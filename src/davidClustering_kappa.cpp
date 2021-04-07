#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::plugins("cpp11")]]

typedef std::vector<int> IntVec;
typedef std::list< std::vector<int> > IntList;

IntList dc_kappaRowSeeds(NumericMatrix kappaMatrix,
                         double kappaThr = 0.35,
                         unsigned initialGroupMembership = 3) {
   int anrow = kappaMatrix.nrow();
   int ancol = kappaMatrix.ncol();
   if(anrow != ancol) {
     Rcpp::stop("The input matrix must be a square matrix, i.e. row numbers must equal to column numbers");
   }

   IntList seeds;
   for(int i=0; i<anrow; i++) {
     IntVec currSeeds;
     for(int j=0; j<ancol; j++)  {
       if(kappaMatrix(i, j) >= kappaThr and i!=j) {
         currSeeds.push_back(j);
        }
     }
     if(currSeeds.size() >= initialGroupMembership-1) {
      if(currSeeds.size() == 1) {
         currSeeds.push_back(i);
         seeds.push_back(currSeeds);
       }  else {
         int overThrKappaCnt = 0;
         for(IntVec::iterator it=currSeeds.begin(); it!=currSeeds.end(); ++it) {
           for(IntVec::iterator jt=it+1; jt!=currSeeds.end(); ++jt) {
              if(kappaMatrix(*it, *jt) >= kappaThr) {
                  overThrKappaCnt++;
              }
           }
         }
         int totalKappa = (currSeeds.size()*(currSeeds.size()-1))/2;
         if (overThrKappaCnt >= totalKappa * 0.5) {
           currSeeds.push_back(i);
           seeds.push_back(currSeeds);
         }
       }
      }
   }
   return(seeds);
}

void dc_uniqueSeeds(IntList &seeds) {
  for(IntList::iterator it=seeds.begin(); it!=seeds.end(); ++it) {
    std::sort(it->begin(), it->end());
    std::transform(it->begin(), it-> end(),
                   it->begin(), std::bind2nd( std::plus<int>(), 1 ) );
  }
  seeds.sort();
  seeds.erase( std::unique( seeds.begin(), seeds.end() ), seeds.end() );
}

void dc_mergeSeeds(IntList &seeds,
                   double multiLinkageThr=0.5,
                   int mergeRule=1) {
  int lastSeedCount;
  int newSeedCount = -1;
  while(newSeedCount<0 || newSeedCount != lastSeedCount) {
    lastSeedCount = seeds.size();
    bool changed = FALSE;
    for(std::list< std::vector<int> >::iterator it=seeds.begin(); it!=seeds.end(); ++it) {
     for(std::list< std::vector<int> >::iterator jt=it; jt!=seeds.end(); ++jt) {
       if(jt==it) {
         continue;
       }
       IntVec seedi = *it;
       IntVec seedj = *jt;
       IntVec intersect;
       IntVec ijunion;
       std::set_intersection(seedi.begin(),seedi.end(),
                             seedj.begin(),seedj.end(),
                             std::back_inserter(intersect));
       std::set_union(seedi.begin(),seedi.end(),
                      seedj.begin(),seedj.end(),
                      std::back_inserter(ijunion));
       int ninter = intersect.size();
       bool toMerge = FALSE;
       if(mergeRule==1) {
         toMerge = ninter >= multiLinkageThr * seedi.size() || ninter >= multiLinkageThr * seedj.size(); // OR Rule, default
       } else if (mergeRule==2) {
         toMerge = ninter >= multiLinkageThr * seedi.size() && ninter >= multiLinkageThr * seedj.size(); // AND Rule
       } else if (mergeRule==3) {
          toMerge = ninter >= multiLinkageThr * ijunion.size(); // Union Rule
       } else if (mergeRule==4) {
          toMerge = ninter * ninter / (seedi.size() * seedj.size()) >= multiLinkageThr * multiLinkageThr; // GMEAN - too liberal
       } else if (mergeRule==5) {
         toMerge = ((ninter / seedi.size()) + (ninter / seedj.size()))/2.0 >= multiLinkageThr; // AMEAN
       } else {
          Rcpp::stop("should not be here");
       }
       if(toMerge) {
         *it = ijunion;
         seeds.erase(jt);
         changed = TRUE;
         break;
       }
     }
     if(changed) {
       break;
     }
    }
    newSeedCount = seeds.size();
  }
}

//' Cluster rows of a Kappa-statistic-matrix by the hierarhical fuzzy multi-linkage partitioning method proposed by DAVID
//'
//' The function implements the Hierarhical fuzzy multi-linkage partitioning method used in the DAVID Bioinformatics tool.
//'
//' @param kappaMatrix A numeric matrix of Kappa statistics, which is likely returned by \code{\link{rowKappa}} or \code{\link{colKappa}}
//' @param kappaThr Numeric, the threshold of the Kappa statistic, which is used to select initial seeds. Default value: 0.35, as recommended by the authors of the original study based on their experiences.
//' @param initialGroupMembership Non-negative integer, the number of minimal members in initial groups. Default value: 3.
//' @param multiLinkageThr Numeric, the minimal linkage between two groups to be merged. Default value: 0.5.
//' @param mergeRule Integer, how two seeds are merged. See below.
//' 
//' Currently following merge rules are implemented:
//' \itemize{
//' \item{1 (OR RULE) length of intersect divided by length of \emph{either} seeds no less than \code{multiLinkageThr}. Empirical evidence suggests that it is a bit coarse grain than the native DAVID clustering algorithm, but the performance is quite good judged by biological relevance.}
//' \item{2 (AND RULE) length of intersect divided by length of \emph{both} seeds no less than \code{multiLinkageThr}, which gives slightly fragmented cluster by empirical experieince}
//' \item{3 (UNION RULE) length of intersect divided by length of the union no less than \code{multiLinkageThr}, which performs similar to the \emph{AND RULE} above.}
//' \item{4 (GMEAN RULE) Geometric mean of length of intersect divided by length of \emph{both} seeds no less than \code{multiLinkageThr}, the clusters tend to be highly fragemented.}
//' \item{5 (AMEAN RULE) Arithmetic mean of length of intersect divided by length of \emph{both} seeds no less than \code{multiLinkageThr}, a few items tend to appear in multiple clusters.}
//' }
//' 
//' @author Jitao David Zhang <jitao_david.zhang@roche.com>
//'
//' @note
//' The function has only been tested in a few anecdotal examples. Cautions and more systematic tests are required before it is applied to critical datasets.
//'
//' @references
//' \itemize{
//' \item{Huang *et al.* The DAVID Gene Functional Classification Tool: a novel biological module-centric algorithm to functionally analyze large gene lists. Genome Biology, 2007}
//' \item{Additional file of the manuscript available at \url{https://david.ncifcrf.gov/helps/2D_Introduction_files/additional_file_13.doc}}
//' }
//'
//' @examples 
//' synData <- matrix(c(rep(c(rep(1, 10), rep(0, 5)), 3),
//' rep(0, 4), rep(1, 7), rep(0,4),
//' rep(c(rep(0,5), rep(1,10)), 3),
//' rep(c(rep(0,3), 1), 4)[-16]), ncol=15, byrow=TRUE)
//' rownames(synData) <- sprintf("Gene %s", letters[1:8])
//' colnames(synData) <- sprintf("t%d", 1:15)
//' synKappaMat <- rowKappa(synData)
//' synKappaMat.round2 <- round(synKappaMat, 2)
//' davidClustering_kappa(synKappaMat.round2)
//' 
//' @export
// [[Rcpp::export]]
Rcpp::List davidClustering_kappa(Rcpp::NumericMatrix kappaMatrix,
                                double kappaThr = 0.35,
                                unsigned initialGroupMembership = 3,
                                double multiLinkageThr=0.5,
                                int mergeRule=1) {
  IntList seeds = dc_kappaRowSeeds(kappaMatrix,
                                   kappaThr,
                                   initialGroupMembership);
  dc_uniqueSeeds(seeds);
  dc_mergeSeeds(seeds,
                multiLinkageThr,
                mergeRule);
  return(Rcpp::wrap(seeds));
}
// You can include R code blocks in C++ files processed with sourceCpp
// (useful for testing and development). The R code will be automatically 
// run after the compilation.
//

/*** R
synData <- matrix(c(rep(c(rep(1, 10), rep(0, 5)), 3),
                    rep(0, 4), rep(1, 7), rep(0,4),
                    rep(c(rep(0,5), rep(1,10)), 3),
                    rep(c(rep(0,3), 1), 4)[-16]), ncol=15, byrow=TRUE)
rownames(synData) <- sprintf("Gene %s", letters[1:8])
colnames(synData) <- sprintf("t%d", 1:15)
synKappaMat <- rowKappa(synData)
synKappaMat.round2 <- round(synKappaMat, 2)
davidClustering_kappa(synKappaMat.round2, kappaThr=0.35)
*/

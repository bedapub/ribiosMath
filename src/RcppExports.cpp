// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <RcppArmadillo.h>
#include <Rcpp.h>

using namespace Rcpp;

#ifdef RCPP_USE_GLOBAL_ROSTREAM
Rcpp::Rostream<true>&  Rcpp::Rcout = Rcpp::Rcpp_cout_get();
Rcpp::Rostream<false>& Rcpp::Rcerr = Rcpp::Rcpp_cerr_get();
#endif

// cossimVec
RcppExport SEXP cossimVec(SEXP x, SEXP y, SEXP narm);
RcppExport SEXP _ribiosMath_cossimVec(SEXP xSEXP, SEXP ySEXP, SEXP narmSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< SEXP >::type x(xSEXP);
    Rcpp::traits::input_parameter< SEXP >::type y(ySEXP);
    Rcpp::traits::input_parameter< SEXP >::type narm(narmSEXP);
    rcpp_result_gen = Rcpp::wrap(cossimVec(x, y, narm));
    return rcpp_result_gen;
END_RCPP
}
// davidClustering_kappa
Rcpp::List davidClustering_kappa(Rcpp::NumericMatrix kappaMatrix, double kappaThr, unsigned initialGroupMembership, double multiLinkageThr, int mergeRule);
RcppExport SEXP _ribiosMath_davidClustering_kappa(SEXP kappaMatrixSEXP, SEXP kappaThrSEXP, SEXP initialGroupMembershipSEXP, SEXP multiLinkageThrSEXP, SEXP mergeRuleSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< Rcpp::NumericMatrix >::type kappaMatrix(kappaMatrixSEXP);
    Rcpp::traits::input_parameter< double >::type kappaThr(kappaThrSEXP);
    Rcpp::traits::input_parameter< unsigned >::type initialGroupMembership(initialGroupMembershipSEXP);
    Rcpp::traits::input_parameter< double >::type multiLinkageThr(multiLinkageThrSEXP);
    Rcpp::traits::input_parameter< int >::type mergeRule(mergeRuleSEXP);
    rcpp_result_gen = Rcpp::wrap(davidClustering_kappa(kappaMatrix, kappaThr, initialGroupMembership, multiLinkageThr, mergeRule));
    return rcpp_result_gen;
END_RCPP
}
// empval
RcppExport SEXP empval(SEXP stat, SEXP sim);
RcppExport SEXP _ribiosMath_empval(SEXP statSEXP, SEXP simSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< SEXP >::type stat(statSEXP);
    Rcpp::traits::input_parameter< SEXP >::type sim(simSEXP);
    rcpp_result_gen = Rcpp::wrap(empval(stat, sim));
    return rcpp_result_gen;
END_RCPP
}
// colKappa
RcppExport SEXP colKappa(Rcpp::NumericMatrix matrix, int minOverlap);
RcppExport SEXP _ribiosMath_colKappa(SEXP matrixSEXP, SEXP minOverlapSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< Rcpp::NumericMatrix >::type matrix(matrixSEXP);
    Rcpp::traits::input_parameter< int >::type minOverlap(minOverlapSEXP);
    rcpp_result_gen = Rcpp::wrap(colKappa(matrix, minOverlap));
    return rcpp_result_gen;
END_RCPP
}
// colKappaSimp
RcppExport SEXP colKappaSimp(SEXP Xs, int minOverlap);
RcppExport SEXP _ribiosMath_colKappaSimp(SEXP XsSEXP, SEXP minOverlapSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< SEXP >::type Xs(XsSEXP);
    Rcpp::traits::input_parameter< int >::type minOverlap(minOverlapSEXP);
    rcpp_result_gen = Rcpp::wrap(colKappaSimp(Xs, minOverlap));
    return rcpp_result_gen;
END_RCPP
}
// rowKappa
RcppExport SEXP rowKappa(Rcpp::NumericMatrix matrix, int minOverlap);
RcppExport SEXP _ribiosMath_rowKappa(SEXP matrixSEXP, SEXP minOverlapSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< Rcpp::NumericMatrix >::type matrix(matrixSEXP);
    Rcpp::traits::input_parameter< int >::type minOverlap(minOverlapSEXP);
    rcpp_result_gen = Rcpp::wrap(rowKappa(matrix, minOverlap));
    return rcpp_result_gen;
END_RCPP
}

static const R_CallMethodDef CallEntries[] = {
    {"_ribiosMath_cossimVec", (DL_FUNC) &_ribiosMath_cossimVec, 3},
    {"_ribiosMath_davidClustering_kappa", (DL_FUNC) &_ribiosMath_davidClustering_kappa, 5},
    {"_ribiosMath_empval", (DL_FUNC) &_ribiosMath_empval, 2},
    {"_ribiosMath_colKappa", (DL_FUNC) &_ribiosMath_colKappa, 2},
    {"_ribiosMath_colKappaSimp", (DL_FUNC) &_ribiosMath_colKappaSimp, 2},
    {"_ribiosMath_rowKappa", (DL_FUNC) &_ribiosMath_rowKappa, 2},
    {NULL, NULL, 0}
};

RcppExport void R_init_ribiosMath(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}

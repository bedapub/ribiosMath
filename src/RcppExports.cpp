// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <RcppArmadillo.h>
#include <Rcpp.h>

using namespace Rcpp;

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
RcppExport SEXP colKappa(SEXP matrix);
RcppExport SEXP _ribiosMath_colKappa(SEXP matrixSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< SEXP >::type matrix(matrixSEXP);
    rcpp_result_gen = Rcpp::wrap(colKappa(matrix));
    return rcpp_result_gen;
END_RCPP
}
// colKappaSimp
RcppExport SEXP colKappaSimp(SEXP Xs);
RcppExport SEXP _ribiosMath_colKappaSimp(SEXP XsSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< SEXP >::type Xs(XsSEXP);
    rcpp_result_gen = Rcpp::wrap(colKappaSimp(Xs));
    return rcpp_result_gen;
END_RCPP
}
// davidClustering_cpp
Rcpp::List davidClustering_cpp(Rcpp::NumericMatrix kappaMatrix, double kappaThr, int initialGroupMembership);
RcppExport SEXP _ribiosMath_davidClustering_cpp(SEXP kappaMatrixSEXP, SEXP kappaThrSEXP, SEXP initialGroupMembershipSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< Rcpp::NumericMatrix >::type kappaMatrix(kappaMatrixSEXP);
    Rcpp::traits::input_parameter< double >::type kappaThr(kappaThrSEXP);
    Rcpp::traits::input_parameter< int >::type initialGroupMembership(initialGroupMembershipSEXP);
    rcpp_result_gen = Rcpp::wrap(davidClustering_cpp(kappaMatrix, kappaThr, initialGroupMembership));
    return rcpp_result_gen;
END_RCPP
}
// randmat
RcppExport SEXP randmat(SEXP vec, SEXP size, SEXP N);
RcppExport SEXP _ribiosMath_randmat(SEXP vecSEXP, SEXP sizeSEXP, SEXP NSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< SEXP >::type vec(vecSEXP);
    Rcpp::traits::input_parameter< SEXP >::type size(sizeSEXP);
    Rcpp::traits::input_parameter< SEXP >::type N(NSEXP);
    rcpp_result_gen = Rcpp::wrap(randmat(vec, size, N));
    return rcpp_result_gen;
END_RCPP
}

static const R_CallMethodDef CallEntries[] = {
    {"_ribiosMath_cossimVec", (DL_FUNC) &_ribiosMath_cossimVec, 3},
    {"_ribiosMath_empval", (DL_FUNC) &_ribiosMath_empval, 2},
    {"_ribiosMath_colKappa", (DL_FUNC) &_ribiosMath_colKappa, 1},
    {"_ribiosMath_colKappaSimp", (DL_FUNC) &_ribiosMath_colKappaSimp, 1},
    {"_ribiosMath_davidClustering_cpp", (DL_FUNC) &_ribiosMath_davidClustering_cpp, 3},
    {"_ribiosMath_randmat", (DL_FUNC) &_ribiosMath_randmat, 3},
    {NULL, NULL, 0}
};

RcppExport void R_init_ribiosMath(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}

// This file was generated by Rcpp::compileAttributes
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <Rcpp.h>

using namespace Rcpp;

// test
double test(double min = 0.0, double max = 1.0);
RcppExport SEXP bbhw6_test(SEXP minSEXP, SEXP maxSEXP) {
BEGIN_RCPP
    SEXP __sexp_result;
    {
        Rcpp::RNGScope __rngScope;
        Rcpp::traits::input_parameter< double >::type min(minSEXP );
        Rcpp::traits::input_parameter< double >::type max(maxSEXP );
        double __result = test(min, max);
        PROTECT(__sexp_result = Rcpp::wrap(__result));
    }
    UNPROTECT(1);
    return __sexp_result;
END_RCPP
}

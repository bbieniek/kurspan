#include <Rcpp.h>
using namespace Rcpp;

//' @title ...
//' @description ...
//'
//' @param min ...
//' @param max ....
//' @return ....
//'
//' @export
// [[Rcpp::export]]
double test(double min =0.0, double max =1.0) {
return Rf_runif ( min , max );
}

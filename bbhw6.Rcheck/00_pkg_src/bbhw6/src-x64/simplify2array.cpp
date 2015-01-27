#include <Rcpp.h>
using namespace Rcpp;



//' @title simplify2array
//' @description The function simplifies a list of numeric vectors into a numeric vector
//'
//' @param x List - expecting a list of numeric vectors
//' @return NumericVector - a list of numeric vectors
//'
//' @export
// [[Rcpp::export]]
NumericVector simplify2array(List x) {
   int totalLength = 0;
   
   for (int i=0; i<x.size(); i++)
   {
     if (Rf_isNumeric(x[i]))
     {
       NumericVector temp(x[i]);
       totalLength += temp.size();
     }
   }
   
   NumericVector ret(totalLength);
   
   int currentIndex = 0;
   
   for (int i=0; i<x.size(); i++)
   {
     if (Rf_isNumeric(x[i]))
     {
       NumericVector temp(x[i]);
       for (int j=0; j<temp.size(); j++)
       {
         ret[currentIndex++] = temp[j];
       }
       
     }
   }
   
   return ret;
}

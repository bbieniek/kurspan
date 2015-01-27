#include <Rcpp.h>
#include <algorithm>    // std::next_permutation, std::sort
#include <iostream>

using namespace Rcpp;


unsigned long factorial(int x)
{
  unsigned long result = 1;
  for (unsigned long i = x; i>=1; i--)
  {
    result = result * i;
  }
  return result;
}

//' @title perms
//' @description The function generates all possible combinations of a given vector
//'
//' @param x input vector
//' @return Matrix - the matrix that represents all possible permutations
//'
//' @export
// [[Rcpp::export]]
NumericMatrix perms(IntegerVector x) {
   int size = x.size();
   int* inputVector = clone(x).begin();
   
   int numberOfRows = factorial(size);
   
   NumericMatrix ret(numberOfRows, size);
   for(int j = 0; j < numberOfRows; j++)
   {
     std::next_permutation(inputVector, inputVector+size);   
   
     for (int i = 0; i < size; i++)
     {
       ret(j, i) = inputVector[i];
     }
     
   }
   
   return ret;
}

#include <Rcpp.h>
#include <set>

using namespace Rcpp;


//' @title mode
//' @description The function calculates a mode of a given integer vector
//'
//' @param x IntegerVector
//' @return Integer value - mode of a vector
//'
//' @export
// [[Rcpp::export]]
int mode(IntegerVector x) {
   int occurences = 0;
   int maxOccurences = 0;
   
   if (x.size() > 0)
   {
     std::set<int> unique;
     for (const auto& e : x)
     {
       unique.insert(e);
     }
     
     IntegerVector counts(unique.size());
     
     int i = 0;
     
     for (const auto& item : unique)
     {
       counts[i++] = item;
     }
     
     int mode = x[0];
     for (i =0; i<  counts.size(); i++)
     {
        occurences = 0;
        for (int j = 0; j< x.size(); j++)
        {
          if (counts[i] == x[j])
          {
            occurences++;
          }
        }
        if (occurences > maxOccurences)
        {
          maxOccurences = occurences;
          mode = counts[i];
        }
     }
     
     return mode;
   }
   else
   {
     return NA_INTEGER;
   }
}

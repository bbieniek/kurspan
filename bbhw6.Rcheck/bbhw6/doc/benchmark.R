## ----,echo=FALSE---------------------------------------------------------
library(microbenchmark)
library(bbhw6)

## ----,cache=TRUE---------------------------------------------------------
modeR <- function(x) {
  as.numeric(names(table(x))[which.max(table(x))]) 
}

## ----,cache=TRUE---------------------------------------------------------

x<-sample(1:100, replace=TRUE, 100000)
microbenchmark::microbenchmark(bbhw6::mode(x), modeR(x))
x<-sample(1:1000, replace=TRUE, 100000)
microbenchmark::microbenchmark(bbhw6::mode(x), modeR(x))

## ----,cache=TRUE---------------------------------------------------------

x<-replicate(1000, sample(1:100,size=10), simplify=FALSE)
microbenchmark::microbenchmark(bbhw6::simplify2array(x), unlist(x))
x<-replicate(10000, sample(1:100,size=100), simplify=FALSE)
microbenchmark::microbenchmark(bbhw6::simplify2array(x), unlist(x))

## ----,cache=TRUE---------------------------------------------------------
permutations <- function(n){
    if(n==1){
        return(matrix(1))
    } else {
        sp <- permutations(n-1)
        p <- nrow(sp)
        A <- matrix(nrow=n*p,ncol=n)
        for(i in 1:n){
            A[(i-1)*p+1:p,] <- cbind(i,sp+(sp>=i))
        }
        return(A)
    }
}

overallPermutation <- function(x){
  matrix(x[permutations(length(x))], ncol = length(x))
}


## ----,cache=TRUE---------------------------------------------------------

x<-replicate(100, sample(1:100,size=5), simplify=FALSE)
microbenchmark::microbenchmark(lapply(x, bbhw6::perms), lapply(x,overallPermutation))
x<-replicate(100, sample(1:100,size=6), simplify=FALSE)
microbenchmark::microbenchmark(lapply(x, bbhw6::perms), lapply(x,overallPermutation))


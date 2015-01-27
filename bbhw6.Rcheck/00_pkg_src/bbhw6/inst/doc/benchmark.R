## ----,cache=TRUE---------------------------------------------------------
require(microbenchmark)
x<-sample(1:100, replace=TRUE, 100000)
microbenchmark(bbhw6::mode(x), modeR(x))
x<-sample(1:1000, replace=TRUE, 100000)
microbenchmark(bbhw6::mode(x), modeR(x))

## ----,cache=TRUE---------------------------------------------------------
require(microbenchmark)
x<-replicate(1000, sample(1:100,size=10), simplify=FALSE)
microbenchmark(bbhw6::simplify2array(x), unlist(x))
x<-replicate(10000, sample(1:100,size=100), simplify=FALSE)
microbenchmark(bbhw6::simplify2array(x), unlist(x))


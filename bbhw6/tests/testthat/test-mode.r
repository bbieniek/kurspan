x <- c(1,2,3)
modeR <- function(x) {
  as.numeric(names(table(x))[which.max(table(x))]) 
}

expect_equal(mode(x), modeR(x))
x<- c(1,2,3,3,3)
expect_equal(mode(x), modeR(x))
x<- c(1,2,3,3,4,3,4,4)
expect_equal(mode(x), modeR(x))
x<- c(1,2,3,3,3,5,5,5)
expect_equal(mode(x), modeR(x))
x<- c(1,2,3,3,3, -1, -2,-3)
expect_equal(mode(x), modeR(x))
x<- c(9,8,7, 32767)
expect_equal(mode(x), modeR(x))
x<- c(1,2,2,3)
expect_equal(mode(x), modeR(x))
x<- c(2,3,2,-2,-3)
expect_equal(mode(x), modeR(x))
x<- c(3,3,2,2)
expect_equal(mode(x), modeR(x))
x<- c(1,2,3,3)
expect_equal(mode(x), modeR(x))
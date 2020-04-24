mat <- function() {
  B <- matrix(nrow = 3, ncol = 3)
  B[1,] <- c(1, 2, 3)
  B[2,] <- c(4, 2, 6)
  B[3,] <- c(-3, -1, -3)

  product <- B%*%B%*%B
  print(paste("Scalar value: ",product[1,1]), quote = FALSE)
}
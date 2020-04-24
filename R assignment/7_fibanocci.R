fibanocci <- function (no_of_terms=10){
  a <- 21
  b <- 31
  print("The fibanocci series using 21 and 31 are: ", quote = FALSE)
  for (i in 1:no_of_terms){
    c <- a + b
    print(c, quote = FALSE)
    a <- b
    b <- c
  }
}
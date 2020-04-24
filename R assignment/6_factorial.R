factorial <- function(num){
  f <- 1
  for (i in 2:num){
    f <- f*i
  }
  print(paste("Factorial of ", num, " is ",f),quote = FALSE)
}
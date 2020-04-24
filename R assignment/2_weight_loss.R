weight_loss <- function (){
  before <- c(78,72,78,79,105)
  after <- c(67,65,79,70,93)

  weight_loss <- before - after
  avg_weight_loss <- mean(weight_loss)
  print("The corresponding weightlosses are: ",quote = FALSE)
  print(weight_loss)
  print(paste("Average weighloss: ", avg_weight_loss),quote = FALSE)
}
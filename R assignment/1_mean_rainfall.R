mean_rainfall <- function (){

  rain_amount <- c(0.1, 0.6, 33.8, 1.9, 9.6, 4.3, 33.7, 0.3, 0.0, 0.1)
  cumilative <- cumsum(rain_amount)

  print(paste("Mean rainfall: ",mean(rain_amount)),quote = FALSE)
  print(paste("Cumilative rainfall: ",cumilative[length(cumilative)]),quote = FALSE)

}
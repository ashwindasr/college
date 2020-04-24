leap_year <- function() {
  l <- list()
  print("The leap years between the two years are:",quote = FALSE)
  for (i in 1800:2020) {
    if (i %% 4 == 0) {
      if (i %% 100 == 0) {
        if (i %% 400 == 0) {
          l <- c(l,i)
        }
      }else {
        l <- c(l,i)
      }
    }
  }
  print(l)
}
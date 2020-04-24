students <- function (){
  details <- c('IT', "S8", "Abilash")
  subs <- matrix(c("Subject 1","Faculty 1","Subject 2","Faculty 2"), nrow = 2, ncol = 2)
  students <- c("Ashwin Das","Ashwin Titus","Navneeth K","Deepu","Sreenath")

  all <- list(details,subs,students)
  all[[3]][[6]] = "Thomas"
  all[[3]][[7]] = "John"

  all
}
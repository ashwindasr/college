films <- function (){
  title <- c('Film 3', 'Film 1', 'Film 2')
  director <- c('John Doe','Peter Gynn','Jolie Hope')
  year <- c('2010','2008','2007')
  country <- c('India', 'USA', 'China')

  films <- data.frame(title, director, year, country)

  new_film <- data.frame(title='Film 4', director='George Thomas',year='2020', country='Japan')
  films <- rbind(films,new_film)
  print(films[order(films$title),])
}
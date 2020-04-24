matrix_mul <- function(){
  A <- matrix(c(1,5,3,8), ncol=2, nrow=2)
  b <- c(2,4)
  Ab <-matrix(0 , dim(A)[1] , dim(A)[2] , TRUE )
  for ( i in 1:dim(A)[1] ) {
     for ( j in 1:length(b) ) {
        Ab[i,j] = A[i,j] * b[j]
     }
   }
  print(Ab)
}
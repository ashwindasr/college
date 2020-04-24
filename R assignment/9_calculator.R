calculator <- function(operand1, operator, operand2) {
  if (operator == '+') {
    return(operand1 + operand2)
  }
  else if (operator == '-') {
    return(operand1 - operand2)
  }else if (operator == 'x') {
    return(operand1 * operand2)
  }else if (operator == '/') {
    return(operand1 / operand2)
  }else {
    return("Invalid Oprator")
  }
}
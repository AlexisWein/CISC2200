The purpose of this project was to implement a class that can store integers of unlimited size (BigInt.h and BigInt.cpp) and a class that can perform operations on the Big Integers (calculator.cpp).
In the BigInt class, I used lists to store the integers and wrote overloaded functions for addition, subtraction, and multiplication, as well as an isLessThan function, which is called in other functions. 
In calculator.cpp, I implemented the infixToPostfix and evaluatePostfix functions. 
The infixToPostfix function takes an expression in infix notation and converts it to postfix notation (Reverse Polish Notation). 
The evaluatePostfix function evaluates the expression and returns the result as a BigInt.

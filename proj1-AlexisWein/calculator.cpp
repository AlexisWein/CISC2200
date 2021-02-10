#include "BigInt.h"
#include <stack>
#include <string>

using std::stack;
using std::string;

std::string infixToPostfix(const std::string &infix) {
  // TODO: transform an `infix` expression to a `postifx` expression
  stack<char> opStack;
  string postFixString = "";
  char currOp;

  //Loop through the array (one character at a time) until we reach the end of the string.
    for (long unsigned int i = 0; i < infix.length(); i++)
    {
      //cout << "infix at " << i << ": " << infix.at(i) << endl;          //debugging statement
      if(isdigit(infix.at(i))  ||  isspace(infix.at(i)))
      {
        postFixString += infix.at(i);
        //cout << "Test first if" << endl;                                //debugging statement
      }
      else if(infix.at(i) == '+'  ||  infix.at(i) == '-'  ||  infix.at(i) == '*')
      {
        //cout << "Test second if" << endl;                               //debugging statement
        currOp = infix.at(i);
        //cout << "currOp test: " << currOp << endl;                      //debugging statement
        
        while (!opStack.empty()  &&  opStack.top() != '(' &&  !(currOp == '*'  &&  opStack.top() != '*'))
        {
          //cout << "Top: " << opStack.top() << endl;                     //debugging statement
          postFixString += opStack.top();       //append the top operator from stack to postFixString
          //cout << "postFixString: " << postFixString << endl;           //debugging statement
          opStack.pop();
        }
        opStack.push(currOp);
      }
      else if(infix.at(i) == '(')
      {
        //cout << "Test third if" << endl;                                 //debugging statement
        opStack.push('(');
      }
      else if(infix.at(i) == ')')
      {
        //cout << "Test fourth if" << endl;                                //debugging statement
        
        //When we reach a closing one, start popping off operators
        //until we run into an opening parenthesis.
        while (!opStack.empty())
        {
          if (opStack.top() == '(')
          {
            opStack.pop();
            break;
          }
          else
          {
            postFixString += opStack.top();
            opStack.pop();
          }
        }
      }
    }
    while(!opStack.empty()  &&  (opStack.top() == '+'  ||  opStack.top() == '-'  ||  opStack.top() == '*'))
    {
      //cout << "Top: " << opStack.top() << endl;                           //debugging statement
      postFixString += opStack.top();
      opStack.pop();
    }
    //cout << "Test: " << postFixString << endl;                            //debugging statement

  return postFixString;
}


ds::BigInt evaluatePostfix(const std::string &postfix) {
  // TODO: evaluate and return the value of `postfix` expression
  //Based on the algorithm in the instructions
  stack<ds::BigInt> bigStack;
  for(long unsigned int i = 0; i < postfix.length(); i++)
  {
    if(isspace(postfix.at(i)))
    {
      //cout << "test 1" << endl;                   //debugging statement
      continue;
    }
      string temp = "";
      while(isdigit(postfix.at(i)))
      {
        temp += postfix.at(i);
        i++;
      }
      if(temp.length() > 0)
      {
        //cout << "stack maker test" << endl;                  //debugging statement
        ds::BigInt sub(temp);
        bigStack.push(sub);
        //cout << "temp test: " << temp << endl;               //debugging statement
        //cout << "top test: " << bigStack.top() << endl;      //debugging statement
      }
    
    if(postfix.at(i) == '+'  ||  postfix.at(i) == '-'  ||  postfix.at(i) == '*')
    {
      //cout << "test 2" << endl;                                    //debugging statement
      ds::BigInt elem1 = bigStack.top();
      bigStack.pop();
      ds::BigInt elem2 = bigStack.top();
      bigStack.pop();
      //cout <<  "elem1: " << elem1 << endl;                         //debugging statement
      //cout << "elem2: " << elem2 << endl;                          //debugging statement
      if(postfix.at(i) == '+')
        bigStack.push(elem1 + elem2);
      else if(postfix.at(i) == '-')
        bigStack.push(elem1 - elem2);
      else if(postfix.at(i) == '*')
        bigStack.push(elem1 * elem2);
    }
  }
  //cout << "test" << endl;                                          //debugging statement
  return bigStack.top();
}

#include "LStack.h"
#include <stack>
#include <string>
#include <iostream>

using std::string;
using std::stack;

bool isValid(const string &s) {
  // TODO: determine if the input string `s` is valid
  stack<char> cStack;                                                    //declares a stack of chars

  for(int i = 0; i < s.length(); i++)                                    //iterates through all the characters in the string
  {
    if (s.at(i) == '('  ||  s.at(i) == '{'  || s.at(i) == '[')           //pushes opening symbols to the stack
      cStack.push(s.at(i));
    else if(s.at(i) == ')'  ||  s.at(i) == '}'  || s.at(i) == ']')       //checks if closing symbols have a matching opening symbol on the top of the stack
    {
      if(cStack.empty())
        return false;
      else if(s.at(i) == ')'  &&  cStack.top() == '(')
        cStack.pop();
      else if(s.at(i) == '}'  &&  cStack.top() == '{')
        cStack.pop();
      else if(s.at(i) == ']'  &&  cStack.top() == '[')
        cStack.pop();
      else
        return false;
    }
  }
  if(!cStack.empty())                                                     //returns false if the stack is not empty after running the for loop
      return false;
  
  return true;                                                            //returns true as a default; the code will never have to use this
  
}

string decodeString(const string &s) {
  // TODO: decode given string `s`
  stack<string> strStack;                         //stores intermediate results (decoded substrings)
  stack<int> intStack;                            //stores ks
  strStack.push("");                              //pushes an empty string to the stack
  

  for(int i = 0; i < s.length(); i++)
  {
    if(isdigit(s.at(i)))
    {
      int foundPos = s.find('[', i);                  //find position of '['
      int tempLen = foundPos - i;                     //find length of k
      int temp = stoi(s.substr(i, tempLen));          //convert the substring k to an integer
      intStack.push(temp);                            //push k to the integer stack
      i = foundPos - 1;                               //set i to its new value
    }
    else if(s.at(i) == '[')
    {
      strStack.push("");
    }
    else if(s.at(i) == ']')
    {
      //decodes the string
      string decStr = "";
      for(int i = 0; i < intStack.top(); i++)
      {
        decStr += strStack.top();
        //std::cout << "decStr Test: " << decStr << "\n";           //debugging statement
      }
      strStack.pop();
      intStack.pop();

      //puts the decoded string on the stack
      string tempStr = strStack.top() + decStr;
      strStack.pop();
      strStack.push(tempStr);
    }
    else
    {
      string tempX = strStack.top() + s.at(i);                       //temp variable to store the value of top + s.at(i) before popping
      //std::cout << "tempX test: " << tempX << "\n";                //debugging statement

      strStack.pop();
      strStack.push(tempX);                                          //pushes the temp variable to the stack
    }   
  }
  
  return strStack.top();
}

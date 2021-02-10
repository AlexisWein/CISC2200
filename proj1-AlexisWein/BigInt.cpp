#include "BigInt.h"
#include <iostream>
#include <stack>
#include <vector>
//#include <string>
using std::stack;

namespace ds {

BigInt::BigInt(const std::string &val) {
  // If you use STL: store the big integer `val` in `digits`
  for (size_t j = 0; j < val.size(); j++) {
    digits.append(val[j] - '0');
  }
}

std::ostream &operator<<(std::ostream &os, const BigInt &bi) {
  // If you use STL: put `bi.digits` to `os`
  for (int i = 0; i < bi.digits.length(); i++)
    os << bi.digits.getValueAt(i);
  return os;
}

BigInt BigInt::operator+(const BigInt &other) const {
  // TODO: return the *sum* of this BigInt and the `other` BigInt
  // NOTE: https://en.wikipedia.org/wiki/Addition
  // E.G.: 456 + 1123 = 1579
  stack<int> digStack;                               //stack of digits (holds the sum in backward order)
  int carry = 0;                                     //value to be carried
  int i = digits.length()-1;
  int j = other.digits.length()-1;

  while(i >= 0  ||  j >= 0)                          //keep going until you've reached gone through all the digits of the shortest BigInt
  {
    int tempThis;                                    //temp value to hold this
    int tempOther;                                   //temp value to hold other
    
    if(i >= 0)
      tempThis = digits.getValueAt(i);
    else
      tempThis = 0;
    
    if(j >= 0)
      tempOther = other.digits.getValueAt(j);
    else
      tempOther = 0;

    int sum = tempThis + tempOther + carry;
    
    digStack.push(sum % 10);                          //push the remainder to the stack
    carry = sum / 10;                                 //carry is the integer division of sum and 10 (keeps the 10s value)
    
    i--;                                              //decrement i and j
    j--;
  }
  if(carry > 0)
  {
    digStack.push(carry);                             //push carry to the stack after going doing the addition in the for loop
  }

  BigInt sum("");
  while(!digStack.empty())                            //append the values in the stack to the BigInt object sum
  {                                                   //this works because the stack holds the sum in backward order
    sum.digits.append(digStack.top());
    digStack.pop();
  }
  return sum;
}

BigInt BigInt::operator-(const BigInt &other) const {
  // TODO: return the *absolute difference* between this and the `other` BigInt
  // NOTE: https://en.wikipedia.org/wiki/Absolute_difference
  // E.G.: 456 - 1123 = 667
  if(isLessThan(other))                             //calls function isLessThan (see end of code)
  {
    //cout << isLessThan(other) << endl;            //debugging statement to test the isLessThan function
    return other - *this;
  }
  stack<int> digStack;                              //stack of digits (holds the sum in backward order)
  int carry = 0;                                    //value to be carried
  int i = digits.length()-1;
  int j = other.digits.length()-1;

  while(i >= 0  ||  j >= 0)                         //keep going until you've reached gone through all the digits of the shortest BigInt
  {
    int tempThis;                                   //temp value to hold this
    int tempOther;                                  //temp value to hold other
    if(i >= 0)
      tempThis = digits.getValueAt(i);
    else
      tempThis = 0;

    if(j >= 0)
      tempOther = other.digits.getValueAt(j);
    else
      tempOther = 0;

    int diff = tempThis - tempOther - carry;
    if(diff < 0)
    {
      diff += 10;
      carry = 1;
    }
    else
    {
      carry = 0;
    }
    digStack.push(diff);                            //push diff to the stack
    i--;                                            //decrement i and j
    j--;

  }

  //removes leading 0s from the stack
  while(!digStack.empty())
  {
    if(digStack.top() == 0)
      digStack.pop();
    else
      break;
    
  }

  BigInt adiff("");
  while(!digStack.empty())
  {
    adiff.digits.append(digStack.top());        //appends the top element of digStack to adiff, which works because the answer is in backward order in the stack
    digStack.pop();                             //pops the top element of digStack so the next top element can be appended to adiff
  }
  return adiff;
}

BigInt BigInt::operator*(const BigInt &other) const {
  // TODO: return the *product* of this BigInt and the `other` BigInt
  // NOTE: https://en.wikipedia.org/wiki/Multiplication
  // E.G.: 456 * 1123 = 512088
  
  /* //Pseudocode
  multiply(a[1..p], b[1..q], base)                          // Operands containing rightmost digits at index 1
  product = [1..p+q]                                        // Allocate space for result
  for b_i = 1 to q                                          // for all digits in b
    carry = 0
    for a_i = 1 to p                                        // for all digits in a
      product[a_i + b_i - 1] += carry + a[a_i] * b[b_i]
      carry = product[a_i + b_i - 1] / base
      product[a_i + b_i - 1] = product[a_i + b_i - 1] mod base
    product[b_i + p] = carry                               // last digit comes from final carry
  return product
  */
  
  std::vector<int> product2(digits.length() + other.digits.length());   //vector with some space allocated to avoid a seg fault
  
  int pos1 = 0;                                                         //position 1 (important in the loop)
  int pos2 = 0;                                                         //position 2 (important in the loop)
  
  for(int j = other.digits.length() - 1; j >= 0; j--)                   //nested for loops iterate backward through both BigInts and multiply and add products
  {                                                                     //they use pos1 and pos2 to account for the shift when adding the products
    int carry = 0;
    int n1 = other.digits.getValueAt(j);                                //value to multiply in this iteration of the outer loop
    //cout << "Test 1: " << n1 << endl;                                 //debugging statement
    pos2 = 0;                                                           //sets pos2 back to 0 after each iteration of the inner loop
    for(int i = digits.length() - 1; i >= 0; i--)
    {
      int n2 = digits.getValueAt(i);                                    //value to multiply in this iteration of the outer loop
      //cout << "Test 2: " << n2 << endl;                               //debugging statement
      int sum = n1 * n2 + product2.at(pos1 + pos2) + carry;             //adds the product and the current sum of the products
      carry = sum / 10;
      product2.at(pos1 + pos2) = sum % 10;
      pos2++;

    }
    //cout << "Product2: " << product2.at(j+1) << endl;                 //debugging statement
    if(carry > 0)
      product2.at(pos1 + pos2) += carry;
    pos1++;
  }
  int i = product2.size() - 1;                                          //ignores leading 0s 
    while (i>=0 && product2.at(i) == 0) 
    i--;
  BigInt prod("");
  
  //sets prod equal to 0 if ALL the elements of product2 are all 0
  //(this means either this or other were 0)
  if(i < 0)
  {
    prod.digits.append(0);
  }
  
  //appends the values in the vector to the BigInt object for product
  while(i >= 0)
  {
    prod.digits.append(product2.at(i));
    i--;
  }
  
  /* //Debugging statements
  for(int i = product2.size() - 1; i >= 0; i--)
  {
    cout << "test: " << product2.at(i) << endl;
    prod.digits.append(product2.at(i));
  }
  */
  return prod;
}

bool BigInt::isLessThan(const BigInt &other) const
{
  int thisLength = digits.length();
  int otherLength = other.digits.length();
  //cout << "this test: " << *this << endl;            //debugging statement
  //cout << "other test: " << other << endl;           //debugging statement

  if(thisLength < otherLength)
    return true;
  else if(thisLength > otherLength)
    return false;
  else                                                //covers the case where both BigInts are the same length
  {
    for(int i = 0; i < digits.length(); i++)
    {
      if(digits.getValueAt(i) < other.digits.getValueAt(i))
        return true;
      else
       i = digits.length();                          //breaks the loop
    }
  }

  return false;
}

} // namespace ds

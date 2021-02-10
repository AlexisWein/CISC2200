#include <vector>
#include <algorithm>

using namespace std;

//overloaded function; this one is used for combine
void bt(vector<vector<int> > &res, vector<int> &candidate, int n, unsigned int k) {
  if (k == candidate.size()) {
    res.push_back(vector<int>(candidate));
    return;
  }
  
  //finds the last element of candidate
  int last;
  if(candidate.size() == 0)
    last = 0;
  else
    last = candidate.back();

  //cout << "last: " << last << endl;       //debugging statement
  
int i = 1 + last;                           //1+last element of candidate;
  for (; i <= n; i++) {
    candidate.push_back(i);
    bt(res, candidate, n, k);
    candidate.pop_back();
  }
}

//overloaded function; this one is used for permute
void bt(vector<vector<int> > &res, vector<int> &candidate, unsigned int n) {
  if (candidate.size() == n) {
    res.push_back(vector<int>(candidate));
    return;
  }
  for (unsigned int i = 1; i <= n; i++) {
    if (find(candidate.begin(), candidate.end(), i) != candidate.end())  // I learned how to use std::find from http://www.cplusplus.com/reference/algorithm/find/
      continue;
    candidate.push_back(i);
    bt(res, candidate, n);                    //bug in original (provided) code; I switched candidate and res
    candidate.pop_back();
  }
}

//combine function: returns all possible combinations
vector<vector<int> > combine(int n, int k) {
  // TODO: return all possible combinations of k numbers out of 1..n
  vector<vector<int> > res;
  vector<int> candidate;
  bt(res, candidate, n, k);
  return res;
}

//permute function: returns all possible permutations
vector<vector<int> > permute(int n) {
  // TODO: return all possible permutations of 1..n
  vector<vector<int> > res;
  vector<int> candidate;
  bt(res, candidate, n);
  return res;
}

#include <bits/stdc++.h>
using namespace std;

bool f(int a, int b) {
  return a > b;
}

int main() {
  vector<int> a = {1, 2, 3, 4};
  bool find = binary_search(a.begin(), a.end(), 4);  // Does a binary search, return true if present else false
  cout << find;                                      // output: 1
  find = binary_search(a.begin(), a.end(), 6);
  cout << find;  // Output 0
  a = {2, 4, 2, 4};
  sort(a.begin(), a.end());  // sorts elements in vector output
  a = {2, 3, 11, 14, 100, 100, 100, 123};
  cout << endl;
  //returns element strictly greater than 100 (>)
  auto it = upper_bound(a.begin(), a.end(), 100);
  //returns the first element greater than or equal to 100 (>=)
  auto it2 = lower_bound(a.begin(), a.end(), 100);
  cout << it - a.begin() << " " << it2 - a.begin() << endl;
  cout << it - it2;

  sort(a.begin(), a.end(), f);

  cout << endl;
  for (int x : a) {
    // x++ () Doesn't update the vector since get by value not reference
    cout << x << " ";
  }
  cout << endl;

  // For reference of x to change the array values
  for (int& x : a) {
    x++;
    cout << x << " ";
  }
  cout << endl;

  for (int x : a) {
    cout << x << " ";
  }
}

#include <bits/stdc++.h>
using namespace std;

int main() {
  set<int> s = {1, 2, 3, 4};
  s.insert(3);
  for (int x : s)
    cout << x << ' ';
  cout << endl;
  auto it = s.find(1);
  if (it == s.end()) {
    cout << "Not present\n";
  } else {
    cout << "present\n";
    cout << *it << endl;
  }
  auto it2 = s.upper_bound(-1);
}
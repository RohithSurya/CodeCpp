#include <bits/stdc++.h>
using namespace std;

int main() {
  map<int, int> a;
  a[1] = 100;
  map<char, int> cnt;
  string s = "rachit jain";
  for (auto c : s) {
    cnt[c]++;
  }
  cout << cnt['f'];
  cout << s.find('a');
}
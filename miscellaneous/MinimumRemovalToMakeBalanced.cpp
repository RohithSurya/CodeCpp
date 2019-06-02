/**
 * @author: Podugu Rohith Surya
 * @link: No Link
 * @desc: Given a string, remove the minimum no of brackets to make it balanced;
 * Input: String with '(',')', alphabets numbers;
 * Output: Strings with minimum no of brackets removed;
 **/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

map<string, bool> visited;
vector<string> ans;

bool balanced(string s) {
  int count = 0;
  for (char c : s) {
    if (c == '(')
      count++;
    else if (c == ')')
      count--;
    if (count < 0) return false;
  }
  return count == 0;
}

void minimumlengthstrings(string s) {
  queue<pair<string, int>> Q;
  int length;
  string t;
  Q.push({s, 0});
  int expectedLength = -1;
  while (!Q.empty()) {
    auto pa = Q.front();
    Q.pop();
    length = pa.second;
    t = pa.first;
    if (visited[t]) continue;
    visited[t] = 1;
    if (expectedLength == -1) {
      if (balanced(t)) {
        ans.push_back(t);
        expectedLength = length;
      }
      for (int i = 0; i < t.length(); i++) {
        if (t[i] == ')' || t[i] == '(')
          Q.push({t.substr(0, i) + t.substr(i + 1, t.length()), length + 1});
      }
    } else if (expectedLength == length) {
      if (balanced(t)) ans.push_back(t);
    } else
      return;
  }
}

int main() {
  string s;
  cin >> s;
  minimumlengthstrings(s);
  for (string t : ans) {
    cout << t << endl;
  }
}

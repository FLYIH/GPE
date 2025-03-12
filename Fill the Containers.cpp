#include <bits/stdc++.h>
using namespace std;
bool check(vector<int> &a, int c, int target) {
  int cnt = 0;
  int sum = 0;
  for(int i = 0 ; i < a.size() ; i++) {
    if(a[i] > target) {
      return false;
    }
    if(sum + a[i] > target) {
      cnt++;
      sum = a[i];
      if(a[i] > target) {
        return false;
      }
    } else {
      sum += a[i];
    }
  }
  return (cnt <= c - 1);
}
int main() {
  
  int v, c;
  while(cin >> v >> c) {
    vector<int> a(v);
    for(int i = 0 ; i < v ; i++) {
      cin >> a[i];
    }

    int l = 1, r = 1e9 + 1;

    while(l < r) {
      int m = l + (r - l) / 2;
      if(check(a, c, m)) {
        r = m;
      } else {
        l = m + 1;
      }
    }
    cout << l << endl;
  }
  return 0;
}
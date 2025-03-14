#include <bits/stdc++.h>
using namespace std;

int main() {
  while(1) {
    int n;
    cin >> n;
    if(!n) break;
    bool found = false;
    vector<int> a(n);
    for(int i = 0 ; i < n ; i++) {
      cin >> a[i];
    }
    unordered_map<int, vector<pair<int, int>>> sum;
    unordered_map<int, vector<pair<int, int>>> diff;
    for(int i = 0 ; i < n ; i++) {
      for(int j =  i + 1 ; j < n ; j++) {
        sum[a[i] + a[j]].push_back({a[i], a[j]});
      }
    }
    for(int i = 0 ; i < n ; i++) {
      for(int j =  i + 1 ; j < n ; j++) {
        diff[a[i] - a[j]].push_back({a[i], a[j]});
        diff[a[j] - a[i]].push_back({a[j], a[i]});
      }
    }
    int ans = -1;
    for(auto& [key, value] : sum) {
      if(diff.find(key) != diff.end()) {
        for(auto& [a, b] : value) {
          for(auto& [d, c] : diff[key]) {
            if(a != d && a != c && a != b && b != d && b != c && d != c) {
              ans = max(ans, d);
              found = true;
            }
          }
        }
      }
    }
    if(!found) cout << "no solution" << endl;
    else cout << ans << endl;
  }
  
  return 0;
}
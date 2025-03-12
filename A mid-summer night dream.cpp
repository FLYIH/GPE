#include <bits/stdc++.h>
using namespace std;

int main() {
  // the minimum
  // how many input 
  // the number of a
  int n;
  while(cin >> n) {
    vector<int> a(n);
    unordered_map<int, int> hash;
    for(int i = 0 ; i < n ; i++) {
      cin >> a[i];
      hash[a[i]]++;
    }
    if(n == 1) {
      cout << a[0] << " " << 1 << " " << 1 << endl;
      continue;
    }
    sort(a.begin(), a.end());
    int a1, a2, a3;

    if(n % 2 == 0) {
      a1 = a[n / 2 - 1];
      
      if(a[n / 2] == a[n / 2 - 1]) {
        a2 = hash[a[n / 2]];
        a3 = 1;
      } else {
        a2 = hash[a[n / 2 - 1]] + hash[a[n / 2]];
        a3 = a[n / 2] - a[n / 2 - 1] + 1;
      }
    } else {
      a1 = a[n / 2];
      a2 = hash[a[n / 2]];
      a3 = 1;
    }
    cout << a1 << " " << a2 << " " << a3 << endl;
  }
  return 0;
}
/*
2
10
10
4
1
2
2
4
*/
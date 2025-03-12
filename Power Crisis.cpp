#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  while(cin >> n && n) {
    for(int m = 1 ; m < n ; m++) {
      int pos = 0;
      for(int i = 1 ; i < n ; i++) {
        pos = (pos + m) % i;
      }
      if(pos == 11) {
        cout << m << endl;
        break;
      }
    }
  }
  
  return 0;
}
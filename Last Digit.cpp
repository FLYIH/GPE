#include <bits/stdc++.h>
using namespace std;

int main() {
  string n;
  while(cin >> n) {
    if(n == "0") break;
    int len = n.length();
    int lasttwo;
    if(len == 1) {
      lasttwo = n[len - 1] - '0';
    } else {
      lasttwo = (n[len - 2] - '0') * 10 + (n[len - 1] - '0');
    }

    int res = 0;

    for(int i = 1 ; i <= lasttwo ; i++) {
      int x = 1, cnt = i;
      while(cnt--) {
          x *= i;
          x %= 10;
      }
    
      res += (x % 10);
    }
    cout << res % 10 << endl;
  }

  return 0;
}
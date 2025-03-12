#include <bits/stdc++.h>
using namespace std;

int main() {
  int s;
  long long d;

  while(cin >> s >> d) {
    long long l = 1, r = 1e8;
    while(l < r) {
      long long mid = l + (r - l) / 2;
      long long ans = mid * (2 * s - 1) + mid * mid;
      if(ans >= 2 * d) {
        r = mid;
      } else {
        l = mid + 1;
      }
    }
    cout << s + r - 1 << endl;
  }
}
/*
1 6
3 10
3 14
*/
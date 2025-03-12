#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
  return b == 0 ? abs(a) : gcd(b, a % b);
}

int main() {
  int n;
  cin >> n;
  while(n--) {
    int lines;
    cin >> lines;
    vector<pair<int, int>> v(lines);
    for(int i = 0 ; i < lines ; i++) {
      cin >> v[i].first >> v[i].second;
    }
    set<tuple<int, int, int>> s;
    for(int i = 0 ; i < lines ; i++) {
      for(int j = i + 1 ; j < lines ; j++) {
        int a = v[i].second - v[j].second;
        int b = v[j].first - v[i].first;
        
        int g = gcd(a, b);
        a /= g;
        b /= g;

        if(a < 0) {
          a = -a;
          b = -b;
        } else if(a == 0 && b < 0) {
          b = -b;
        }
        int c = - a * v[i].first - b * v[i].second;
        s.insert({a, b, c});
      }
    }
    cout << s.size() << endl;
  }
} 
/*
2
7 0 0 1 1 2 2 3 3 4 4 6 6 0 3
5 0 0 1 1 1 -1 -1 1 -1 -1
*/
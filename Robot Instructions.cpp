#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  while(n--) {
    int t;
    cin >> t;
    getchar();
    vector<string> s;
    int pos = 0;
    for(int i = 0 ; i < t ; i++) {
      string str;
      getline(cin, str);
    
      if(str.substr(0, 4) == "SAME") {
        string num = str.substr(8, str.length() - 8);
        int idx = stoi(num) - 1;
        //cout << "idx = " << idx << endl;
        str = s[idx];
      }
      if(str == "LEFT") {
        pos--;
        s.push_back(str);
      } else if(str == "RIGHT") {
        pos++;
        s.push_back(str);
      } 
    }
    cout << pos << endl; 
  }
}
/*
2
3
LEFT
RIGHT
SAME AS 2
5
LEFT
SAME AS 1
SAME AS 2
SAME AS 1
SAME AS 4
*/
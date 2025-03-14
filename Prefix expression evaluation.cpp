#include <bits/stdc++.h>
using namespace std;
int main() {
  while(1) {
    string s;
    getline(cin , s);
    if(s == ".") break;
    stack<int> dig;

    for(int i = s.size() - 1 ; i >= 0 ; i--) {
      if(s[i] == ' ') continue;
      if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '%') {
        if(dig.empty()) {
          break;
        }
        int num1 = dig.top();
        dig.pop();
        if(dig.empty()) {
          break;
        }
        int num2 = dig.top();
        dig.pop();
        char c = s[i];
        if(c == '+') dig.push(num1 + num2);
        else if(c == '-') dig.push(num1 - num2);
        else if(c == '*') dig.push(num1 * num2);
        else if(c == '/') {
          if(num2 == 0) break;
          dig.push(num1 / num2);
        }
        else if(c == '%') {
          if(num2 == 0) break;
          dig.push(num1 % num2);
        }
        // cout << num1 << " " << c << " " << num2 << " = " << dig.top() << endl;
      } else if(s[i] >= '0' && s[i] <= '9'){
        string temp = "";
        temp += s[i];
        while(i - 1 >= 0 && s[i - 1] >= '0' && s[i - 1] <= '9') {
          temp += s[i - 1];
          i--;
        }
        reverse(temp.begin() , temp.end());
        int num = stoi(temp);
        dig.push(num);
      }
    }
    if(dig.empty() || dig.size() != 1) cout << "illegal" << endl;
    else cout << dig.top() << endl;
  }
  return 0;
}
/*
- * + 23 % 45 10 6 / 77 12
162

+ * 234 56
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    while(n != 0) {
        unordered_map<string, int> hash;
        for(int j = 0 ; j < n ; j++) {
            vector<int> temp(5);
            for(int i = 0 ; i < 5 ; i++) {
                cin >> temp[i];
            }
            sort(temp.begin(), temp.end());

            string key = "";
            for(int i = 0 ; i < 5 ; i++) {
                key += to_string(temp[i]);
            }
            hash[key]++;
        }
        
        priority_queue<int> pq;
        for(auto it = hash.begin() ; it != hash.end() ; it++) {
            pq.push(it->second);
        }
        int max = pq.top();
        pq.pop();
        int count = max;
        while(!pq.empty()) {
            if(pq.top() == max) {
                count += max;
            } else {
                break;
            }
            pq.pop();
        }
        cout << count << endl;
        cin >> n;
    }
    return 0;
}
/*
3
100 101 102 103 488
100 200 300 101 102
103 102 101 488 100
3
200 202 204 206 208
123 234 345 456 321
100 200 300 400 444
0

2 3
*/
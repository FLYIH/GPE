#include <bits/stdc++.h>
using namespace std;

int main () {
  int l, r, c;
  int dir[6][3] = {{0, 0, 1}, {0 , 0, -1}, {0, 1, 0}, {0 , -1, 0}, {1, 0, 0}, {-1, 0, 0}};
  cin >> l >> r >> c;
  while(!(l == 0 && r == 0 && c == 0)) {
    vector<int> s(3), e(3);
    vector<vector<vector<char>>> m(l, vector<vector<char>>(r, vector<char>(c)));
    for(int i = 0 ; i < l ; i++) {
      for(int j =  0 ; j < r ; j++) {
        for(int k = 0 ; k < c ; k++) {
          cin >> m[i][j][k];
          if(m[i][j][k] == 'S') {
            s[0] = i; s[1] = j; s[2] = k;
            // z x y
          }
          if(m[i][j][k] == 'E') {
            e[0] = i; e[1] = j; e[2] = k;
            // z x y
          }
        }
      }
    }

    vector<vector<vector<bool>>> visited(l, vector<vector<bool>>(r, vector<bool>(c, false)));
    priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>, greater<pair<int, vector<int>>>> pq;
    pq.push({0, {s[0], s[1], s[2]}});
    int res = -1;
    while(!pq.empty()) {
      int dist = pq.top().first;
      vector<int> cur = pq.top().second;
      pq.pop();
      if(cur[0] < 0 || cur[0] >= l || cur[1] < 0 || cur[1] >= r || cur[2] < 0 || cur[2] >= c || visited[cur[0]][cur[1]][cur[2]] || m[cur[0]][cur[1]][cur[2]] == '#') {
        continue;
      }
      if(cur[0] == e[0] && cur[1] == e[1] && cur[2] == e[2]) {
        res = dist;
        break;
      }
      visited[cur[0]][cur[1]][cur[2]] = true;
      for(int i = 0 ; i < 6 ; i++) {
        int z = cur[0] + dir[i][0];
        int x = cur[1] + dir[i][1];
        int y = cur[2] + dir[i][2];
        pq.push({dist + 1, {z, x, y}});
      }
    }
    if(res == -1) {
      cout << "Trapped!" << endl;
    } else {
      cout << "Escaped in " << res << " minute(s)." << endl;
    }
    cin >> l >> r >> c;
  }
  return 0;
}
/*
3 4 5
S....
.###.
.##..
###.#

#####
#####
##.##
##...

#####
#####
#.###
####E

1 3 3
S##
#E#
###

0 0 0
*/
#include <bits/stdc++.h>
using namespace std;
int main() {
  int c[6] = {5, 10, 20, 50, 100, 200};

  while(1) {
    vector<pair<int, int>> coins(6);
    double p;
    int total = 0;
    for(int i = 0 ; i < 6; i++) {
      int cnt;
      cin >> cnt;
      coins[i] = {c[i], cnt};
      total += cnt;
    }
    if(total == 0) break;
    cin >> p;
    int price = (int)(p * 100 + 0.5);

    int maxPrice = 5000;
    vector<int> dp(maxPrice + 1, 1e9);
    dp[0] = 0;

    for(int i = 0 ; i < 6 ; i++) {
      int count = coins[i].second;
      for(int j = 1 ; count > 0 ; j *= 2) {
        int num = min(j, count);
        count -= num;
        int coinPrice = coins[i].first * num;
        for(int k = maxPrice ; k - coinPrice >= 0 ; k--) {
          if(dp[k - coinPrice] == 1e9)
            continue;
          dp[k] = min(dp[k], dp[k - coinPrice] + num);
        }
      }
    }

    int minCoins = dp[price];
    vector<int> changedp(maxPrice + 1, 1e9);
    changedp[0] = 0;
    
    for(int j = 0 ; j < 6 ; j++) {
      for(int k = coins[j].first ; k <= maxPrice - price; k++) {
        changedp[k] = min(changedp[k], changedp[k - coins[j].first] + 1);
      }
    }
    
    for(int i = price ; i <= maxPrice ; i+=5) {
      int change = i - price;
      if(changedp[change] != 1e9)
        minCoins = min(minCoins, dp[i] + changedp[change]);
    }

    cout << setw(3) << minCoins << endl;
  }
  return 0;
}
#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;
int dp[101][101];
int cost[101][101];
int n;

int dp_cal(int x, int y){
    if(x > n || y > n) return 0;
    if(x == n && y == n) return 1;
    int& ret = dp[x][y];
    if(ret != -1) return ret;
    return ret = dp_cal(x + cost[x][y], y) || dp_cal(x, y + cost[x][y]);
}

int main(void){
    int t;
    cin >> t;
    while(t--){
        memset(dp, -1, sizeof(dp));
        memset(cost, 0, sizeof(dp));
        cin >> n;
        
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                cin >> cost[i][j];
            }
        }
        int result = dp_cal(1, 1);
        if(result == 1) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
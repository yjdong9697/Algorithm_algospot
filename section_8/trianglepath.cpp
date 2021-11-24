#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;
int triangle[101][101];
int dp[101][101];
int n;

int memoization(int x, int y){
    if(x == n) return triangle[x][y];
    int& ret = dp[x][y];
    if(ret != -1) return ret;
    else{
        return ret = max(memoization(x + 1, y), memoization(x + 1, y + 1)) + triangle[x][y];
    }
}

int main(void){
    fastio;
    int t;
    cin >> t;
    while(t--){
        memset(dp, -1, sizeof(dp));
        cin >> n;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= i; j++){
                cin >> triangle[i][j];
            }
        }
        cout << memoization(1, 1) << "\n";
    }
}
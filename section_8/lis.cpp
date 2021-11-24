#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;
int value[500];
int dp[500];
int n;

int memoi(int x){
    int& ret = dp[x];
    if(ret != -1) return ret;
    int max_cal = 1;
    for(int i = x + 1; i < n; i++){
        if(value[x] < value[i]) max_cal = max(max_cal, memoi(i) + 1);
    }
    return ret = max_cal;
}

int main(void){
    fastio;
    int t;
    cin >> t;
    while(t--){
        memset(dp, -1, sizeof(dp));
        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> value[i];
        }
        memoi(0);

        int result = -1;

        for(int i = 0; i < n; i++){
            result = max(result, memoi(i));
        }
        cout << result << "\n";
    }
    return 0;
}
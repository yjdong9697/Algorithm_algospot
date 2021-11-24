#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;
string W;
string T;
int dp[101][101];

bool memoization(int w, int t){
    int& ret = dp[w][t];
    if(ret != -1) return ret;
    while(w < W.size() && t < T.size() && (W[w] == T[t] || W[w] == '?')){
        return ret = memoization(w + 1, t + 1);
    }
    if(w == W.size()) return (t == T.size());

    if(W[w] == '*'){
        if(memoization(w + 1, t) || (t < T.size() && memoization(w, t + 1))) return ret = true;
    }
    return ret = false;
}

int main(void){
    int c;
    cin >> c;
    while(c--){    
        cin >> W;
        int n;
        cin >> n;
        vector<string> v;
        for(int i = 0; i < n; i++){
            memset(dp, -1, sizeof(dp));
            cin >> T;
            if(memoization(0, 0)) v.push_back(T);
        }
        sort(v.begin(), v.end());
        for(int i = 0; i < v.size(); i++){
            cout << v[i] << "\n";
        }
    }
    return 0;
}
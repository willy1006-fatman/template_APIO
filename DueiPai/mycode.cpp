#include<bits/stdc++.h>
using namespace std;
#define IOS cin.tie(nullptr)->sync_with_stdio(0),cin.exceptions(cin.failbit);
#define lb(x) (x)&-(x)
#define all(x) (x).begin(),(x).end()
#define ll long long

constexpr int maxN=1e4+5,maxM = 1e2+5;

int n,m,K,dp0[maxN],pts[maxN<<1][maxM],pos[maxN<<1];

deque<int> cand[maxN];

bitset<maxM> dp[maxN];

int main(){
    cin>>n>>m>>K;
    for(int i = 1;i<=n;i++){
        int sum = 0;
        for(int j = 1;j<=m;j++)cin>>pts[i][j],sum+=pts[i][j];
        cand[sum].emplace_back(i);
        pos[i] = sum;
    }
    int lst = n+1;
    for(int i = 0;i<=m*K;i++){
        dp0[i] = max(dp0[i],dp0[i-1]);
        for(;!cand[i].empty();){
            int id = cand[i].back();
            cand[i].pop_back();
            int flag = 0;
            if(lst<id)flag = 1;
            dp[i].reset();
            dp[pos[lst]].reset();
            dp[i][0] = 1;
            for(int k = 1;k<=m;k++){
                for(int j = pos[lst];j+pts[id][k]<=i;j++){
                    dp[j]|=(dp[j+pts[id][k]]<<1);
                }
            }
            int nxt = i;
            int flag2 = 1;
            for(;nxt<=m*K&&cand[nxt].empty();nxt++);
            if(nxt==m*K+1||cand[nxt].back()>id)flag2 = 0;
            for(int k = 1;k<=m;k++)for(int j = pos[lst]+flag;j<=i;j++)if(dp[j][k]){
                if(j+K*k<nxt+flag2){
                    dp0[j+K*k] = max(dp0[j+K*k],dp0[j-flag]+k);
                }
            }
            lst = id;
        }
    }
    cout<<n*m-dp0[m*K]<<'\n';
}
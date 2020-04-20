#include <bits/stdc++.h>
#define INF 1000000000
using namespace std;

const int MAX_N=16;
int N, W[MAX_N][MAX_N], DP[MAX_N][1<<16];

int dp(int last, int path){
    if(DP[last][path]!=-1) return DP[last][path];
    if(path==(1<<N)-1)
        return (W[last][0]!=0 ? W[last][0] : INF);
   
    DP[last][path] = INF;
    for(int i=1; i<N; i++)
        if((~path & (1<<i)) && W[last][i])
            DP[last][path] = min(DP[last][path], dp(i, path | (1<<i))+W[last][i]);
    
    return DP[last][path];
}
int main(){
    scanf("%d", &N);
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++) scanf("%d", W[i]+j);
    
    memset(DP, -1, sizeof(DP));
    cout << dp(0,1);
}
#include <bits/stdc++.h>
#define INF 1000000000
using namespace std;

int N, W[16][16], P, DP[1<<16], S;

int bitCnt(int n){
    int cnt=0;
    while(n>0){
        if(n & 1) cnt++;
        n >>= 1;
    }
    return cnt;
}
int dp(int stat){
    if(DP[stat]!=-1) return DP[stat];
    if(bitCnt(stat)>=P) return 0;

    DP[stat] = INF;

    for(int i=0; i<N; i++)
        if(!(stat & (1<<i))){
            int minCost=INF, bef;
            for(int j=0; j<N; j++)
                if((stat & (1<<j)) && W[j][i]<minCost){
                    minCost = W[j][i]; bef = j;
                }

            DP[stat] = min(DP[stat],
                dp(stat | (1<<i))+W[bef][i]);
        }

    return DP[stat];
}
int main(){
    memset(DP, -1, sizeof(DP));

    scanf("%d", &N);
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            scanf("%d", W[i]+j);

    char tmp[17];
    scanf("%s", tmp);
    scanf("%d", &P);
    
    for(int i=0; i<N; i++){
        if(tmp[i]=='Y')
            S |= (1<<i);
    }
    
    if(S==0 && P>0) printf("-1");
    else printf("%d", dp(S));
}
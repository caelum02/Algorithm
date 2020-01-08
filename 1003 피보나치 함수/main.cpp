#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int T; pii DP[41]; bool visited[41];
pii f(int n){
    if(visited[n]++)  return DP[n];
    if(n==0)    return DP[n]={1, 0};
    if(n==1)    return DP[n]={0, 1};
    return DP[n]={f(n-1).first+f(n-2).first, f(n-1).second+f(n-2).second};
}
int main(){
    scanf("%d", &T);
    int t;
    while(T--){
        scanf("%d", &t); printf("%d %d\n", f(t).first, f(t).second);
    }
}
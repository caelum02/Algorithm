#include <bits/stdc++.h>
using namespace std;

const int MAX_V = 402, INF = 99999999;
int N, M, c[MAX_V][MAX_V], f[MAX_V][MAX_V], totFlow;
int main(){
    scanf("%d %d", &N, &M); int S=0, E=N+M+1;
    vector<int> adj[N+M+2];
    for(int i=1; i<=N; i++){
        adj[S].push_back(i); adj[i].push_back(S); c[S][i]=1;
        
        int t, u; scanf("%d", &t);
        while(t--){
            scanf("%d", &u); c[i][N+u]=1; adj[i].push_back(N+u); adj[N+u].push_back(i);
        }
    }
    for(int i=1; i<=M; i++){
        c[N+i][E]=1;
        adj[N+i].push_back(E);
        adj[E].push_back(N+i);
    }
    while(1){
        queue<int> q; q.push(S);
        int p[MAX_V]; fill(p, p+MAX_V, -1);
        while(!q.empty() && p[E]==-1){
            int cur = q.front(); q.pop();
            for(int nxt : adj[cur]){
                if(p[nxt]==-1 && (c[cur][nxt]-f[cur][nxt]) > 0){
                    p[nxt]=cur; q.push(nxt);
                    if(nxt==E) break;
                }
            }
        }
        if(p[E]==-1) break;
        for(int i=E; i!=S; i=p[i]){
            f[p[i]][i] += 1; f[i][p[i]] -= 1;
        }
        totFlow += 1;
    }
    printf("%d", totFlow);
}

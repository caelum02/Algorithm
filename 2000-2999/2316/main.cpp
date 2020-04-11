#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 400;

int N, P, S, E, f[2*MAX_N+1][2*MAX_N+1], c[2*MAX_N+1][2*MAX_N+1], total;
int main(){
    scanf("%d %d", &N, &P);

    S=1; E=2;
    vector<int> adj[2*N+1];
    for(int i=3; i<=N; i++){
        adj[i].push_back(i+N);
        adj[i+N].push_back(i);
        c[i][i+N]=1;
    }
        
    int a, b;
    while(P--){
        scanf("%d %d", &a, &b);
        adj[a+N].push_back(b);
        adj[b].push_back(a+N);
        adj[b+N].push_back(a);
        adj[a].push_back(b+N);
        c[a+N][b]=1;
        c[b+N][a]=1;
    }
    while(1){
        queue<int> q;
        q.push(S+N);
        int prv[2*MAX_N+1];
        fill(prv, prv+2*MAX_N+1, -1);
        while(!q.empty() && prv[E]==-1){
            int cur = q.front(); q.pop();
            for(int &nxt : adj[cur]){
                if(prv[nxt]==-1 && c[cur][nxt]-f[cur][nxt] > 0){
                    q.push(nxt); prv[nxt]=cur;
                    if(nxt==E) break;
                }
            }
        }
        if(prv[E]==-1) break;
        
        for(int i=E; i!=S+N; i=prv[i]){
            f[i][prv[i]]--; f[prv[i]][i]++;
        }
        total++;
    }
    printf("%d", total);
}

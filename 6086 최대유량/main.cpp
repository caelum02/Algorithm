#include <bits/stdc++.h>
using namespace std;

const int MAX_V = 52;
const int INF = 10000000;

int N, cap[MAX_V][MAX_V], flow[MAX_V][MAX_V], maxf;

int c2d(char c){
    if('a' <= c && c <= 'z') return c-'a';
    return c - 'A' + 26;
}
int main(){
    scanf("%d", &N);
    vector<int> adj[MAX_V];
    
    while(N--){
        char u, v; int w;
        scanf(" %c %c %d", &u, &v, &w);
        u = c2d(u); v = c2d(v);
        cap[u][v] = cap[v][u] += w;
        adj[u].push_back(v); adj[v].push_back(u);
    }
    int S = c2d('A'), E = c2d('Z'); cout << "\n";
    while(1){
        int prev[MAX_V];
        fill(prev, prev+MAX_V, -1);
        queue<int> q; q.push(S);
        while(!q.empty() && prev[E]==-1){
            int c = q.front(); q.pop();
            for(int n : adj[c]){
                if(prev[n]==-1 && (cap[c][n]-flow[c][n]) > 0){
                    prev[n]=c; q.push(n); cout << c << " " << n << "\n";
                    if(n==E) break;
                }
            }
        }
        if(prev[E]==-1) break;
        int minf = INF;
        for(int i=E; i!=S; i=prev[i])
            minf = min(minf, cap[prev[i]][i]-flow[prev[i]][i]);
        
        for(int i=E; i!=S; i=prev[i]){
            flow[prev[i]][i] += minf;
            flow[i][prev[i]] -= minf;
        }

        maxf += minf;
    }
    printf("%d", maxf);
}
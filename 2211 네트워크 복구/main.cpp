#include <bits/stdc++.h>
#define inf 999999999
using namespace std;

int N, M, w[1001][1001], dist[1001], prv[1001], cnt;
bool visited[1001], cn[1001][1001], visited_[1001]; // cn : 네트워크 연결 여부
typedef pair<int, int> pii;
int main(){
    scanf("%d %d", &N, &M);
    int a, b, c;
    vector<int> adj[N+1];
    for(int i=2; i<=N; i++) dist[i]=inf;
    for(int i=0; i<M; i++){
        scanf("%d %d %d", &a, &b, &c);
        w[a][b]=w[b][a]=c;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    priority_queue<int> pq; pq.push(-1);
    while(!pq.empty()){
        int cur;
        do{
            cur=-pq.top(); pq.pop();
        } while(!pq.empty() && visited[cur]);
        if(visited[cur]) break;
        visited[cur]++;
        for(int p : adj[cur])
            if(dist[p] > dist[cur] + w[cur][p]){
                dist[p] = dist[cur] + w[cur][p];
                pq.push(-p); prv[p]=cur;
            }
    }
    vector<pii> v;
    for(int i=2; i<=N; i++){
        if(visited_[i]) continue;
        for(int j=i; j!=1; j=prv[j])
            if(!cn[prv[j]][j]){
                v.push_back({prv[j], j}); cnt++; cn[prv[j]][j]=cn[j][prv[j]]=true; visited_[j]++;
            }
    }
    cout << v.size() << endl;
    for(auto &i : v)
        printf("%d %d\n", i.first, i.second);
}
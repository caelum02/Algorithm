#include <bits/stdc++.h>
using namespace std;

int edge[501][501], in[501], n, m;

void init(){
    memset(edge, 0, sizeof(edge));
    memset(in, 0, sizeof(in));
}
void solve(){

        scanf("%d", &n); int tmp;

        for(int i=0; i<n; i++){
            scanf("%d", &tmp);
            for(int j=1; j<=n; j++)
                if(!edge[j][tmp] && tmp != j){
                    edge[tmp][j]++; in[j]++;
                }
        }

        scanf("%d", &m);

        int a, b;
        while(m--){
            scanf("%d %d", &a, &b);
            int d = (edge[a][b] ? 1 : -1);  in[a] += d; in[b] -= d;
            swap(edge[a][b], edge[b][a]);
        }

        int f, cnt = 0;
        vector<int> out; tmp=0;
        queue<int> q;

        for(int i=1; i<=n; i++)
            if(!in[i])
                q.push(i);

        while(!q.empty()){
            int h = q.front(); q.pop(); tmp = 0; cnt++; out.push_back(h);
            for(int i=1; i<=n; i++){
                if(edge[h][i])
                    if(!(--in[i]))
                        q.push(i);
            }
            if(q.size()>1){printf("?\n"); return;}
        }
        
        if(cnt != n){
            printf("IMPOSSIBLE\n"); return;
        }

        for(int i : out)
            printf("%d ", i);
        printf("\n");
}
int main(){
    int T; scanf("%d", &T);
    while(T--){
        init(); solve();
    }
}
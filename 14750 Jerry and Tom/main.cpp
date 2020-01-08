#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

const int MAX_n=1000, MAX_h=50, MAX_k=5, MAX_v=MAX_h*MAX_k+MAX_h+2 ;

int n, k, h, m, S, E, total;
pii hole[MAX_h], mic[MAX_k*MAX_h], crn[MAX_n];
int c[MAX_v][MAX_v], f[MAX_v][MAX_v];

inline int ccw(pii p1, pii p2, pii p3){
    ll x1 = p2.first-p1.first, y1 = p2.second-p1.second, x2 = p3.first-p1.first, y2 = p3.second-p1.second;
    ll op = x1*y2-x2*y1;
    return op>0 ? 1 : (op<0 ? -1 : 0);
}
inline bool intersect(pii m, pii h, pii n1, pii n2){
    int ccw1 = ccw(m, h, n1) * ccw(m, h, n2), ccw2 = ccw(n1, n2, m) * ccw(n1, n2, h);
    if(ccw1 == 0 && ccw2 == 0){
        if(m > h) swap(m, h);
        if(n1 > n2) swap(n1, n2);
        return n2 >= m && h >= n1;
    }
    else return ccw1 <= 0 && ccw2 <= 0;
}
inline bool canSee(int mi, int hi){
    for(int i=0; i<n-1; i++){
        if(((crn[i] <= hole[hi] && hole[hi] <= crn[i+1]) || (crn[i] >= hole[hi] && hole[hi] >= crn[i+1])) && ccw(crn[i], crn[i+1], hole[hi])==0) continue;
        if(intersect(mic[mi], hole[hi], crn[i], crn[i+1])) return false;
    }

    if(!(((crn[n-1] <= hole[hi] && hole[hi] <= crn[0]) || (crn[n-1] >= hole[hi] && hole[hi] >= crn[0])) && ccw(crn[n-1], crn[0], hole[hi])==0) 
        && intersect(mic[mi], hole[hi], crn[n-1], crn[0])) return false;
    
    return true;
}
int main(){
    scanf("%d %d %d %d", &n, &k, &h, &m);
    S = 0; E = m + h + 1;
    vector<int> adj[m+h+2];

    for(int i=0; i<n; i++)
        scanf("%d %d", &crn[i].first, &crn[i].second);
    for(int i=0; i<h; i++)
        scanf("%d %d", &hole[i].first, &hole[i].second);
    for(int i=0; i<m; i++)
        scanf("%d %d", &mic[i].first, &mic[i].second);

    for(int mi=0; mi<m; mi++){
        adj[S].push_back(1+mi);
        adj[1+mi].push_back(S);
        c[S][1+mi]=1;
    }

    for(int mi=0; mi<m; mi++)
        for(int hi=0; hi<h; hi++){
            if(canSee(mi, hi)){
                adj[1+mi].push_back(m+1+hi);
                adj[1+m+hi].push_back(1+mi);
                c[1+mi][m+1+hi]=1;
            }
        }

    for(int hi=0; hi<h; hi++){
        adj[m+1+hi].push_back(E);
        c[m+1+hi][E]=k;
    }

    while(1){
        int prev[MAX_v]; fill(prev, prev+MAX_v, -1);
        queue<int> q; q.push(S);
        while(!q.empty() && prev[E]==-1){
            int cur = q.front(); q.pop();
            for(int &nxt : adj[cur]){
                if(prev[nxt]==-1 && c[cur][nxt]-f[cur][nxt] > 0){
                    q.push(nxt); prev[nxt]=cur;
                    if(nxt==E) break;
                }
            }
        }
        if(prev[E]==-1) break;

        for(int i=E; i!=S; i=prev[i]){
            f[prev[i]][i]++; f[i][prev[i]]--;
        }
        total++;
    }
    puts(total == m ? "Possible" : "Impossible");
}
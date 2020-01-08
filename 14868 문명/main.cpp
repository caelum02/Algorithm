#include <bits/stdc++.h>
using namespace std;
int m[2001][2001], N, K, p[100001], lev[100001], di[4]={0,1,0,-1}, dj[]={1,0,-1,0};
int cnt, y=0;
bool safe(int x, int y){ return 1<=x && x<=N && 1<=y && y<=N; }
int Find(int i){
    if(p[i]==i) return i;
    return p[i]=Find(p[i]);
}
void Union(int i, int j){
    i = Find(i); j = Find(j);
    if(i==j) return;
    cnt--;
    if(lev[i]==lev[j]){
        p[j]=i; lev[i]++; return;
    }
    if(lev[i] > lev[j]) p[j]=i;
    else p[i]=j;
}
int main(){
    scanf("%d %d", &N, &K); cnt = K;
    for(int i=1; i<=K; i++) p[i] = i;
    
    int tx, ty;
    queue<int> Q[2];
    
    for(int i=1; i<=K; i++){
        scanf("%d %d", &tx, &ty);
        m[tx][ty]=i; Q[1].push((tx<<11)+ty);
        for(int k=0; k<4; k++)
            if(safe(tx+di[k], ty+dj[k]) && m[tx+di[k]][ty+dj[k]])
                Union(i, m[tx+di[k]][ty+dj[k]]);
    }

    while(cnt>1){
        y++;
        queue<int> &q = Q[y%2];
        while(!q.empty()){
            int p = q.front(); q.pop();
            int ci = p >> 11, cj = p & ((1<<11)-1);
            for(int k=0; k<4; k++){
                int ni=ci+di[k], nj=cj+dj[k]; if(!safe(ni, nj)) continue;
                if(!m[ni][nj]){
                    m[ni][nj]=m[ci][cj];
                    for(int l=0; l<4; l++){
                        int nni = ni+di[l], nnj=nj+dj[l];
                        if(safe(nni, nnj) && m[nni][nnj] && m[nni][nnj]!=m[ni][nj])
                            Union(m[ni][nj], m[nni][nnj]);
                    }
                    Q[(y+1)%2].push((ni<<11) + nj);
                } 
                else Union(m[ci][cj], m[ni][nj]);
            }
        }
        
    }
    printf("%d", y);
}
#include <bits/stdc++.h>
#define inf 999999999
using namespace std;

const int MAX_N=125;
int mp[MAX_N][MAX_N], dist[MAX_N][MAX_N], di[]={1, 0, -1, 0}, dj[]={0, 1, 0, -1};
int N, cnt=0;
bool visited[MAX_N][MAX_N];
inline bool safe(int i, int j){
    return 0<=i && i<N && 0<=j && j<N;
}
int main(){
    scanf("%d", &N);
    while(N!=0){
        cnt++;
        for(int i=0; i<N; i++)
            for(int j=0; j<N; j++){
                scanf("%d", mp[i]+j);
                dist[i][j]=inf;
                visited[i][j]=false;
            }

        priority_queue<int> pq;
        dist[0][0]=mp[0][0]; pq.push(0);
        while(!pq.empty()){
            int cur, ci, cj;
            do{
                cur = -pq.top(); pq.pop();
                ci = cur >> 7; cj = cur & ((1<<7)-1);
            } while(!pq.empty()&&visited[ci][cj]);
            if(dist[ci][cj]==inf) break;
            visited[ci][cj]=true;
            for(int k=0; k<4; k++){
                int ni=ci+di[k], nj=cj+dj[k];
                if(!safe(ni, nj)) continue;
                if(dist[ni][nj] > dist[ci][cj]+mp[ni][nj]){
                    dist[ni][nj] = dist[ci][cj]+mp[ni][nj];
                    pq.push(-((ni<<7)+nj));
                }
            }
        }
        printf("Problem %d: %d\n", cnt, dist[N-1][N-1]);
        scanf("%d", &N);
    };
    

}

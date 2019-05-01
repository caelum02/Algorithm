#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int M, N, box[1000][1000], cnt = 0, day[1000][1000];
int di[] = {-1, 0, 1, 0}, dj[] = {0, 1, 0, -1};

bool safe(pii p){
    int i = p.first, j = p.second;
    return 0<=i && i<N && 0<=j && j<M;
}
int main(){
    scanf("%d %d", &M, &N);
    queue<pii> q;

    for(int i=0; i<N; i++)
    for(int j=0; j<M; j++){
        scanf("%d", box[i] + j);
        if(box[i][j] == 1){
            q.push({i, j});
            day[i][j] = 0;
        }
            
        if(box[i][j] == 0)
            cnt++;
    }

    int maxDay = 0;
    while(!q.empty()){
        pii c = q.front(); q.pop();
        for(int k=0; k<4; k++){
            pii n = {c.first + di[k], c.second + dj[k]};
            if(safe(n) && box[n.first][n.second] == 0){
                q.push(n);
                box[n.first][n.second] = 1;
                maxDay = max(day[n.first][n.second] = day[c.first][c.second] + 1, maxDay);
                cnt--;
            }
        }
    }

    if(cnt != 0) printf("-1");
    else printf("%d", maxDay);

    return 0;
}

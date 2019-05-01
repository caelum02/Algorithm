#include <bits/stdc++.h>
using namespace std;

struct pos{int i, j, k;};

int M, N, H, box[100][100][100], cnt = 0, day[100][100][100];
int di[] = {-1, 0, 1, 0, 0, 0}, dj[] = {0, 1, 0, -1, 0, 0}, dk[] = {0, 0, 0, 0, 1, -1};

bool safe(pos p){
    int i = p.i, j = p.j, k = p.k;
    return 0<=i && i<N && 0<=j && j<M && 0<=k && k<H;
}

int main(){
    scanf("%d %d %d", &M, &N, &H);
    queue<pos> q;

    for(int k=0; k<H; k++)
    for(int i=0; i<N; i++)
    for(int j=0; j<M; j++){
        scanf("%d", &box[k][i][j]);
        if(box[k][i][j] == 1)
            q.push({i, j, k});
        if(box[k][i][j] == 0)
            cnt++;
    }

    int maxDay = 0;
    while(!q.empty()){
        pos c = q.front(); q.pop();
        // printf("%d %d %d\n", c.i, c.j, c.k);
        for(int k=0; k<6; k++){
            pos n = {c.i + di[k], c.j + dj[k], c.k + dk[k]};
            if(safe(n) && box[n.k][n.i][n.j] == 0){
                q.push(n);
                box[n.k][n.i][n.j] = 1;
                maxDay = max(day[n.k][n.i][n.j] = day[c.k][c.i][c.j] + 1, maxDay);
                cnt--;
            }
        }
    }

    if(cnt != 0) printf("-1");
    else printf("%d", maxDay);

    return 0;
}

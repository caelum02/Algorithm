#include <bits/stdc++.h>
#define INF 987654321
using namespace std;

struct pos{
    int x, y;

    void operator+= (const pos &p){
        x += p.x;
        y += p.y;
    }
    pos operator+ (const pos &p){
        return pos{x+p.x, y+p.y};
    }
    pos operator- (const pos &p){
        return pos{x-p.x, y-p.y};
    }
};

pos P[21];
double ans = INF;
int T, N;
pos total;

double norm(pos p){
    return sqrt(1LL*p.x*p.x+1LL*p.y*p.y);
}
void query(int ub, int cnt, pos s){
    if(cnt==0){
        double tmp = norm(s+s-total);
        ans = min(ans, tmp);
        return;
    }   
    for(int u=ub; u>=cnt; u--)
        query(u-1, cnt-1, s+P[u]);
}

int main(){
    cin >> T;
    while(T--){
        cin >> N;
        for(int i=1; i<=N; i++){
            scanf("%d %d", &P[i].x, &P[i].y);
            total += P[i];
        }

        ans = INF;
        query(N, N/2, {0,0});
        printf("%lf\n", ans);
    }
}
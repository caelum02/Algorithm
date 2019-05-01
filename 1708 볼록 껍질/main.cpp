#include <bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
int N;
const int inf=99999999;

ll ccw(pii p1, pii p2, pii p3){
    return 1LL*(p2.x-p1.x)*(p3.y-p1.y) - 1LL*(p2.y-p1.y)*(p3.x-p1.x);
}
int main(){    
    scanf("%d", &N); pii b={inf, inf};
    vector<pii> v(N); int idx;

    for(int i=0; i<N; i++){
        scanf("%d %d", &v[i].x, &v[i].y);
        if(v[i] < b){
            b=v[i]; idx=i;
        }
    }

    v.erase(v.begin()+idx);
    for(pii &i : v){
        i.x-=b.x; i.y-=b.y;
    }
    
    sort(v.begin(), v.end(), 
        [](const pii &p1, const pii &p2){
            return 1LL*p1.y*p2.x < 1LL*p1.x*p2.y;
        });
    v.insert(v.begin(), {0, 0});
    v.push_back({0,0});

    stack<int> stk;
    stk.push(0); stk.push(1); int next=2;
    while(next < N+1){
        while(stk.size()>=2){
            int f, s; f=stk.top(); stk.pop();
            s=stk.top();
            if(ccw(v[s], v[f], v[next])>0){
                stk.push(f); break;
            }
        }
        stk.push(next++);
    }
    stk.pop();
    printf("%d", stk.size());
}
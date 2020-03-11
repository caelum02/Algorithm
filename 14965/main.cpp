#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
int N, x[1000000], y[1000000];

int main(){
    scanf("%d", &N);
    vector<pii> v;

    int lb=1e9+1, idx=0;
    for(int i=0; i<N; i++){
        scanf("%d %d", &x[i], &y[i]);
        if(lb>x[i]){
            lb=x[i]; idx=i;
        }
    }
    int j, s, cnt=1;
    for(int i=0; i<N; i+=2){
        j=(i+idx)%N;
        if(1LL*y[j]*y[(j+1)%N]<0){
            if(cnt%2) s=x[j];
            else {
                int flag=(s<x[j] ? 1 : -1);
                v.push_back({s, flag});
                v.push_back({x[j], -flag});
            }
            cnt++;
        }
    }

    sort(v.begin(), v.end());

    int stk=0, a=0, b=0;
    stk += v[0].second;
    for(int i=1; i<v.size(); i++){
        if(v[i-1].second>0 && v[i].second<0) b++;
        stk += v[i].second;
        if(stk==0 && v[i].second<0) a++;
    }
    printf("%d %d", a, b);
}

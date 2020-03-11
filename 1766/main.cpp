#include <bits/stdc++.h>
using namespace std;

int N, M, in[32001];
int main(){
    scanf("%d %d", &N, &M);
    vector<int> to[N+1];
    for(int i=0; i<M; i++){
        int t1, t2;
        scanf("%d %d", &t1, &t2);
        to[t1].push_back(t2);
        in[t2]++;
    }

    priority_queue<int> pq;

    for(int i=1; i<=N; i++)
        if(!in[i]) pq.push(-i);
    
    while(!pq.empty()){
        int c = -pq.top(); pq.pop();
        printf("%d ", c);
        for(int n : to[c]){
            if(!(--in[n]))  pq.push(-n);
        }
    }
}
#include <bits/stdc++.h>
using namespace std;

int N; priority_queue<int> pq;
int main(){
    scanf("%d", &N); int t;
    for(int i=1; i<=N; i++){
        scanf("%d", &t);
        pq.push(-t);
    }
    for(int i=N+1; i<=N*N; i++){
        scanf("%d", &t);
        pq.push(-t); pq.pop();
    }
    printf("%d", -pq.top());
}
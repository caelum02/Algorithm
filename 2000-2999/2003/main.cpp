#include <bits/stdc++.h>
using namespace std;

int N, M;
const int MAX_N = 10000;
int A[MAX_N];

int main(){
    scanf("%d %d", &N, &M);
    for(int* i=A; i<A+N; i++)
        scanf("%d", i);

    // two pointer technique
    int l=0,r=0, sum=0, res=0;
    while(r<=N){
        if(sum == M) res++;
        if(sum >= M) sum -= A[l++];
        if(sum < M)  sum += A[r++];
    }
    printf("%d", res);

}
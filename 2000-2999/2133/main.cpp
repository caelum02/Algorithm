#include <bits/stdc++.h>
using namespace std;

int a[31], b[31];
int main(){
    int N; scanf("%d", &N);
    if(N%2){
        printf("0"); return 0;
    }

    a[2]=1;
    b[2]=2;

    for(int i=4; i<=N; i+=2){
        a[i]=2*a[i-2]+b[i-2];
        b[i]=3*a[i-2]+2*b[i-2];
    }

    printf("%d", a[N]+b[N]);
}
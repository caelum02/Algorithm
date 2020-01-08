#include <bits/stdc++.h>
using namespace std;
int M[2][3], m[2][3], t1, t2, t3;
int main(){
    int N; scanf("%d", &N);
    for(int i=1; i<=N; i++){
        scanf("%d %d %d", &t1, &t2, &t3);
        bool bf = (i-1)%2;
        M[i%2][0] = max(M[bf][0], M[bf][1]) + t1;
        M[i%2][1] = max(M[bf][0], max(M[bf][1], M[bf][2])) + t2;
        M[i%2][2] = max(M[bf][1], M[bf][2]) + t3;
        
        m[i%2][0] = min(m[bf][0], m[bf][1]) + t1;
        m[i%2][1] = min(m[bf][0], min(m[bf][1], m[bf][2])) + t2;
        m[i%2][2] = min(m[bf][1], m[bf][2]) + t3;
    }
    printf("%d %d", max(max(M[N%2][0], M[N%2][1]), M[N%2][2]),
                    min(min(m[N%2][0], m[N%2][1]), m[N%2][2]));
}
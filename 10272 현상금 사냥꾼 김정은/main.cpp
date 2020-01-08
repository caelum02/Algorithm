#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
struct crd{int x, y;};

int T, n;
double d[513][513][2], dp[513][513];;
int x[513], y[513];

inline double getD(int i, int j){
    if(d[i][j][1] == T) return d[i][j][0];
    d[i][j][1] = T;
    return d[i][j][0] = sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
}
void init(){    
    scanf("%d", &n);

    int t1, t2;
    for(int i=1; i<=n; i++)
        scanf("%d %d", x + i, y + i);
    
    dp[2][1] = getD(1, 2); dp[1][1] = 0;
}
int main(){
    cin >> T;

    while(T){
        init();
        
        for(int i=3; i<=n; i++){
            for(int j=1; j<=i-2; j++)
                dp[i][j] = dp[i-1][j] + getD(i-1, i);
                
            dp[i][i-1] = 9999999999;
            for(int j=1; j<=i-2; j++)
                dp[i][i-1] = min(dp[i][i-1], dp[i-1][j] + getD(j, i));
        }
        
        dp[n][n] = 9999999999;

        for(int i=1; i<n; i++)
            dp[n][n] = min(dp[n][n], dp[n][i] + getD(i, n));
        
        printf("%.2lf\n", dp[n][n]);
        T -= 1;
    }
}
#include <bits/stdc++.h>
using namespace std;

inline int sq(int x){
    return x*x;
}
int main(){
    int T;
    cin >> T;

    while(T--){
        int x1, y1, r1, x2, y2, r2;
        scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);
        int dsq = sq(x1-x2) + sq(y1-y2);
        if(sq(r1+r2)>dsq && sq(r1-r2)<dsq)
            cout << 2;
        else if(dsq==0 && r1==r2) cout << -1;
        else if(sq(r1+r2)==dsq || sq(r1-r2)==dsq) cout << 1;
        else cout << 0;
        cout << endl;
    }
}
#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

inline int sq(int x){
    return x*x;
}
bool isIn(int x, int y, int cx, int cy, int r){
    return sq(x-cx)+sq(y-cy) < r*r;
}
int main(){
    int T; cin >> T;

    while(T--){
        int x1, x2, y1, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        int n;
        cin >> n;
        vi cx(n), cy(n), r(n);
        for(int i=0; i<n; i++){
            scanf("%d %d %d", &cx[i], &cy[i], &r[i]);
        }
        int cnt = 0;
        for(int i=0; i<n; i++){
            if(isIn(x1, y1, cx[i], cy[i], r[i]) xor isIn(x2, y2, cx[i], cy[i], r[i]))
                cnt++;
        }
        cout << cnt << endl;
    }
}
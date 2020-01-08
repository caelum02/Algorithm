#include <bits/stdc++.h>
using namespace std;

struct crd{int x, y;};
long long int ccw(crd p1, crd p2, crd p3){
    return (p1.x*p2.y+p2.x*p3.y+p3.x*p1.y)-(p1.y*p2.x+p2.y*p3.x+p3.y*p1.x);
    // if(cp>0) return 1;
    // else if(cp==0) return 0;
    // else return -1;
}

int main(){
    crd p[4];
    
    for(int i=0; i<4; i++)
        scanf("%d %d", &p[i].x, &p[i].y);
    long long int c1 = ccw(p[0], p[1], p[2]), c2 = ccw(p[0], p[1], p[3]);

    if(c1*c2>=0) printf("0");
    else printf("1");
}
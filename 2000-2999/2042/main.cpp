#include <cstdio>
using namespace std;

typedef long long int lld;
int N, M, K;
lld tree[4000000], num[1000000];

void init(int node, int l, int r){
    if(l==r){
        tree[node] = num[l];
        return;
    }

    int m = (l + r)/2;
    init(node*2, l, m);
    init(node*2 + 1, m + 1, r);
    tree[node] = tree[node*2] + tree[node*2 + 1];
}

void update(int idx, lld delta, int l, int r, int node){
    if(!(l <= idx && idx <= r))
        return;

    tree[node] += delta;
    if(l==r) return;

    i nt m = (l + r)/2;
    update(idx, delta, l, m, node*2);
    update(idx, delta, m + 1, r, node*2 + 1);
}

lld query(int s, int e, int l, int r, int node){
    if(s <= l && r <= e) return tree[node];
    if(r < s || l > e) return 0;
    return (query(s, e, l, (l + r)/2, node*2) + query(s, e, (l + r)/2 + 1, r, node*2 + 1));
}

int main(){
    scanf("%d %d %d", &N, &M, &K);
    
    for(int i=1; i<=N; i++)
        scanf("%d", num + i);
    
    init(1, 1, N);
    int T = M + K, a, b, c;
    while(T--){
        scanf("%d %d %d", &a, &b, &c);
        if(a==1){
            update(b, c - num[b], 1, N, 1);
            num[b] = c;
        }
        if(a==2)
            printf("%lld\n", query(b, c, 1, N, 1));
    }
}
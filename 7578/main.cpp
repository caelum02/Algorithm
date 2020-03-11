#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef long long ll;

const int MAX_N=500100, MAX_H=1000100;
int N, hsh[MAX_H], ord[MAX_N];
ll tree[4*MAX_N];
void update(int s, int e, int n, int idx){
	if(idx<s || idx>e) return;
	tree[n]++;
	if(s==e) return;
	update(s, (s+e)/2, 2*n, idx);
	update((s+e)/2+1, e, 2*n+1, idx);
}
ll getSum(int s, int e, int n, int idx){ //n~N
	if(idx<=s && e<=N) return tree[n];
	if(e<idx || s>N) return 0;
	ll a=getSum(s, (s+e)/2, 2*n, idx),
		b=getSum((s+e)/2+1, e, 2*n+1, idx);
	return a+b;
}
int main(){
	scanf("%d", &N);
	int t;
	ll s=0;

	for(int i=1; i<=N; i++){
		scanf("%d", &t); hsh[t]=i;
	}
	for(int i=1; i<=N; i++){
		scanf("%d", &t); ord[hsh[t]]=i;
	}
	for(int i=1; i<=N; i++){
		s+=getSum(1, N, 1, ord[i]+1);
		update(1, N, 1, ord[i]);
	}
	cout << s;
}


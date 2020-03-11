#include <bits/stdc++.h>
using namespace std;

const int MAX_N=200000;
int M, N, mat[3][MAX_N];
struct p2{
	int a, b;
	bool operator <(const p2 &o){
		return a < o.a;
	}
};
struct p3{
	int a, b, c;
	bool operator <(const p3 &o){
		return a < o.a;
	}
};
void sub3(){
	vector<p3> v(N);
	for(int i=0; i<N; i++)
		scanf("%d", &v[i].a);
	for(int i=0; i<N; i++)
		scanf("%d", &v[i].b);
	for(int i=0; i<N; i++)
		scanf("%d", &v[i].c);
}
int query3(vector<int> )
int query2(vector<int> &tree, int s, int e, int n, int idx){
	// 0 ~ idx
	if(s>idx || e<0) return 0;
	if(0<=s && e <= idx) return tree[n];
	int m1=query2(tree, s, (s+e)/2, 2*n, idx),
		m2=query2(tree, (s+e)/2+1, e, 2*n+1, idx);
	return max(m1, m2);
}
void update2(vector<int> &tree, int s, int e, int n, int idx, int val){
	if(s>idx || e<idx) return;
	tree[n]=max(tree[n], val);
	if(s!=e){
		update2(tree, s, (s+e)/2, 2*n, idx, val);
		update2(tree, (s+e)/2+1, e, 2*n+1, idx, val);
	}
}
void sub2(){
	vector<p2> v(N);
	for(int i=0; i<N; i++)
		scanf("%d", &v[i].a);
	for(int i=0; i<N; i++)
		scanf("%d", &v[i].b);

	sort(v.begin(), v.end());

	vector<p2> seq(N);
	for(int i=0; i<N; i++)
		seq[i]=p2{v[i].b, i};

	sort(seq.begin(), seq.end());

	vector<int> st(1<<((int)ceil(log2(N))));
	for(int idx=0; idx<N; idx++){
		int tmp=query2(st, 0, N-1, 1, seq[idx].b);
		update2(st, 0, N-1, 1, seq[idx].b, tmp+1);
	}
	printf("%d", query2(st, 0, N-1, 1, N-1));
}
int main(){
	scanf("%d %d", &M, &N);	
	if(M==2) sub2();
	else sub3();
}

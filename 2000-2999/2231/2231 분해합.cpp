#include <bits/stdc++.h>
using namespace std;

inline int psum(int N){
	int ret = N;
	while(N>0){
		ret += N%10;
		N /= 10;
	}
	return ret;
}
int main(){
	int N;
	scanf("%d", &N);
	int i=0;
	for(i=max(N-54, 1); i<N; i++){
		if(psum(i)==N){
			cout << i; return 0;	
		}
	}
	cout << 0; return 0; 
}

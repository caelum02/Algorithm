#include <bits/stdc++.h>
#define x first
#define y second
#define inf 99999999
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
int N; pii b;

inline int ccw(pii p1, pii p2, pii p3){
	ll op = 1LL*(p2.x-p1.x)*(p3.y-p1.y)-1LL*(p3.x-p1.x)*(p2.y-p1.y);
	return (op>0 ? 1 : (op==0 ? 0 : -1));
}
int main(){
	pii p;
	scanf("%d %d %d", &N, &p.x, &p.y);
	vector<pii> v(N);
	for(int i=0; i<N; i++)
		scanf("%d %d", &v[i].x, &v[i].y); 
	
	int cnt=0;

	while(v.size()>2){
		sort(v.begin(), v.end());
		b = v[0];

		sort(v.begin()+1, v.end(),
			[](const pii &p1, const pii &p2){
				return ccw(b, p1, p2)>0;
			});

		vector<int> stk; int next=2, sz=2;
		stk.push_back(0); stk.push_back(1);
		while(next < v.size()){
			while(sz>=2){
				int first=stk[sz-1], second; sz--; stk.pop_back();
				second=stk[sz-1];
				if(ccw(v[second], v[first], v[next])>0){
					stk.push_back(first); sz++;
					break;
				}
			}	
			stk.push_back(next++); sz++;
		}
		
		int flag=ccw(p, v[stk[0]], v[stk[sz-1]]);
		for(int i=1; i<sz; i++){
			if(flag!=ccw(p, v[stk[i]], v[stk[i-1]])){
				cout << cnt; return 0;
			}
		}

		for(int i=sz-1; i>=0; i--)
			v.erase(v.begin()+stk[i]);
		
		cnt++;
	}
	cout << cnt;
}

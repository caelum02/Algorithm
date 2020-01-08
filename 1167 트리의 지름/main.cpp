#include <bits/stdc++.h>
using namespace std;

int V;
typedef pair<int, int> pii;
struct tri{int c, b, d;};

int main(){
	scanf("%d", &V);
	vector<pii> v[V+1];
	int idx, a, b;
	for(int i=0; i<V; i++){
		scanf("%d", &idx);
		while(1){
			scanf("%d", &a);
			if(a==-1) break;
			scanf("%d", &b);
			v[idx].push_back({a, b});
		}
	}

	queue<tri> q;
	int Md=0, Midx;

	q.push({1, -1, 0});
	while(!q.empty()){
		tri cur = q.front(); q.pop();
		int ci = cur.c, bf=cur.b, dst=cur.d;
		if(v[ci].size()==1 && dst > Md){
				Md=dst; Midx=ci;
		}
		for(int i=0; i<v[ci].size(); i++){
			if(v[ci][i].first==bf) continue;
			q.push({v[ci][i].first, ci, dst+v[ci][i].second});
		}
	}

	q.push({Midx, -1, 0}); Md=0;
	while(!q.empty()){
		tri cur = q.front(); q.pop();
		int ci = cur.c, bf=cur.b, dst=cur.d;
		
		if(v[ci].size()==1 && dst>Md)
			Md=dst;

		for(int i=0; i<v[ci].size(); i++){
			if(v[ci][i].first==bf) continue;
			q.push({v[ci][i].first, ci, dst+v[ci][i].second});
		}
	}
	cout << Md;
}

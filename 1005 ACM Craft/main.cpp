#include <bits/stdc++.h>
using namespace std;

int N, K, W, D[1001];

// topological sort

int main(){
	int T;
	scanf("%d", &T);
	while(T--){
		scanf("%d %d", &N, &K);
		vector<int> adj[N+1];

		for(int i=1; i<=N; i++)
			scanf("%d", D+i);
		
		int f, to;
		int in[1001] = {0,};

		while(K--){
			scanf("%d %d", &f, &to);
			adj[f].push_back(to);
			in[to]++;
		}

		scanf("%d", &W);
		vector<int> t(N+1, 0);

		queue<int> q;

		// 들어가는 간선 없는 노드 찾기
		for(int i=1; i<=N; i++)
			if(!in[i]){
				q.push(i);
				t[i] = D[i];
			}

		bool visited[1001] = {0,};
		bool isOver = false;
		while(!q.empty()){
			int h = q.front(); q.pop();
			if(visited[h]++) continue;
			for(int i : adj[h]){
				t[i] = max(t[i], t[h] + D[i]);
				if(!--in[i]){
					if(i==W){
						printf("%d\n", t[i]);
						isOver = true;
						break;
					}
					q.push(i);
				}
			}
			if(isOver) break;
		}
	}
	return 0;
}

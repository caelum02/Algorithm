#include <bits/stdc++.h>
using namespace std;

int main(){
	int h[9], sum=0;

	for(int i=0; i<9; i++){
		scanf("%d", h+i);
		sum += h[i];
	}
	sort(h, h+9);

	int delta = sum - 100;

	for(int i=0; i<9; i++)
		for(int j=i+1; j<9; j++){
			if(h[i]+h[j]==delta){
				for(int k=0; k<9; k++){
					if(k!=i && k!=j)
						printf("%d\n", h[k]);
				}
				return 0;
			}
		}
}

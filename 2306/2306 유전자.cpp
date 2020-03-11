#include <cstdio>
#include <string.h>

using namespace std;

char DNA[501];
short dp[500][500];

inline short max(short a, short b){
	return a>b?a:b;
}
int main(){

	scanf("%s", DNA);
	int len = strlen(DNA);

	for(int j=1; j<len; j++){
		for(int i=j-1; i>=0; i--){
			if((DNA[i]=='a' && DNA[j]=='t')	|| (DNA[i]=='g' && DNA[j]=='c'))
				dp[i][j] = dp[i+1][j-1] + 2;
			for(int k=j+1; i+k<=j; k++){
				dp[i][j] = max(dp[i][i+k]+dp[i+k+1][j], dp[i][j]);
			}
		}
	}
	
	printf("%d", dp[0][len-1]);
}

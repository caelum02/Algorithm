#include <bits/stdc++.h>
using namespace std;

typedef long long int lld;

int N, K;
int E[15], l[15];
int powK[54];
string s[15];
lld DP[1<<15][100];

lld dp(int used, int r){
    if(DP[used][r]!=-1) return DP[used][r];
    if(used==(1<<N)-1) return DP[used][r]=(r?0LL:1LL);
    lld &ref=DP[used][r]=0;
    for(int i=0; i<N; i++){
        if(!((1<<i)&used)){
            ref += dp(used | (1<<i), 
                (E[i]+powK[l[i]]*r)%K);
        }
    }

    return ref;
}
lld gcd(lld a, lld b){
    if(b>a) swap(a,b);
    lld tmp;
    while(b>0){
        tmp = a%b;
        a = b;
        b = tmp;
    }
    return a;
}
int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    memset(DP, -1, sizeof(DP));

    cin >> N;
    for(int i=0; i<N; i++){
        cin >> s[i];
        l[i]=s[i].length(); 
    }
    cin >> K;

    powK[0]=1%K;
    for(int i=1; i<54; i++)
        powK[i]=(powK[i-1]*10)%K;

    for(int i=0; i<N; i++){
        E[i]=0;
        for(int j=0; j<l[i]; j++)
            E[i] = (E[i] + powK[j]*(s[i][l[i]-1-j]-'0')) % K;
    }

    lld p=dp(0,0);
    lld q = 1; for(int i=2; i<=N; i++) q*=i;

    if(p==0) cout << "0/1" << endl;
    else if(p==q) cout << "1/1" << endl;
    else{
        lld g=gcd(p, q);
        cout << p/g << "/" << q/g << endl;
    }
}

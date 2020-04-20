#include <bits/stdc++.h>
using namespace std;

typedef long long int lld;

int N, K;
int E[15], l[15];
int powK[54];
string s[15];
lld DP[1<<15][100];

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

    DP[(1<<N)-1][0]=1;
    for(int used=(1<<N)-2; used>=0; used--)
        for(int r=0; r<K; r++){
            DP[used][r]=0;
            for(int i=0; i<N; i++)
                if(!((1<<i)&used)) DP[used][r] += DP[used | (1<<i)][(E[i]+powK[l[i]]*r)%K];
        }

    lld p=DP[0][0];
    lld q = 1; for(int i=2; i<=N; i++) q*=i;


    if(p==0) cout << "0/1" << endl;
    else if(p==q) cout << "1/1" << endl;
    else{
        lld g=gcd(p, q);
        cout << p/g << "/" << q/g << endl;
    }
}

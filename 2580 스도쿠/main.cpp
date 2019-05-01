#include <bits/stdc++.h>
using namespace std;

int brd[81], col[9][10], row[9][10], box[9][10];

int b(int p){
    return (3*(p/27) + p%9/3);
}

void output(){
    for(int p=0; p<81; p++){
        if(!(p%9)) printf("\n");
        printf("%d ", brd[p]);
    }
    printf("\n");
}

void preProcess(){
    for(int p=0; p<81; p++){
        scanf("%d", brd + p); 
        if(brd[p])  col[p%9][brd[p]] = row[p/9][brd[p]] = box[b(p)][brd[p]] = true;
    }
}

void DFS(int p, int n){
    int tmp[81], tmpc[];
    copy(brd, brd + 81, tmp);

    
    brd[p] = n



    copy(tmp, tmp + 81, brd);
}

int main(){
    preProcess();
    
    output();
}
#include<iostream>
#include<algorithm>
using namespace std;

int rat[4] = {4,6,2,4};
int gcd(int p,int q){
    if(q>p) swap(p,q);
    if(q==0) return p;
    return gcd(q,p%q);
}
void portion(int lis[]){
    int a = gcd(rat[0],rat[1]);
    for(int i=2;i<4;i++){
        a = gcd(a,rat[i]);
    }
    int temp[4] = {0};
    for(int i=0;i<4;i++){
        temp[i] = rat[i]/a;
        rat[i] = rat[i]/a;
    }
    while(1){
        int cor=0;
        for(int i=0;i<4;i++){
            if(rat[i]>=lis[i]) cor++;
        }
        if(cor==4) break;
        for(int i=0;i<4;i++){
            rat[i] += temp[i];
        }

    }
    for(int i=0;i<4;i++){
        lis[i] = rat[i]-lis[i];
    }
    for(int i=0;i<4;i++){
        cout<<lis[i]<<" ";
    }
    return ;
}

int main(){
    int lis[4] = {7,4,2,4};
    portion(lis);
    return 0;
}

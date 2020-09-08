#include<iostream>

using namespace std;
int price[5]={25,30,40,50,100};
int want[5] = {7,9,10,12,20};
int cache[10001]={0};
/*int sushi(int wa,int money){
    if(money<2500) return wa;
    int& ret = cache[money];
    if(ret!=0) return ret;
    for(int i=0;i<6;i++){
        if(money>=price[i]){
            ret = max(ret,sushi(wa+want[i],money-price[i]));
        }
    }
    return ret;
}*/
int c[201]={0};
/*
int sushi2(){
    int ret=0;
    for(int budget=1;budget<=10000;budget++){
        c[budget] = 0;
        for(int dish=0;dish<5;dish++)
            if(budget>=price[dish])
                c[budget] = max(c[budget],c[budget-price[dish]]+want[dish]);
        ret = max(ret,c[budget]);
    }
    return ret;
}
*/

int main(){
    cout<<sushi2();
    return 0;
}

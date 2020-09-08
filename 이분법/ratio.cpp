#include<iostream>

using namespace std;

int needgames(int n,int m){
    int rt= 100*double(m)/n;

    int lo=0;
    int hi=100000000;
    int mid;
    if(rt+1>int(100*double(m+100000000)/(n+100000000))) return -1;
    for(int it=0;it<100;it++){
        mid = (lo+hi)/2;
        if(rt+1<=int(100*double(m+mid)/(n+mid))) hi = mid;
        else lo = mid;
    }
    return hi;

}

int main(){
    cout<<needgames(1000000000,470000000);

    return 0;
}

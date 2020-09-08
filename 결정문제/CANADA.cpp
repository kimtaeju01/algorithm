#include<iostream>
#include<algorithm>
using namespace std;
int city[3][3] = {{500,100,10},{504,16,4},{510,60,6}};
bool desicion(double x,int k){
    int p = 0;
    int min1 = city[0][0]-city[0][1];
    int min2 = city[1][0]-city[1][1];
    int min3 = city[2][0]-city[2][1];
    for(int i = min1;i<=x;i=i+city[0][2]){
        if(i<=x) p++;
        else break;
    }
    for(int i = min2;i<=x;i=i+city[1][2]){
        if(i<=x) p++;
        else break;
    }
    for(int i = min3;i<=x;i=i+city[2][2]){
        if(i<=x) p++;
        else break;
    }
    if(p>=k) return true;
    else return false;
}
int optimize(int k){
    double mid=0;
    double lo = 0;
    double hi = 510;
    for(int it=0;it<100;it++){
        mid = (lo+hi)/2;

        if(desicion(mid,k)) hi=mid;
        else lo = mid;
    }
    return hi;
}
int main(){
    cout<<optimize(15);
    return 0;
}

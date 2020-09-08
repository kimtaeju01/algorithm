#include<iostream>

using namespace std;

double pos[3][3]={{0.18,0.40,0.42},{0.15,0.46,0.39},{0.58,0.23,0.19}};
int time[3]={4,4,2};
double cache[3][6] = {{-1,-1,-1,-1,-1,-1},{-1,-1,-1,-1,-1,-1},{-1,-1,-1,-1,-1,-1}};
double genius(double k,int n){
    if(k<time[0]){
        if(n==0) return 1;
        else return 0;
    }
    int times = k;
    double& ret = cache[n][times];
    if(ret!=-1) return ret;
    ret=0;
    for(int j=0;j<3;j++){
        ret = ret+pos[j][n]*genius(k-time[j],j);
    }
    return ret;
}

int main(){
    cout<<genius(6.5,1);
    return 0;
}

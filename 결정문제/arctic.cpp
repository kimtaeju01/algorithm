#include<iostream>

using namespace std;
double cord[6][2] = {{1.0,1.0},{30.91,8.0},{4.0,7.64},{21.12,6.0},{11.39,3.0},{5.31,11.0}};
bool desicion(double d){
    int pos[6] = {0};
    pos[0] = 1;
    for(int i=0;i<5;i++){
        double x = cord[i][0];
        double y = cord[i][1];
        for(int j=0;j<6;j++){
            if(pos[j]==0&&j!=i)
                if((x-cord[j][0])*(x-cord[j][0])+(y-cord[j][1])*(y-cord[j][1])<=d*d)
                    pos[j]=1;
        }
    }
    for(int i=0;i<6;i++)
        if(pos[i]==0) return false;
    return true;
}
double optimize(){
    double lo=0;
    double hi = 100;
    for(int it=0;it<100;it++){
        double mid=(lo+hi)/2;
        if(desicion(mid)){
            hi=mid;
        }
        else lo = mid;
    }
    return lo;
}
int main(){
    cout<<optimize();

    return 0;
}

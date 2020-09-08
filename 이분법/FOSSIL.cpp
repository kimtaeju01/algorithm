#include<iostream>
#include<math.h>
using namespace std;

double cor1[5][2] = {{35.74,35.85},{69.64,50.0},{73.52,82.55},{43.5,92.22},{17.67,76.18}};

double cor2[5][2] = {{16.47,8.02},{60.98,14.62},{66.80,37.74},{45.89,67.22},{13.04,55.19}};

double cal1(int idx,double x){
    double y = (cor1[idx%5][1]-cor1[(idx+1)%5][1])/(cor1[idx%5][0]-cor1[(idx+1)%5][0])*(x-cor1[idx%5][0])+cor1[idx%5][1];
    return y;
}
double cal2(int idx,double x){
    double y = (cor2[idx%5][1]-cor2[(idx+1)%5][1])/(cor2[idx%5][0]-cor2[(idx+1)%5][0])*(x-cor2[idx%5][0])+cor2[idx%5][1];
    return y;
}
double inc(double x){
    int a1[2] = {-1,-1};
    int a2[2] = {-1,-1};
    int pos1=0;
    int pos2=0;
    for(int i=0;i<5;i++){
        if(((cor1[i%5][0]<x)&&(cor1[(i+1)%5][0]>x))||(((cor1[i%5][0]>x)&&(cor1[(i+1)%5][0]<x)))){
            a1[pos1] = i;
            pos1++;
        }
        if((cor2[i%5][0]<x&&cor2[(i+1)%5][0]>x)||((cor2[i%5][0]>x&&cor2[(i+1)%5][0]<x))){
            a2[pos2] = i;
            pos2++;
        }
    }
    cout<<"x:"<<x<<endl;
    if(pos1*pos2!=4) return -1;

    cout<<"a1: "<<a1[0]<<a1[1]<<endl;
    cout<<"a2: "<<a2[0]<<a2[1]<<endl;
    double temp1 = cal1(a1[0],x);
    double temp2 = cal1(a1[1],x);
    double temp3 = cal2(a2[0],x);
    double temp4 = cal2(a2[1],x);
    if((max(temp1,temp2)<min(temp3,temp4))||(min(temp1,temp2)>max(temp3,temp4))) return -1;
    if(max(temp1,temp2)>min(temp3,temp4)&&min(temp1,temp2)<=min(temp3,temp4)){
        return max(temp1,temp2)-min(temp3,temp4);
        }
    else if(max(temp3,temp4)>min(temp1,temp2)&&min(temp3,temp4)<=min(temp1,temp2)){
             return max(temp3,temp4)-min(temp1,temp2);
             }
    return min(fabs(temp1-temp2),fabs(temp3-temp4));
}
double opt(){
    double lo = 0;
    double hi = 100;
    for(int it=0;it<100;it++){

        if(inc((2*lo+hi)/3)<inc((lo+hi*2)/3)){
            lo = (2*lo+hi)/3;}
        else hi = (lo+hi*2)/3;
    }
    return (lo+hi)/2;
}
int main(){
    cout<<opt();
return 0;}

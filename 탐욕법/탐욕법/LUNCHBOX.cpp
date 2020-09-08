#include<iostream>

using namespace std;
int m[3]={1,2,3};
int e[]={1,2,1};
int eaten[3] = {-1,-1,-1};
int lunchbox(){
    int time=0;
    for(int i=0;i<2;i++){
        for(int j=i+1;j<3;j++){
            if(e[i]<e[j]){
                swap(e[i],e[j]);
                swap(m[i],m[j]);
            }
        }
    }
    for(int i=0;i<3;i++){
        time += m[i];
    }
    time += e[2];
    return time;
}

int heat(){
    vector<pair<int,int>> order;
    for(int i=0;i<3;i++)
        order.push_back(make_pair(-e[i],i));
    sort(order.begin(),order.end());
    int ret=0, begineat=0;
    for(int i=0;i<3;i++){
        int box = order[i].second;
        begineat += m[box];
        ret = max(ret,begineat+e[box]);
    }
    return ret;
}

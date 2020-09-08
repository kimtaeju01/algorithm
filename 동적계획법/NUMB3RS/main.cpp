#include <iostream>

using namespace std;
double cache[8][3] = {0};
int connected[8] = {0};
int path[8][8]={{0,1,1,1,0,0,0,0},
                {1,0,0,1,0,0,0,0},
                {1,0,0,1,0,0,0,0},
                {1,1,1,0,1,1,0,0},
                {0,0,0,1,0,0,1,1},
                {0,0,0,1,0,0,0,1},
                {0,0,0,0,1,0,0,0},
                {0,0,0,0,1,1,0,0},};
double numb3rs(int day,int cur){
    if(day==0){
        if(cur==3) return 1;
        else return 0;
    }
    double& ret = cache[cur][day];
    if(ret!=-1) return ret;
    ret = 0;
    for(int i=0;i<8;i++){
        if(path[cur][i]==1){
            ret += numb3rs(day-1,i)/connected[i];
        }
    }
    return ret;
}
int main()
{
    for(int i=0;i<8;i++){
        for(int j=0;j<3;j++){
            cache[i][j]=-1;
        }
    }
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(path[i][j]==1) connected[i]++;
        }
    }
    cout<<numb3rs(2,3);
    return 0;
}

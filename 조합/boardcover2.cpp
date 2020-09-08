#include<iostream>
#include<vector>
using namespace std;
const int coverType[8][4][2]={{{0,0},{1,0},{0,1},{0,2}},{{0,0},{0,1},{1,1},{2,1}},{{0,0},{1,0},{1,1},{1,2}},{{0,0},{1,0},{1,-1},{1,-2}}
                            ,{{0,0},{1,0},{2,0},{0,1}},{{0,0},{0,1},{0,2},{1,2}},{{0,0},{1,0},{2,0},{2,1}},{{0,0},{1,0},{2,0},{2,-1}}};

bool set(int temp[][7],int y,int x,int type,int delta){
    bool ok = true;
    for(int i=0;i<4;i++){
        const int ny = y+coverType[type][i][0];
        const int nx = x+coverType[type][i][1];
        if(ny<0 || ny >= 4 || nx>=7 || nx < 0){
            ok = false;
            break;
        }
        else if(temp[ny][nx]+=delta>1){
            ok = false;
            break;
        }
    }
    return ok;
}
int maximum=0;
int cover(int temp[][7],int many){
    int y=-1,x=-1;

    cout<<"ha"<<endl;
    for(int i=0;i<4;i++){
        if(x!=-1) break;
        for(int j=0;j<7;j++)
        if(temp[i][j]==0){
            y=i;
            x=j;
    }
    }
    if(y==-1){
        maximum = max(maximum,many);
        return maximum;
    }
    for(int i=0;i<8;i++){
        if(set(temp,y,x,i,1)){
            many = many+1;
            cover(temp,many);
        }
    }
    maximum = max(many,maximum);
    return maximum;
}

int main(){
    int temp[4][7] = {{1,1,0,1,1,0,0},{1,0,0,0,0,0,0},{1,0,0,0,0,1,1},{1,0,0,1,1,1,1}};
    cout<<cover(temp,0);
    return 0;
}

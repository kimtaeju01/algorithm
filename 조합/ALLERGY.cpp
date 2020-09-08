#include<iostream>

using namespace std;

int info[10][7] = {{1,1,1,0,0,0,0},
                   {0,0,0,1,1,1,1},
                   {1,0,1,0,1,0,1},
                   {1,1,0,1,0,0,0},
                   {0,0,0,0,0,1,0},
                   {0,0,1,0,1,0,0},
                   {0,0,1,1,0,1,1},
                   {1,0,1,0,1,0,1},
                   {1,1,1,0,1,0,1},
                   {1,0,1,0,0,1,0}};
int best=100;
int allergy(int choice[],int start){
    choice[start]=1;
    int pos[10] = {0};
    int temp=0;
    for(int i=0;i<7;i++){
        temp+=choice[i];
    }
    if(temp>best){
        choice[start]=0;
        return 0;
    }
    for(int i=0;i<7;i++){
        if(choice[i]==1){
            for(int j=0;j<10;j++){
                pos[j] += info[j][i];
            }
        }
    }
    int ret=1;
    for(int i=0;i<10;i++){
        if(pos[i]==0){
            ret=0;
            break;
        }
    }
    if(ret==1){
        int total=0;
        for(int i=0;i<7;i++) total+=choice[i];
        best = min(best,total);
    }
    for(int next=start+1;next<7;next++){
        allergy(choice,next);
    }
    choice[start] = 0;
}

int n,m;
void search(vector<int>& edible, int chosen){
    if(chosen>=best) return;
    int first=0;
    while(first<n && edible[first]>0) ++first;

    if(first==n) {best=chosen; return;}
    for(int i=0;i<canEat[first].size();i++){
        int food = canEat[first][i];
        for(int j=0;j<eaters[food].size();j++)
            edible[eaters[food][j]]++;
        search(edible,chosen+1);
        for(int j=0;j<eaters[food].size();j++)
            edible[eaters[food][j]]--;
    }
    }
int main(){

    return 0;
}

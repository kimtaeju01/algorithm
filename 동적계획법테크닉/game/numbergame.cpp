#include<iostream>
using namespace std;
int board[]={-1000,-1000,-3,-1000,-1000};
int cache[5][5]={0};
int play(int left,int right){
    if(left>right) return 0;
    int& ret = cache[right][left];
    if(ret!=0) return ret;
    ret = max(board[left]-play(left+1,right),board[right]-play(left,right-1));
    if(right-left>=1){
        ret = max(ret,-play(left+2,right));
        ret = max(ret,-play(left,right-2));
    }
    return ret;
}

int main(){
    cout<<play(0,4);
    return 0;
}

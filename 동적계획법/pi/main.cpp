#include <iostream>

using namespace std;
/*
int cache[8] = {0};
int cal(int arr[],int start,int len){
    int same=0;
    int i=0;
    for(i=start;i<start+len-1;i++){
        if(arr[i]!=arr[i+1]){
            same=1;
            break;
        }
    }
    if(same==0) return 1;
    int up=0;
    int down=0;
    for(i=start;i<start+len-1;i++){
        if(arr[i]+1!=arr[i+1]){
            up=1;
            break;
        }
    }
    if(up==0) return 2;
    for(i=start;i<start+len-1;i++){
        if(arr[i]-1!=arr[i+1]){
            down=1;
            break;
        }
    }
    if(down==0) return 2;
    int t=0;
    for(i=start;i<start+len-2;i++){
        if(arr[i]!=arr[i+2]){
            t=1;
            break;
        }
    }
    if(t==0) return 4;
    int score=0;
    int gap = arr[start]-arr[start+1];
    for(i=start;i<start+len-1;i++){
        if(gap!=arr[i]-arr[i+1]){
            score=1;
            break;
        }
    }
    if(score==0) return 5;
    return 10;

}
int pi(int arr[],int start){
    if(start>7) return 0;
    if(start>=3){
        int score = cal(arr,start,8-start);
        return score;
    }
    int& ret = cache[start];
    if(ret!=0) return ret;
    ret = min(cal(arr,start,3)+pi(arr,start+3),cal(arr,start,4)+pi(arr,start+4));
    ret = min(ret,cal(arr,start,5)+pi(arr,start+5));
    return ret;
}*/
int quantization(int arr[])
int main()
{
    int arr[8]={2,2,2,2,2,2,2,2};
    cout<<pi(arr,0);
    return 0;
}

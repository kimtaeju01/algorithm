#include <iostream>
#include <list>
using namespace std;
/*int b[30][30] = {0};
int bino(int n, int r){
    if(r==0||n==r) return 1;
    if(b[n][r]!=0) return b[n][r];
    return b[n][r] = bino(n-1,r-1) + bino(n-1,r);
}
int n=7;
int board[7][7];
int cache[7][7];
int jumpgame(int y,int x){
    if(y>=n||x>=n) return 0;
    if(y==n-1&&x==n-1) return 1;
    int& ret = cache[y][x];
    if(ret!=-1) return ret;
    int jumpsize = board[y][x];
    return ret = (jumpgame(y+jumpsize,x)||jumpgame(y,x+jumpsize));
}
int cache[5][5] = {0};
int arr[5][5] = {{7,0,0,0,0},{3,8,0,0,0},{8,1,1,0,0},{2,7,4,4,0},{4,5,2,6,5}};
int triangle(int x,int y){
    if(y==4) return arr[y][x];
    int& ret = cache[y][x];
    if(ret!=0) return ret;
    return ret = max(triangle(x+1,y+1),triangle(x,y+1))+arr[y][x];
}*/
/*
int lis(list<int> i){
    if(i.empty()) return 0;
    list<int> temp;
    for(list<int>::iterator a = i.begin();a!=i.end();a++){
        if(*a>*(i.begin())) temp.push_back(*a);
    }
    return 1+lis(temp);
}
*/
/*
int arr[5] = {-1,-1,-1,-1,-1};
list<int> origin;
int mlis(list<int> i,int num){
    if(i.empty()) return 0;
    if(arr[num]!=-1) return 1+arr[num];
    list<int> temp;
    for(list<int>::iterator a = i.begin();a!=i.end();a++){
        if(*a>*(i.begin())) temp.push_back(*a);
    }
    int k=0;
    list<int>::iterator start = origin.begin();
    int j=0;
    for(j=0;j<5;j++){
        if(*start==temp.front()){
            k=j;
            break;
        }
        else start++;
    }
    return arr[num] = 1+mlis(temp,k);
}*/
/*
int n=5;
int cache[5]={-1,-1,-1,-1,-1};
int S[5] = {1,3,2,4,5};
int lis2(int start){
    int& ret = cache[start];
    if(ret!=-1) return ret;
    ret = 1;
    for(int next=start+1;next<n;++next){
        if(S[start]<S[next])
            ret = max(ret,lis2(next)+1);
    }
    return ret;
}*/
const int INF = 987654321;
int n=9;
int arr[9]={1,1,1,2,2,2,3,3,3};
int cal(int s,int f){
    int a=f+1-s;
    int b=0;
    for(int i=s;i<f+1;i++){
        b=b+arr[i];
    }
    int ans = b/a;

    int hap1=0;
    for(int i=s;i<f+1;i++){
        hap1 += (arr[i]-ans)*(arr[i]-ans);
    }
    int hap2=0;
    for(int i=s;i<f+1;i++){
        hap2 += (arr[i]-(ans+1))*(arr[i]-(ans+1));
    }
    return min(hap1,hap2);
}
int cache[9][3]={{-1,-1,-1},{-1,-1,-1},{-1,-1,-1},{-1,-1,-1},{-1,-1,-1},{-1,-1,-1},{-1,-1,-1},{-1,-1,-1},{-1,-1,-1}};
int quantize(int from,int parts){
    if(from==n) return 0;
    if(parts==0) return INF;
    int& ret = cache[from][parts];
    if(ret!=-1) return ret;
    ret = INF;
    for(int partSize = 1;from+partSize<=n;partSize++){
        ret = min(ret,cal(from,from+partSize-1)+quantize(from+partSize,parts-1));
    }
    return ret;
}
int main()
{
    cout<<quantize(0,3)<<endl;

    return 0;
}

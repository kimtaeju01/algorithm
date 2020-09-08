#include <iostream>
#include<string>
using namespace std;
/*
int cache1[4][4] = {0};
int cache2[4][4] = {0};
int triangle[4][4] = {{9,0,0,0},{5,7,0,0},{1,3,2,0},{3,5,5,6}};
int change(int y,int x){
    if(y==3){
        cache1[y][x] = triangle[y][x];
        return triangle[y][x];}
    int& ret = cache1[y][x];
    if(ret!=0) return ret;
    return ret = triangle[y][x]+max(change(y+1,x),change(y+1,x+1));
}
int findpath(int y,int x){
    if(y==3) return 1;
    int& ret = cache2[y][x];
    if(ret!=0) return ret;
    int num = cache1[y][x]-triangle[y][x];
    if(num==cache1[y+1][x]&&num==cache1[y+1][x+1]){
        return ret = findpath(y+1,x) + findpath(y+1,x+1);
    }
    if(num==cache1[y+1][x]) return ret = findpath(y+1,x);
    return ret = findpath(y+1,x+1);
}*/
/*
int n,m;
int cache[m][2*m+1];
int climb(int days,int climbed){
    if(days==m) return climbed >=n ? 1:0;
    int& ret = cache[days][climbed];
    if(ret!=-1) return ret;
    return ret = climb(days+1,climbed+1)+climb(days+1,climbed+2);
}
*/
int cache1[101];
int cache2[101];
const int MOD = 1000000007;
int tiling(int width){
    if(width<=1) return 1;
    int& ret = cache1[width];
    if(ret!=-1) return ret;
    return ret = (tiling(width-1)+tiling(width-2))%MOD;
}
int asymtiling(int width){
    if(width%2==0) return tiling(width/2)+tiling(width/2-1);
    return tiling((width-1)/2);
}
int asymtiling2(int width){
    if(width<=2) return 0;
    int& ret = cache2[width];
    if(ret!=-1) return ret;
    ret = asymtiling2(width-2)%MOD;
    ret = (ret+asymtiling2(width-4))%MOD;
    ret = (ret+tiling(width-3))%MOD;
    ret = (ret+tiling(width-3))%MOD;
    return ret;
}
int main()
{
    for(int i=0;i<101;i++){
        cache1[i] = -1;
        cache2[i] = -1;
    }
    cout<<asymtiling2(92);
    return 0;
}

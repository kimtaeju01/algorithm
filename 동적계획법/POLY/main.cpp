#include <iostream>

using namespace std;
const int MOD = 10*1000*1000;
int cache[101][101];
int poly(int n,int first){
    if(first==n) return 1;
    int& ret = cache[n][first];
    if(ret!=-1) return ret;
    ret = 0;
    for(int second=1;second<=n-first;second++){
        int add = second + first -1;
        add = add*poly(n-first,second);
        ret += add;
    }
    return ret;
}
int main()
{
    for(int i=0;i<101;i++){
        for(int j=0;j<101;j++) cache[i][j] = -1;
    }
    int total=0;
    for(int i=1;i<=4;i++){
        total += poly(4,i);
    }
    cout<<total;
    return 0;
}

#include <iostream>

using namespace std;
int n=3;
int cache[3]={-1,-1,-1};
int S1[3] = {1,2,3};
int S2[3] = {4,5,6};
/*
int lis2(int start){
    int& ret = cache[start];
    if(ret!=-1) return ret;
    ret = 1;
    for(int next=start+1;next<n;++next){
        if(S[start]<S[next])
            ret = max(ret,lis2(next)+1);
    }
    return ret;
}
*/
int jlis(int start){
    int& ret = cache[start];
    if(ret!=-1) return ret;
    ret = 1;
    int maximum = S1[start];
    for(int i=0;i<3;i++){
        if(maximum<S2[i]){
            ret++;
            maximum = S2[i];
        }
    }
    for(int next=start+1;next<n;next++){
        if(S1[start]<S1[next]){
            ret = max(ret,jlis(next)+1);
        }
    }
    return ret;
}
int main()
{
    int maxlen = 0;
    for(int i=0;i<5;i++){
        maxlen = max(maxlen,jlis(i));
    }
    cout<<maxlen<<endl;
    return 0;
}

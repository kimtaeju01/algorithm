#include <iostream>
using namespace std;
/*
int n;
int cache[101],s[100],choices[101];
int lis4(int start){
    int& ret = cache[start+1];
    if(ret!=-1) return ret;
    ret=1;
    int bestNext=-1;
    for(int next=start+1;next<n;next++){
        if(start==-1 || s[start]<s[next]){
            int cand = lis4(next)+1;
            if(cand>ret){
                ret = cand;
                bestNext = next;
            }
        }
    }
    choices[start+1] = bestNext;
    return ret;
}
void reconstruct(int start,vector<int>& seq){
    if(start!=-1) seq.push_back(s[start]);
    int next = choices[start+1];
    if(next!=-1) reconstruct(next,seq);
} */
int weightlist[6] = {4,2,6,4,2,10};
int wantlist[6] = {7,10,6,7,5,4};
int cache1[6]={-1,-1,-1,-1,-1,-1};
int cache2[6]={-1,-1,-1,-1,-1,-1};
int packing(int start,int weight){
    weight = weight+weightlist[start];
    if(weight>17) return 0;
    if(start>=6) return 0;
    int& ret= cache1[start];
    if(ret!=-1) return ret;
    ret = wantlist[start];
    for(int i=start+1;i<6;i++){
        if(weight+weightlist[i]<=17){
            if(ret<(wantlist[start]+packing(i,weight))){
                cache2[i] = 0;
                ret = wantlist[start]+packing(i,weight);
            }
        }
    }
    return ret;
}
int main()
{
    cout<<packing(0,0)<<endl;
    for(int i=0;i<6;i++){
        cout<<cache2[i]<<endl;
    }
    return 0;
}

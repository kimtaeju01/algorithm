#include<iostream>
#include<list>
#include<math.h>
#include<algorithm>
using namespace std;

int n=8;
int cache1[8]={-1,-1,-1,-1,-1,-1,-1,-1};
int cache[8]={-1,-1,-1,-1,-1,-1,-1,-1};
int S[8]={5,1,6,4,3,2,8,7};
int LIS(int start){
    if(start>=8) return 0;
    int& ret=cache1[start];
    if(ret!=-1) return ret;
    ret = 1;
    for(int next=start+1;next<8;next++){
        if(S[start]<S[next]){
            if (ret<1+LIS(next)){
                ret = 1+LIS(next);
            }
        }
    }
    return ret;
}

int count(int start){
    if(LIS(start)==1) return 1;
    int& ret = cache[start+1];
    if(ret!=-1) return ret;
    ret = 0;
    for(int next=start+1;next<n;next++){
        if(S[next]>S[start]&&LIS(start)==LIS(next)+1){
            ret = ret+count(next);
        }
    }
    return ret;
}
void reconstruct(int start,int skip,vector<int>& lis){
    if(start!=-1) lis.push_back(S[start]);
    vector<pair<int,int>> followers;
    for(int next=start+1;next<n;next++){
        if(S[next]>S[start]&&LIS(start)==LIS(next)+1){
            followers.push_back(ff));
        }
    }
    sort(followers.begin(),followers.end());
    for(int i=0;i<followers.size();i++){
        int idx=followers[i].second;
        int cnt = count(idx);
        if(cnt<=skip) skip-=cnt;
        else {reconstruct(idx,skip,lis);
            break;
        }
    }
}

int main(){

    return 0;
}

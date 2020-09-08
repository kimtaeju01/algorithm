#include<iostream>
#include <vector>
using namespace std;
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

int n,capacity;
int volume[100],need[100];
int cache[1001][100];
string name[100];

int pack(int capacity,int item){
    if(item==n)return 0;
    int& ret=cache[capacity][item];
    if(ret!=-1) return ret;
    ret = pack(capacity,item+1);
    if(capacity>=volume[item])
        ret = max(ret,pack(capacity-volume[item],item+1)+need[item]);
    return ret
}
void reconstruct(int capacity,int item,vector<string>& picked){
    if(item==n) return;
    if(pack(capacity,item)==pack(capacity,item+1)) reconstruct(capacity,item+1,picked);
    else{
        picked.push(name[item]);
        reconstruct(capacity-volume[item],item+1,picked);
    }
}

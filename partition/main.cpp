#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> partion(int arr[])
{
    vector<int> ret(6);
    ret[0] = arr[0]%4;
    for(int i=1;i<6;i++)
        ret[i] = (arr[i]+ret[i-1])%4;
    return ret;
}
int cache[6] = {-1,-1,-1,-1,-1,-1};
int santa1(int arr[]){
    vector<int> psum = partion(arr);
    vector<int> temp = psum;
    sort(temp.begin(),temp.end());
    int ret1=0;
    for(vector<int>::iterator a = temp.begin();a!=temp.end();a++){
        int total = 1;
        while(1){
            if(*a==*(a+1)){
                total++;
                a++;
            }
            else break;
        }
        ret1 += (total*(total-1))/2;
    }
    return ret1;
}
int santa2(vector<int> psum,int num){
    if(num>5) return 0;
    int& ret = cache[num];
    if(ret!=-1) return ret;
    ret = 0;
    if(find(psum.begin()+num+1,psum.end(),psum[num])!=psum.end()) ret = 1;
    if(psum[num]==0){
        ret=santa2(psum,num+1)+1;
    }
    else{
    for(int i=num+1;i<6;i++){
        int temp = psum[i];
        int j=i;
        for(j=i;j<6;j++){
            if(temp==psum[j]) break;
        }
        if(j!=6) ret = max(ret,santa2(psum,j+1)+1);
    }}
    return ret;
}
int main()
{
    int arr[] = {4,4,4,4,4,4};
    cout<<santa1(arr)<<endl;
    vector<int> psum = partion(arr);
    cout<<santa2(psum,0)<<endl;
}

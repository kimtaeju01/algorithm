#include<iostream>
#include<math.h>
#include<vector>
using namespace std;
int minFactor[2000001];
void eratosthenes2(){
    minFactor[0] =minFactor[1] = -1;
    for(int i=2;i<2000001;i++) minFactor[i] = i;
    int sqrtn = int(sqrt(2000000));
    for(int i=2;i<=sqrtn;i++){
        if(minFactor[i]==i){
            for(int j=i*i;j<=2000000;j+=i){
                if(minFactor[j]==j)
                    minFactor[j] = i;
            }
        }
    }
}

vector<int> factor(int n){
    vector<int> ret;
    while(n>1){
        ret.push_back(minFactor[n]);
        n = n/minFactor[n];
    }
    return ret;
}
int pass486(int lo,int hi,int cor){
    vector<int> temp;
    int ret=0;
    for(int i=lo;i<=hi;i++){
        temp = factor(i);
        int num=1;
        for(vector<int>::size_type j=0;j<temp.size();j++){
            int a = temp[j];
            int num2=0;
            while(a==temp[j]&&j<temp.size()){
                num2++;
                j++;
            }
            if(i==6)
            cout<<a<<" "<<num2<<endl;
            num = num*(num2+1);
        }
        if(cor==num){
            ret++;
        }
    }
    return ret;
}
int main(){
    eratosthenes2();
    pass486(2,10,2);
}

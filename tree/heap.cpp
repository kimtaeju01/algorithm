#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> inse(vector<int> lis,int num){
    lis.push_back(num);
    int pos = lis.size()-1;
    while(1){
        if(lis[pos]>lis[(pos-1)/2]){
            swap(lis[pos],lis[(pos-1)/2]);
            if(pos%2==0){
                if(lis[pos-1]<lis[pos]){
                    swap(lis[pos-1],lis[pos]);
                    if(lis[pos-1]>lis[pos/2])
                        swap(lis[pos-1],lis[pos/2]);
                }

            }
            pos = (pos-1)/2;

            if(pos%2!=0){
                if(lis[pos]<lis[pos+1]){
                    int temp2 = lis[pos];
                    lis[pos] = lis[pos+1];
                    lis[pos+1] = temp2;
                }
            }
            else if(pos>1){
                if(lis[pos]<lis[pos-1]){
                    int temp2 = lis[pos];
                    lis[pos] = lis[pos-1];
                    lis[pos-1] = temp2;
                }
            }
        }
        else{
            if(pos%2==0){
                if(lis[pos-1]<lis[pos]){
                    swap(lis[pos-1],lis[pos]);
                    pos--;
                }
            }
            int root = (pos-1)/2;
            if(root%2!=0){
                if(lis[root+1]<lis[pos]){
                    swap(lis[root+1],lis[pos]);
                }
            }
            break;
        }
    }
    return lis;
}
int main(){
    int numl[]={4,6,1,3,7,2,5};
    vector<int> lis;
    lis.push_back(4);
    for(int i=1;i<7;i++){
        lis = inse(lis,numl[i]);
        for(vector<int>::iterator a=lis.begin();a!=lis.end();a++)
            cout<<*a<<" ";
        cout<<""<<endl;
    }
}

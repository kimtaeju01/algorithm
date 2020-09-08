#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int strjoin(){
    int ret=0;
    vector<int> str;
    str.push_back(3);
    str.push_back(1);
    str.push_back(3);
    str.push_back(4);
    str.push_back(1);
    sort(str.begin(),str.end());
    int value=0;
    while(str.size()>1){
        value = str[0]+str[1];
        ret+=value;
        str.erase(str.begin());
        str.erase(str.begin());
        str.push_back(value);
        sort(str.begin(),str.end());
    }
    return ret;
}

int main(){
    cout<<strjoin();
    return 0;
}

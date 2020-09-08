#include <iostream>
#include <string>
using namespace std;
bool wildcard(string pattern, string example,int num,int num2){
    int pos = pattern.find('*',num);
    if(pattern.find('*',num)!=-1){
    if(pos==num){
        if(pos==pattern.length()-1) return true;
        else return wildcard(pattern,example,num+1,num2);
    }
    else{
        string temp("");
        for(int i=num;i<pos;i++){
            temp += pattern[i];
        }
        if(example.find(temp,num2)!=-1){
            num2 = num2+example.find(temp,num2);
            return wildcard(pattern,example,num+1,num2);
        }
        else return false;
    }
    }
    else{
        string temp("");
        for(int i=num;i<pattern.length();i++){
            temp += pattern[i];
        }
         for(int j=0;j<temp.length();j++){
            if(temp[temp.length()-1-j]!=example[example.length()-1-j]) return false;
         }
        return true;
    }
}
int main()
{
    string pattern = "***************a";
    string example = "aaaaaaaaaaaaaab";
    cout<<wildcard(pattern,example,0,0);


    return 0;
}

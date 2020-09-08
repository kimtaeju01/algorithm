#include<iostream>
#include<string>
using namespace std;
/*
string finds(string s,int cur_n,int n){
    if(cur_n==n) return s;
    for(int i=0;i<s.length();i++){
        if(s.at(i)=='X'){
            s.replace(i,1,"X+YF");
            i=i+4;
        }
        else if(s.at(i)=='Y'){
            s.replace(i,1,"FX-Y");
            i=i+4;
        }
    }
    return finds(s,cur_n+1,n);
}
void curve(const string& seed, int gen){
    if(gen==0){
        cout<<seed;
        return ;
    }
    for(int i=0;i<seed.size();i++){
        if(seed[i]=='X') curve("X+YF",gen-1);
        if(seed[i]=='Y') curve("FX-Y",gen-1);
        else cout<<seed[i];
    }
}
*/
char expand(const string& dragonCurve,int generations,int skip){
    if(generations==0){
        assert(skip<dragonCurve.size());
        return dragonCurve[skip];
    }
    for(int i=0;i<dragonCurve.size();i++){
        if(dragonCurve[i]=='X'||dragonCurve[i]=='Y'){
            if(skip>=length[generations]) skip=skip-length[generations];
            else if(dragonCurve[i]=='X')
                return expand(EXPAND_X,generations-1,skip);
            else
                return expand(EXPAND_Y,generations-1,skip);
        }
        else if(skip>0){
            skip--;
        }
        else
            return dragonCurve[i];
    }
}
int main(){
    string s("FX");
    for(int i=0;i<5;i++){
        curve(s,i);
        string s("FX");
    }
    return 0;
}

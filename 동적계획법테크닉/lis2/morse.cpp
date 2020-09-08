#include <iostream>
using namespace std;

void generate1(int n,int m,string s){
    if(n==0&&m==0){
        cout<<s<<endl;
        return;
    }
    if(n>0) generate1(n-1,m,s+'-');
    if(m>0) generate1(n,m-1,s+'o');
}
int skip=4;
void generate2(int n,int m,string s){
    if(skip<1) return ;
    if(n==0&&m==0){
        if(skip==1){
            cout<<s<<endl;
            skip--;
            return;
        }
        else skip--;
    }
    if(n>0) generate2(n-1,m,s+'-');
    if(m>0) generate2(n,m-1,s+'o');
}
int bino[10][10]={0};

void calcBino(){
    for(int i=0;i<10;i++){
        bino[i][0] = bino[i][i]=1;
        for(int j=1;j<i;j++){
            bino[i][j] = bino[i-1][j]+bino[i-1][j-1];
        }
    }
}
void generate3(int n,int m,string s){
    if(skip<0) return ;
    if(n==0&&m==0){
        if(skip==0) cout<<s<<endl;
        skip--;
        return ;
    }
    if(skip>=bino[n+m][n]){
        skip = skip-bino[n+m][n];
        return ;
    }
    if(n>0) generate3(n-1,m,s+'-');
    if(m>0) generate3(n,m-1,s+'o');
}

int main(){
    string s;
    calcBino();
    generate3(2,2,s);
    return 0;
}

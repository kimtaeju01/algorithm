#include<stdio.h>

void permute(int list[],int l, int r){
    if(l==r){
        for(int j=0;j<3;j++){
            printf("%d ",list[j]);
        }
        printf("\n");
    }
    else{
        for(int i=l;i<r;i++){
            sw(list,i,l);
            permute(list,l+1,r);
            sw(list,i,l);
        }
    }
}

void sw(int list[],int i, int j){
    int temp = list[i];
    list[i] = list[j];
    list[j] = temp;
}
int main(){
    int list[3]={1,2,3};
    permute(list,0,3);
    return 0;
}

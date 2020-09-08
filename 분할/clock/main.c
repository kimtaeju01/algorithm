#include <stdio.h>
#include <stdlib.h>
int sc[10][6]={{1,2,3,4,5,-1},{3,7,9,11,-1},{4,10,14,15,-1},{0,4,5,6,7,-1},{6,7,8,10,12,-1},{0,2,14,15,-1},{3,14,15,-1},{4,5,7,14,15,-1},{0,1,2,-1},{3,4,5,9,13,-1}};
int list[10] = {0};
int finish(int hour[]){
    int i=0;
    int a=0;
    for(i=0;i<16;i++){
        if(hour[i]!=12){
            a=1;
        }
    }
    if(a==1) return 0;
    else return 1;
}
void change(int hour[], int list[]){
    printf("\n");
    int i=0;
    for(i=0;i<10;i++){
        if(list[i]==0) break;
        if(list[i]%4==0){
            int k=0;
            for(int j=0;j<4;j++){
            while(sc[i][k]>=0){
                hour[sc[i][k]] = (hour[sc[i][k]]+3)%12;
                if(hour[sc[i][k]]==0) hour[sc[i][k]]=12;
                k++;
            }}
        }
        else{
            for(int j=0;j<list[i]%4;j++){
                int k=0;
                while(sc[i][k]>=0){
                hour[sc[i][k]] = (hour[sc[i][k]]+3)%12;
                if(hour[sc[i][k]]==0) hour[sc[i][k]]=12;
                k++;
            }
            }
        }
    }
    for(int a=0;a<16;a++) printf("%d ",hour[a]);
}
void changelist(int list[],int num){
    if(num==9) return ;
    else{
    if(list[num]>0&&list[num]%4==0){
        list[num+1] = list[num+1]+1;
        list[num] = 0;
        changelist(list,num+1);
    }
    }
}
int find(int hour[],int list[]){
    int total=0;
    int temphour[16] = {0};
    for(int k=0;k<16;k++){
        temphour[k] = hour[k];
    }
    for(int i=0;i<10;i++){
        total = total+list[i];
    }
    change(temphour,list);
    if(finish(temphour)==1){
        return total;
    }
    else if (total==30) return -1;
    else{
        list[0] +=1;
        changelist(list,0);
        find(hour,list);
    }
}
int main()
{
    int hour[16] = {12,6,6,6,6,6,12,12,12,12,12,12,12,12,12,12};
    printf("%d",find(hour,list));
}

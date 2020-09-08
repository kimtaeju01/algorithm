#include<iostream>

using namespace std;
int board[5][5]={{0,0,0,0,0},
                 {0,1,1,0,0},
                 {1,1,0,0,1},
                 {1,0,1,1,1},
                 {0,0,1,0,0}};
int check(int board[][5]){//check the game.
    int pos=-1;
    for(int j=0;j<4;j++){
        if((board[0][j]+board[0][j+1]==0)||(board[4][j]+board[4][j+1]==0)||(board[0][j]+board[1][j]==0)){
            return 1;
        }
        if((board[j][0]+board[j+1][0]==0)||(board[j][4]+board[j+1][4]==0)||(board[j][0]+board[j][1]==0)){
            return 1;
        }
    }
    for(int i=1;i<4;i++){
        for(int j=1;j<4;j++){
            if((board[i][j]+board[i][j+1]==0)||(board[i][j]+board[i+1][j+1]==0)){
            return 1;
        }
        }
    }
    return pos;
}
void precalc(){
        for(int j=0;j<4;j++){
        if((board[0][j]+board[0][j+1]==0)||(board[4][j]+board[4][j+1]==0)||(board[0][j]+board[1][j]==0)){
            i=make_pair(0,j)
        }
        if((board[j][0]+board[j+1][0]==0)||(board[j][4]+board[j+1][4]==0)||(board[j][0]+board[j][1]==0)){

        }
    }
    for(int i=1;i<4;i++){
        for(int j=1;j<4;j++){
            if((board[i][j]+board[i][j+1]==0)||(board[i][j]+board[i+1][j+1]==0)){

        }
        }
    }
    }
    return;
}
int blockgame(int board[][5]){
    if(check(board)==-1) return -1;

}

int main(){

    return 0;
}

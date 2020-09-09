#include <iostream>

using namespace std;

int r[4][4] = {{0,0,0,0},{1,0,0,0},{1,1,0,1},{0,0,0,0}};    //���� ���� ����
int c[4][4] = {{1,1,1,1},{1,1,1,1},{1,1,0,1},{1,1,1,1}}; //�б⿡ ���� ����
int INF = 987654321;
int n = 4;                   //���������
int m = 4;                   //�����ϴ� ���� ��
int k = 4;                   //�б� ��
int l = 4;                   //�� �б⿡ ���� �� �ִ� �ִ� ���� ��
int bitCount(int n);
int graduate(int semester, int taken) {
    if(bitCount(taken) >= k) return 0;
    if(semester == m) return INF;

    int& ret = cache[semester][taken];
    if(ret != -1) return ret;
    ret = INF;
    int canTake = (classes[semester] & ~taken); //���� �� �ִ� ���� ��

    for(int i=0;i<n;i++){
        if((canTake&(1<<i))&&(taken&prerequisite[i])!= prerequisite[i]) canTake &= ~(1<<i);
    }
    for(int take = canTake;take>0;take=((take-1)&canTake)){
        if(bitCount(take)>l) continue;
        ret = min(ret, graduate(semester+1, taken|take)+1);
    }
    ret = min(ret, graduate(semester+1,taken));
    return ret;
}

int main()
{
    int status[4] = {0, 0, 0, 0};
    cout << graduation(0, status);
    return 0;
}

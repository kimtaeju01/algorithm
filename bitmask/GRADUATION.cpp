#include <iostream>

using namespace std;

int r[4] = {0, 1, 11, 0};    //과목에 대한 정보
int c[4] = {15, 15, 11, 15}; //학기에 대한 정보
int n = 4;                   //전공과목수
int m = 4;                   //들어야하는 과목 수
int k = 4;                   //학기 수
int l = 4;                   //한 학기에 들을 수 있는 최대 과목 수
int cache[4] = {0};

int main()
{
    int fin[4] = {0, 0, 0, 0};
    cout << graduation(0, fin);
    return 0;
}

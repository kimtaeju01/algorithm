#include <iostream>
#include <vector>
#include <stack>
using namespace std;
//swiping algorithm
//������ ������ ����� ��, ���� ���� ������ ���� ������ ���� �������� �� ��.
vector<int> h; // �� ������ ����

int solveStack(){
    int ret = 0;
    stack<int> remaining; // �����ִ� ������ ����
    h.push_back(0);
    for(int i=0;i<h.size();i++){
        while(!remaining.empty()&&h[remaining.top()]>=h[i]){
            int j = remaining.top();
            remaining.pop();
            int width = -1;
            if(remaining.empty())
                width = i;
            else
                width = i-remaining.top()-1;
            ret = max(ret, h[j]*width);
        }
        remaining.push(i);
    }
    return ret;
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}

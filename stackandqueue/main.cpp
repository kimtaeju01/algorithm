#include <iostream>
#include <vector>
#include <stack>
using namespace std;
//swiping algorithm
//끝나는 조건을 고려할 때, 새로 들어온 것으로 인해 기존의 것이 끝나는지 볼 것.
vector<int> h; // 각 판자의 높이

int solveStack(){
    int ret = 0;
    stack<int> remaining; // 남아있는 판자의 높이
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

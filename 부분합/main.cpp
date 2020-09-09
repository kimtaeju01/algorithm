#include <iostream>

using namespace std;
int gift[] = {0,1,2,3,4};
int psum[] = {0,0,0,0,0};
int cache[] = {-1,-1,-1,-1,-1};
//return value: how many cases if start
int maxcase(int start){
    if(start>=5) return 0;
    int& ret = cache[start];
    if(ret!=-1) return ret;
    ret = 0;
    for(int i=start+1;i<5;i++){
        if(psum[i]==psum[start]){
            ret = max(ret,1+maxcase(i));
        }
        ret = max(ret,maxcase(i));
    }
    return ret;
}
int main()
{
    cout << maxcase(0) << endl;
    for(int i=0;i<5;i++){
        cout << cache[i]<<endl;
    } //3 2 1 0 0 0
    return 0;
}

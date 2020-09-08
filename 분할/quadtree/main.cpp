#include <iostream>
#include <string>
using namespace std;


string r(string::iterator& it){
    cout<<"start"<<endl;
    char head = *it;
    ++it;
    if(head=='b'||head=='w')
        return string(1,head);
    cout<<*it<<endl;
    string ul = r(it);
    cout<<*it<<endl;
    string ur = r(it);
    cout<<*it<<endl;
    string dl = r(it);
    cout<<*it<<endl;
    string dr = r(it);
    return string("x") + dl + dr + ul + ur;
}

int main()
{
    string::iterator it = string("xbwxwbbwb").begin();
    cout<<r(it);
}

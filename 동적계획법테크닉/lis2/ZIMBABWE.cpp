#include<iostream>
#include<string>
using namespace std;
string lis[3]={"oji","jing","geo"};
string cache[3] = {"","",""};
string add(string s1, string s2) {
	string value("");
	if(s1.find(s2)<s1.length()&&s1.find(s2)>=0) return s1;
	value = s1 + s2;
	for (int i = s1.length() - 2; i >= 0; i--) {
		string temp("");
		for (int j = 0; j <= i; j++) temp = temp + s1.at(j);
		string temp2 = temp + s2;
		if (temp2.find(s1) == 0) value = temp2;
	}
	return value;
}
string restore(string lis[],int num){
    if(num==2) {
        return lis[2];
    }
    string& ret = cache[num];
    if(ret!="") return ret;
    ret = lis[num];
    for(int i=num+1;i<3;i++){
        if(add(restore(lis,i),ret).length()> add(ret,restore(lis,i)).length()) ret = add(ret,restore(lis,i));
        else ret = add(restore(lis,i),ret);
    }
    return ret;
}
int main() {
	cout<<restore(lis,0)<<endl;
	return 0;
}

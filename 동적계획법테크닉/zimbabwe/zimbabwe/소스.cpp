#include<iostream>
#include<string>
using namespace std;

string restore(string s1, string s2) {
	string value("");
	value = s1 + s2;
	for (int i = s1.length() - 2; i >= 0; i++) {
		string temp("");
		for (int j = 0; j <= i; j++) temp = temp + s1.at(j);
		string temp2 = temp + s2;
		if (temp2.find(s1) == 0) value = temp2;
	}
	return value;
}

int main() {
	cout << restore("geo", "oji");
	return 0;
}
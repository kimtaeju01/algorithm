#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


bool decision(double x){
    vector<double> v;
    for(int i=0;i<n;i++){
        v.push_back(x*c[i]-r[i]);
    }
    sort(v.begin(),v.end());
    double sum=0;
    for(int i = n-k;i<n;i++)
        sum+=v[i];
    return sum>=0;
}

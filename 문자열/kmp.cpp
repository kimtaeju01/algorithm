#include<iostream>
#include<vector>
#include<string>
vector<int> kmpSearch(const string& H,const string& N){

    int begin=0;
    int n = H.size();
    int m = N.size();
    int matched=0;
    vector<int> ret;
    vector<int> pi = getPi(N);
    while(begin<=n-m){
        if(H[begin+matched]==N[matched]){
            matched++;
            if(matched==m) ret.push_back(begin);
        }
        else{
            if(matched==0) begin++;
            else{
                begin = begin+matched-pi[matched-1]
                matched = pi[matched-1];
            }
        }
    }
    return ret;
}
vector<int> getPi(const string& N){
    vector<int> pi(N.size(),0);
    int begin=1,matched=0;

    while(begin+matched<N.size()){
        if(N[begin+matched]==N[matched]){
            ++matched;
            pi[begin+matched-1] = matched;
        }
        else{
            if(matched==0) begin++;
            else{
                begin += matched-pi[matched-1];
                matched = pi[matched-1];
            }
        }
    }
    return pi;
}

int shifts(const string& original,const string& target,int dir) {
    if(dir==1)
    return original.size()-kmpSearch(original+original,target)[0];
    else if(dir==-1)
        return kmpSearch(original+original,target)[0];
}
    int m = N.size();
    vector<int> pi(m,0);

    int begin=1,matched=0;
    while(begin+matched<m){
        if(N[begin+matched]==N[matched]){
            ++matched;
            pi[begin+matched-1] = matched;
        }
        else{
            if(matched==0) begin++;
            else{
                begin += matched-pi[matched-1];
                matched = pi[matched-1];
            }
        }
    }
}
shifts

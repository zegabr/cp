#include<vector>
#include<iostream>
void readvec(std::vector<int>& v, int sz){
    v.resize(sz);
    for(int &a : v) std::cin >> a;
}

void printvec(std::vector<int> &v){
    for(int i = 0; i < (int)v.size(); i++){
        std::cout << v[i] << " \n"[i==v.size()-1];
    }
}

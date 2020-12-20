
void readvec(vector<int>& v, int sz){
    v.resize(sz);
    for(int &a : v) cin >> a;
}

void printvec(vector<int> &v){
    for(int i = 0; i < (int)v.size(); i++){
        cout << v[i] << " \n"[i==v.size()-1];
    }
}

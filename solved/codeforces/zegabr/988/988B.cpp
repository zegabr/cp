#include <bits/stdc++.h>
using namespace std;

struct compare {
    bool operator()(const std::string& first, const std::string& second) {
        return first.size() < second.size();
    }
};
compare c;
string a[100];
int n,k;
bool can;
int main(){
   cin>>n;
   for(int i=0;i<n;i++){
       cin>>a[i];
       
   }
    sort(a, a+n, c);
    can=true;
    for(int i=0;i<n-1 && can;i++){
        if(a[i+1].find(a[i]) == std::string::npos)//i is not subs de i+1
            can=false;
    }
    if(!can)
        cout<<"NO"<<endl;
    else{
        cout<<"YES"<<endl;
        for(int i=0;i<n;i++)
            cout<<a[i]<<endl;
       
   
    }



    return 0;
}
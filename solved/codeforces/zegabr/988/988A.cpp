#include <bits/stdc++.h>
using namespace std;
unordered_set <int> nums;
set <int> pos;

int n,k,i,elem;
int main(){
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>elem;
        if(nums.count(elem)==0 && nums.size() < k){//not inserted yet
            nums.insert(elem);
            pos.insert(i);
        }

    }
    if(pos.size()!=k){
        cout<<"NO"<<endl;
    }else{
         cout<<"YES"<<endl;
        for(auto it = pos.begin(); it != pos.end() ; it++){
            cout<<*it<<' ';
            
        }
    }




    return 0;
}
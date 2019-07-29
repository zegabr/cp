#include <bits/stdc++.h>
using namespace std;

#define pl '\n'
#define sp ' '
typedef long long ll;
typedef pair<ll,ll> pll;






priority_queue<int> maxhip;
int n,k;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    //cout<<fixed<<setprecision(10);
    cin>>n>>k;
    for(int i=0;i<32;i++){
      if((1<<i)&n){
       // cout<<(1<<i)<<sp;
        maxhip.push(1<<i);
      }
    }
    if(maxhip.size()>k){
      cout<<"NO"<<pl;
      return 0;
    }
    if(maxhip.size()==k){
      cout<<"YES"<<pl;
      while(maxhip.size()){
        cout<<maxhip.top()<<sp;
        maxhip.pop();
      }
     return 0;
    }
   while(maxhip.size()<k){
      int t=maxhip.top();
      if(t==1)break;
      maxhip.pop();
      maxhip.push(t/2);
      maxhip.push(t/2);
   }

    if(maxhip.size()==k){
      cout<<"YES"<<pl;
      while(maxhip.size()){
        cout<<maxhip.top()<<sp;
        maxhip.pop();
      }
     return 0;
    }

      cout<<"NO"<<pl;
      return 0;

}


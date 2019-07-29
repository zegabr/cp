#include <bits/stdc++.h>
#define pl '\n'
#define sp ' '
using namespace std;

int main(){
    string s1,s2;
    int ans=0;
    cin>>s1>>s2;
    if(s1.size()>s2.size()){
        swap(s1,s2);
    }
   int tam1=s1.size(), tam2=s2.size(),i;
   //cout<<tam1<<sp<<tam2<<pl;
   //tam1 is smaller
   set<int> div;
   int sqr=sqrt(tam2);
   for(i=1;i<=sqr;i++){//O(326)=sqrt(1e5)
       if(tam1%i==0){
           if(tam2%i==0){

            div.insert(i);
            if(tam2%(tam1/i)==0)div.insert(tam1/i);
           }
       }
   }
  //working
  string aux1,aux2;
  bool div1,div2;
  for(int d:div){//O(menos de 326)
 // cout<<d<<pl;
  div1=div2=false;
      aux1=s1.substr(0,d);
      aux2=s2.substr(0,d);
      
      if(aux1!=aux2) continue;
      
      
      aux2="";
      for(i=0;i<tam1/d;i++) aux2+=aux1;//O(tle)?
      div1= (s1==aux2);
      
      aux2="";
      for(i=0;i<tam2/d;i++) aux2+=aux1;//outra vez
      div2= (s2==aux2);

      ans+=(div1 and div2);
  }
  cout<<ans<<pl;

}
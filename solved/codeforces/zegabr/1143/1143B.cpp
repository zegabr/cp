#include <bits/stdc++.h>

using namespace std;

int getProd(string &s, int a){
   int resp = 1;
   for(int i=0; i<a; i++){
      resp *= ((s[i]-'0'));
   }
   if(s[0]=='0') resp = 1;
   return resp*(pow(9, s.length()-a));
}

int main(){
   string s;
   cin>>s;
   int maior = getProd(s, s.length());
   for(int i=s.length()-1; i>=0; i--){
      char at = s[i];
      if(s[i]=='0'){
                
      }else{
         s[i] = s[i]-1;
      }
      maior = max(maior, getProd(s, i+1));
      s[i] = at;
   }
   cout<<maior<<endl;
   
     return 0;
}
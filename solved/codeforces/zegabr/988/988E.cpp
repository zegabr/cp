#include <bits/stdc++.h>
using namespace std;


int dois,cinco,sete,zero1,zero2,dist,tam,inf = 1000*1000*1000;
int mind=inf;
string num;
int main(){
    cin>>num;
    tam=num.size();
    for(int k=0;k<tam;k++){//O(18)
        char c=num[k];
        if(c=='2') dois=k+1;
        else if(c=='5') cinco=k+1;
        else if(c=='7') sete =k+1;
        else if(c=='0') zero2 = k+1;
    }
    for(int k=0;k<tam;k++){//O(18)
        if(num[k]=='0' && k+1!=zero2) zero1=k+1;//second rightmost zero
    }
    //25
    if(dois&&cinco){
        dist=0;
        if((dois==1&&num[1]=='0') ||(cinco==1&&num[1]=='0')){
            for(int k=1;k<tam&&num[k]=='0';k++,dist++);
        }
        if(cinco<dois)
            dist++;
        dist+=tam-cinco+tam-1-dois;
        mind = min(dist,mind);
    //  cout<<dist<<endl;   
    }
    //75
    if(sete && cinco){
        dist=0;
        if((sete==1&&num[1]=='0') ||(cinco==1&&num[1]=='0')){
            for(int k=1;k<tam&&num[k]=='0';k++,dist++);
        }
        
        if(cinco<sete)
            dist++;
        dist+=tam-cinco+tam-1-sete;
        mind = min(dist,mind);
        //cout<<dist<<endl;
    }

    //50
    if(cinco && zero2){
        dist=0;
        if(zero2<cinco)
            dist++;
        dist+=tam-zero2+tam-1-cinco;
        mind = min(dist,mind);
        // cout<<dist<<endl;
    }
// cout<<endl;
    //00
    if(zero1&&zero2){
        dist=0;
        dist+=tam-zero2+tam-1-zero1;
        mind = min(dist,mind);
    }
    cout<<(mind<inf?mind:-1)<<endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
char pl = '\n',sp=' ';

int main(){
    int a,b;
    cin>>a>>b;
    if(a==b){
        cout<<"infinity"<<pl;
        return 0;
    }
    if(b>a){
        cout<<0<<pl;
        return 0;
    }
    int n = a-b,sol,p,c=0;
    //cout<<n<<pl;
    set<int> s;
    for(int sol=1;sol*sol<=n;sol++){//pega todos os divisores de n=a-b maiores que b
        if(n%sol==0){
            p=n/sol;
            if(p>b)s.insert(p);
            if(sol>b)s.insert(sol);
        }
    }
    
    cout<<s.size()<<pl;
}
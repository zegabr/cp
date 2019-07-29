#include <bits/stdc++.h>
using namespace std;


int m,n,fing[10],aux;
vector<int> arr;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>aux;
        arr.push_back(aux);
    }
    for(int i=0;i<m;i++){
        cin>>aux;
        fing[aux]=1;
    }
    for(int i=0;i<n;i++){
        if(fing[arr[i]]==1)
            cout<<arr[i]<<(i!=n-1  ? " " : "");
    }
    cout<<endl;
        

    return 0;
}



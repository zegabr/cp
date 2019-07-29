#include <bits/stdc++.h>
using namespace std;

unordered_map <unsigned long long,unsigned long long> strxpos,posxstr,coinxstr,respxpos;
vector <pair<int,int>> v;
int n,k,i;
unsigned long long sum;
pair <int,int> p;
priority_queue <int,vector<int>,greater<int>> qu;	
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
	cin>>n>>k;
	for(i=0;i<n;i++){
		cin>>strxpos[i];
		posxstr[strxpos[i]]=i;
	}
	for(i=0;i<n;i++){
		cin>>coinxstr[strxpos[i]];
		p = make_pair(strxpos[i],coinxstr[strxpos[i]]);
		v.push_back(p);
	}
	sort(v.begin(),v.end());//sort by power
	sum=0LL;
	
	for(i=0;i<n;i++){
		respxpos[posxstr[v[i].first]]=v[i].second+sum;
		
		if(k){
		
			if(qu.size()<k){
				qu.push(v[i].second);
				sum+=(unsigned long long)v[i].second;
			}else{
				if(v[i].second>qu.top()){
					sum-=(unsigned long long)qu.top();
					qu.pop();
					sum+=(unsigned long long)v[i].second;
					qu.push(v[i].second);
			
				}
		
			}
		}
		
	}
	for(i=0;i<n;i++){
		cout<<respxpos[i]<<(i<n-1 ? " ":"");
	}

    return 0;
}



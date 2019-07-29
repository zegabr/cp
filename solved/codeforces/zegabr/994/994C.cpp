#include <bits/stdc++.h>
using namespace std;
//two squares
double a1,a2,b1,b2,a3,b3;
vector <pair<double,double>> q1,q2;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
	cin>>a1>>b1;
	q1.push_back({a1,b1});
	for(int i=0;i<3;i++){
		cin>>a3>>b3;
		if(a3!=a1) a2=a3;
		if(b3!=b1) b2=b3;
		q1.push_back({a3,b3});
	}
	q1.push_back({(a1+a2)/2,(b1+b2)/2});//centro de q1
	if(a1>a2)swap(a1,a2);
	if(b1>b2)swap(b1,b2);
	
	for(int i = 0;i<4;i++){
		cin>>a3>>b3;
		if(a3>=a1&&a3<=a2&&b3>=b1&&b3<=b2){
			cout<<"YES\n"; return 0;
		}
		q2.push_back({a3,b3});
	}
	//centro de q2
	a3=(q2[0].first+q2[2].first)/2; 
	b3=(q2[0].second+q2[2].second)/2;
	if(a3>=a1&&a3<=a2&&b3>=b1&&b3<=b2){
			cout<<"YES\n"; return 0;
	}
	q2.push_back({a3,b3});
	//q2 n tem pontos em q1
	
	//mudar de base
	for(int i=0;i<5;i++ ){
		a3=q1[i].first;
		b3=q1[i].second;
		q1[i]={(a3+b3)/sqrt(2),(b3-a3)/sqrt(2)};
		
		a3=q2[i].first;
		b3=q2[i].second;
		q2[i]={(a3+b3)/sqrt(2),(b3-a3)/sqrt(2)};
	}	
	sort(q2.begin(),q2.begin()+4);
	a1=q2[0].first; a2=q2[2].first;
	b1=q2[0].second; b2=q2[1].second;
	if(a1>a2)swap(a1,a2);
	if(b1>b2)swap(b1,b2);
	
	for(int i=0;i<5;i++){
		a3=q1[i].first;
		b3=q1[i].second;
		if(a3>=a1&&a3<=a2&&b3>=b1&&b3<=b2){
			cout<<"YES\n"; return 0;
		}
	}

	
	cout<<"NO\n";
}



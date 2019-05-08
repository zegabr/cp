#include<bits/stdc++.h>
#define sp ' '
#define pl '\n'
using namespace std;
typedef long long ll;


int a[100][5][5];
int n;
typedef pair<int,int> ii;
priority_queue<ii,vector<ii>,greater<ii>> pq;

void testa(int c1, int c2){//testa se empatam e se alguma cartela empata antes
	bool rep=0;
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			set<int> s;//uniao entre 2 
			s.insert(a[c1][i], a[c1][i]+5);
			s.insert(a[c2][j], a[c2][j]+5);
			if(s.size()==10) continue;//linha i de c1 nao empata com linha j de c2
			rep=1;//linha i de c1 empata com linha j de c2 (possuem numeros em comum)
			for(int k=0;k<n;k++){//pra cada cartela difernte de c1 e c2
				if(k==c1 or k==c2)continue;
				for(int lin=0;lin<5;lin++){//pra cada linha
					bool allin=1;//supoe que todos tao na uniao das linhas de c1 e c2
					for(int col=0;col<5 and allin;col++){
						allin &= s.count(a[k][lin][col]);
					}
					if(allin){
						cout<<"no ties"<<pl;	
						exit(0);//outra linha ganha antes de c1 e c2 empatarem
					}
				}
			}
		}
	}
	if(rep) pq.push({c1,c2});
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	cin>>n;
	for(int i=0;i<n;i++)
		for(int j=0;j<5;j++)
			for(int k=0;k<5;k++)
				cin>>a[i][j][k];

	for(int c1=0;c1<n-1;c1++){
		for(int c2=c1+1;c2<n;c2++){
			testa(c1,c2);
		}
	}

	if(pq.empty()) cout<<"no ties\n";
	else cout<<pq.top().first+1<<sp<<pq.top().second+1<<pl;




}

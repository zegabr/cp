#include <bits/stdc++.h>
using namespace std;
char pl='\n', sp=' ';

queue <int> q;
unordered_map<int,int> m;
set<int> s;
int n,k,i,j,v,ansi,ansj;

int main(){
	//ios::sync_with_stdio(0);cin.tie(0);
	scanf("%d%d",&n,&k);
		//while(q.size())q.pop();
		//s.clear();m.clear();
		ansi=ansj=i=j=1;

		scanf("%d",&v);
		q.push(v);
		s.insert(v);
		m[v]++;
		n--;
		
		while(n--){
			scanf("%d",&v);
			if(m[v]){//ja existe pode add
				q.push(v);
				m[v]++;
				j++;
				if(j-i>ansj-ansi){ansi=i;ansj=j;}
			}else{
				//ver se pode add
				if(s.size()<k){
					q.push(v);
					s.insert(v);
					m[v]++;
					j++;
					if(j-i>ansj-ansi){ansi=i;ansj=j;}
				}else{//n possui v e size=k, logo n pode adicionar enquanto size nao for <k
					if(j-i>ansj-ansi){
						ansi=i;ansj=j;
					}
					while(s.size()==k){
						m[q.front()]--;
						if(m[q.front()]==0) s.erase(q.front());
						q.pop(); i++;
					}
					q.push(v);
					s.insert(v);
					m[v]++;
					j++;
					
				}
			}
		}
	
	printf("%d %d\n",ansi,ansj);

	
		

}
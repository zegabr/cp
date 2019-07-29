#include <bits/stdc++.h>
using namespace std;
char pl = '\n',sp=' ';
typedef long long ll;
typedef pair<int,int> pii;
int v[400005], st[400005],n,q,a,b;

inline int merge(bool isXor, const int &lhs, const int &rhs) {
	if(isXor) return lhs^rhs;
	return lhs|rhs;
}//ok

void build(bool isXor,int x = 1, int l = 0, int r = n - 1) {
    if(l == r) {
        st[x] = v[l];
    } else {
        int m = (l + r) / 2;
        build(!isXor,x + x, l, m);
        build(!isXor,x + x + 1, m + 1, r);
        st[x] = merge(isXor, st[x + x], st[x + x + 1]);
    }
}//ok

void modify(bool isXor, int a, int b, int x = 1, int l = 0, int r = n - 1) {
    if(r < a || l > a) {
        return ;
    }
    if(l == r) {
        st[x] = b;
        return;
    }
    int m = (l + r) / 2;
    modify(!isXor, a, b, x + x, l, m);
    modify(!isXor, a, b, x + x + 1, m + 1, r);
    st[x] = merge(isXor, st[x + x], st[x + x + 1]);
}//ok

int query(bool isXor, int a, int b, int x = 1, int l = 0, int r = n - 1) {
    if(r < a || l > b) {
        return 0; //a|0 == a^0 == a
    }
    if(a <= l && r <= b) {
        return st[x];
    }
    int m = (l + r) / 2;
    return merge(isXor, query(!isXor, a, b, x + x, l, m), query(!isXor, a, b, x + x + 1, m + 1, r));
}//ok

void printatree(){
	cout<<"[ ";
	for(int i=0;i<2*n-1;i++){
		cout<<st[i]<<sp;
	
	}
	cout<<st[2*n-1]<<"]"<<pl;

}



int main(){
    ios::sync_with_stdio(0); cin.tie(0);
	cin>>n>>q;
	bool isXor = !((n)&1);
	n=1<<n;
	for(int i=0;i<n;i++) cin>>v[i];
	build(isXor);
	//Sprintatree();
	while(q--){
		cin>>a>>b;
		modify(isXor,a-1,b);
		cout<<st[1]<<pl;
	
	
	}
	

}

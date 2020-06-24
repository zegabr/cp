
//=============stars and bars=======================
/*
   -n identical objects into k labeled boxes is comb(n+k-1,n)
   -equals combination with repetition of n+k-1, repeating n and k-1

*/

//================derrangements=======================
/*
   the number of ways to make an arrangment where no index is at its proper position is
   derr(n) = (n-1)*(derr(n-1)+derr(n-2))
   derr(0)=derr(1)=0

*/

const int ms=10000;
vector<vector<ll>> c;

void initcomb(){
    c.resize(ms+1,vector<ll>(ms/2+1,0));
}

ll comb(int n,int k){//combinacao de n, escolhendo k
    if(k==0 or k==n) return 1;
    k = min(k,n-k);
    if(c[n][k]) return c[n][k];
    return c[n][k] = comb(n-1,k-1)+comb(n-1,k);
}

void pascaltriangle(int n){
    for(int i=0;i<=n;i++){
        for(int j=0;j<=i;j++){
            cout<<comb(i,j)<<' ';
        }
        cout<<endl;
    }
}


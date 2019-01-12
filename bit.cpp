int bit[maxn];
int sum(int i){
    int res =0;
    while (i){
        res += bit[i];
        i-= i&-i;
    }
    return res;
}
void ad(int i,int val){
    while(i<n){//'n' eh o tamanho utilizado
        bit[i]+=val;
        i+= i&-i;
    }
}
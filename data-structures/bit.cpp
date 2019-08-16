//====================================================
const int ms = 21212414;
int bit[ms],n;
int sum(int i){//O(logn)
	int res =0;
	while (i){
		res += bit[i];
		i-= i&-i;
	}
	return res;
}

void ad(int i,int val){//O(logn)
	while(i<n){
		bit[i]+=val;
		i+= i&-i;
	}
}
//====================================================
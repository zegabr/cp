//////////BIT/////////
const int N = 21212414;
int bit[N],n;
int sum(int i){
	int res =0;
	while (i){
		res += bit[i];
		i-= i&-i;
	}
	return res;
}
void ad(int i,int val){
	while(i<n){
		bit[i]+=val;
		i+= i&-i;
	}
}

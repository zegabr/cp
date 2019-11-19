
const int ms = 21212414;
int bit[ms];
int get(int i){//O(logn)
	int res =0;
	while (i){
		res += bit[i];
		i-= i&-i;
	}
	return res;
}

int get(int i, int j){
	return get(j+1) - get(i);//here
}

void upd(int i,int val){//here
	while(i<ms-1){
		bit[i]+=val;
		i+= i&-i;
	}
}

void build(vector<int> &v){
	for(int i=0;i<v.size();i++)
		upd(i+1,v[i]);//here
}

//TODO: correct indexes and classify
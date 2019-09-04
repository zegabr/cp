void getint(int &num){
	num=0;
	bool neg=0;
	register int c = getchar_unlocked();
	if(c=='-'){
		neg=1;
		c=getchar_unlocked();
	}
	for(;c<='9' and c>='0';c=getchar_unlocked())
		num=(num<<1)+(num<<3)+c-'0';
	if(neg)num*=-1;
}
void getint(ll &num){
	num=0ll;
	bool neg=0;
	register int c = getchar_unlocked();
	if(c=='-'){
		neg=1;
		c=getchar_unlocked();
	}
	for(;c<='9' and c>='0';c=getchar_unlocked())
		num=(num<<1)+(num<<3)+c-'0';
	if(neg)num*=-1ll;
}

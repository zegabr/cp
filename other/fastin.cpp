#define getchar getchar_unlocked
void sc(int &num){//scan int
	num=0;
	bool neg=0;
	int c = getchar();
	while(c==' ')c=getchar();
	if(c=='-')neg=1,c=getchar();
	else if(c=='+') c=getchar();
	for(;c<='9' and c>='0';c=getchar())
		num=(num<<1)+(num<<3)+c-'0';
	if(neg)num*=-1;
}
void sc(ll &num){//scan ll
	num=0ll;
	bool neg=0;
	int c = getchar();
	while(c==' ')c=getchar();
	if(c=='-')neg=1,c=getchar();
	else if(c=='+') c=getchar();
	for(;c<='9' and c>='0';c=getchar())
		num=(num<<1)+(num<<3)+c-'0';
	if(neg)num*=-1ll;
}

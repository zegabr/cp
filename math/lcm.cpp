
long long gcd(long long a, long long b){
	if(b == 0) return a;
	return gcd(b, a % b);
}

long long lcm(const long long &a, const long long &b) {
	return (a / __gcd(a, b)) * b; 
}


long long lcm(const long long &a, const long long &b) {
	return (a / __gcd(a, b)) * b; 
}


inline long lcm(const long &a, const long &b) {
	return (a / __gcd(a, b)) * b; 
}

#include<iostream>
#include<vector>
#include<algorithms>
#include<complex>
using namespace std;
typedef long long ll;
typedef complex<ll> P;
#define X real()
#define Y imag()

long double distanceof2points(P &a, P &b){
	return abs(b-a);
}
long double anglebetween2points(P &a, P &b){
return 0;
}
ll Xproduct(P &a, P &b){
	return (conj(a)*b).Y;
}
int main(){
	
}

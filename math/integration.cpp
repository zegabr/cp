
double f(double x){
	return x;//function here
}
const int N = 1000000;//number of steps
double integral(double a, double b){//simpson integration
	double h = (b-a)/N;
	double s = f(a)+f(b);
	for (int i = 1; i <= N; i += 1){
		double x = a+h*i;
		s += f(x) * ((i & 1) ? 4 : 2);
	}
	s*=h/3.0;
	return s;
}	

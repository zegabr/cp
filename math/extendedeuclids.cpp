
// acha x e y da equacao:
// a * x + b * y = gcd(a, b) = d;
// x eh inverso modular de a no modulo y (se d == 1)
// y eh inverso modular de b no modulo x (se d == 1)
//long x,y,d;
void euclides(long a, long b, long &x, long &y, long &d) {
	if(b==0){x=1; y=0; d=a; return;}
	euclides(b, a % b, x, y, d);
	int x1 = y;
	int y1 = x - ( a / b ) * y;
	x = x1; y = y1;
}

/////positive solution
bool makePositive(long &x,long &y, long d, long a, long b){
	if(x<0){
		//x+ t*b/d >= 0 ==> t >= -x*d/b = -x/(b/d)
		long t = (-x + (b/d)-1)/(b/d);//ceil de -x/(b/d)
		x += b/d * t;
		y -= a/d * t;
	}

	if(y<0){
		//y+ t*a/d >= 0 ==> t >= -y*d/a = -y/(a/d)
		long t = (-y + (a/d)-1)/(a/d);//ceil de -y/(a/d)
		x -= b/d * t;
		y += a/d * t;
	}

	return x>=0 and y>=0;
}

//ax+by=k
int solve(long a, long b, long k, long &x, long &y, long &d){
	euclides(a,b,x,y,d);
	if(k%d!=0) return 0; // no solution at all
	x = k / d * x;
	y = k / d * y;
	if(makePositive(x,y,d,a,b)) return 2;//positive solution exists (comment this if any solution is good)
	return 1;//integer solution exists
}

void minimizeX(long a, long b, long &x, long &y, long &d){//for positive solution
	long t = x/(b/d);
	x-=b/d*t;
	y+=a/d*t;
}

void minimizeY(long a, long b, long &x, long &y, long &d){//for positive solution
	swap(a,b); swap(x,y);
	minimizeX(a,b,x,y,d);
	swap(a,b); swap(x,y);
}



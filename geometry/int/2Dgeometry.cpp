//2D GEOMETRY WITH COMPLEX 
#include<bits/stdc++.h>
#define pl '\n'
#define sp ' '
typedef long double ld;
#define eps 1e-9
struct P{
	double x,y;
	P() {x==y==0.0;}
	P(double _x, double _y) : x(_x), y(_y) {}
	double norm ()  {return hypot (x ,  y) ;  }
	P  normalized ()  {return P (x , y) ∗ (1.0/ norm () ) ;}
	double angle ()  {return atan2 (y ,  x) ;  
	double polarAngle ()  {
			double a = atan2 (y ,  x) ;
			return a < 0 ? a + 2∗acos (−1.0)  :  a ;
	}
	bool operator< ( P  other )const{
		if( fabs (x−other.x) > EPS)return x < other .x ;
			return y < other. y ;
		}
	bool operator== ( P  other )const{return( fabs (x−other . x) < EPS  and  ( fabs (y−other . y) < EPS) ) ;}
	P operator+(P  other )const{return P (x + other . x ,  y + other . y) ;}
		P operator−(P  other )const{return P (x−other . x ,  y−other . y) ;}
		Po perator∗(double k)const{return P (x∗k ,  y∗k) ;}
	};
	double dist ( P  p1 ,  P  p2 )  {return hypot ( p1 . x−p2 . x ,  p1 . y−p2 . y) ;}
	double inner ( P  p1 ,  P  p2 )  {returnp1 . x∗p2 . x + p1 . y∗p2 . y ;}
	double cross ( P  p1 ,  P  p2 )  {returnp1 . x∗p2 . y−p1 . y∗p2 . x ;}
	bool ccw ( P p ,  P q ,  P  r )  {return cross (q−p ,  r−p) > 0;}
	bool collinear ( P p ,  P q ,  P  r )  {return fabs ( cross (p−q ,  r−p) ) < EPS; }
	bool parallel ( P  a ,  P b)  {return fabs ( cross (a ,  b) ) < EPS;}
	double angle ( P  a ,  P  o ,  P b)  {return acos ( inner (a−o ,  b−o )  /  ( dist (o , a )∗dist (o , b) ) ) ;}
	P  rotate ( P p ,double rad )  {return P (p . x∗cos ( rad )−p . y∗sin ( rad ) ,p . x∗sin ( rad ) + p . y∗cos ( rad ) ) ;}
	P  proj ( P u ,  P  v)  {return v∗( inner (u , v) / inner (v , v) ) ;}
	bool between ( P p ,  P q ,  P  r )  {return collinear (p ,  q ,  r )  and  inner (p−q ,  r−q)<= 0;}

	P  lineIntersectSeg ( P p ,  P q ,  P A,P B)  {
		double c = cross (A−B,  p−q) ;
		double a = cross (A, B) ;
		double b = cross (p ,  q) ;
		return(( p−q)∗( a/c ) )−((A−B)∗(b/c ) ) ;
	}

	bool segIntersects ( P  a ,  P b ,  P p ,  Pq)  {
		if( parallel (a−b ,  p−q) )  {
			return between (a ,  p ,  b)   or   between (a ,  q ,  b) or   between (p ,  a ,  q)   or   between (p ,  b ,  q) ;
		}
		P  i = lineIntersectSeg (a ,  b ,  p ,  q) ;
		return between (a ,  i ,  b)  and  between (p ,  i ,  q) ;
	}

	P  closestToLineSegment ( P p ,  P  a ,  P b)  {
		double u = inner (p−a ,  b−a )  /  inner (b−a ,  b−a ) ;
		if(u < 0.0)return a ;
		if(u > 1.0)return b ;
		return a + (( b−a )∗u) ;
	}






	using namespace std;
	main(){
		ios::sync_with_stdio(0); cin.tie(0);
		int t;
		cin>>t;
		ld a,b,c,d;
		while(t--){
			struct	P p5,p6;
			cin>>a>>b>>c>>d;
			p5 = {a,b};
			p6 = {c,d};
			cin>>a>>b>>c>>d;
			struct		P p1,p2,p3,p4;
			p1={a,b};
			p2={c,b};
			p3={c,d};
			p4={a,d};

			bool ok = insiderectangle(p1,p3,p5) or insiderectangle(p1,p3,p6);

			ok |= doIntersect(p5,p6,p1,p2) or doIntersect(p5,p6,p2,p3) or doIntersect(p5,p6,p3,p4) or doIntersect(p5,p6,p4,p1);
			//		ok |= (p5 == p1 or p5 == p2 or p5 == p3 or p5 == p4 or p6==p1 or p6==p2 or p6==p3 or p6 == p4);

			if(ok)cout<<"T"<<pl;
			else cout<<'F'<<pl;


		}
	}

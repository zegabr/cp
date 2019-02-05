//2D geometry with complex
#include<complex>
#include<vector>
using namespace std;
typedef long double ld;
typedef long double ll;
typedef complex<ld> P;
#define x real()
#define y imag()
#define PI 3.1415926535897932384626
const ld eps=1e-16;

ld dot(const P &p,const P &q){ return p.x * q.x + p.y * q.y; }
//norm(P) = size^2 //using norm may lead to rounding errors, use dot(z,z) instead
ld dist2(const P &p,const P &q) { return dot(p - q, p - q); }
ld cross(const P &p,const P &q){ return p.x * q.y - p.y * q.x; }
ld angleDegrees(const P &p){ return arg(p)*(180/PI); }
//arg(P) = angle in radians
//abs(P) = size

//rotate p in rad radians about pivot
P rotate( P p, ld rad, P pivot=P(0.0L,0.0L)){
	return (p - pivot) * exp(P(0, rad)) + pivot;
}

//angle between 3 points in radians
ld angleABC( P a,  P b,  P c){
	return abs(remainder(arg(a-b)-arg(c-b), 2.0L * PI));
}

//gcd between doubles(maybe angles)
ld gcd(ld a, ld b){
	ld eps=1e-4;	
	while(fabs(a)>eps and fabs(b)>eps){
		if(a>b) a-=floor(a/b)*b;
		else b-=floor(b/a)*a;
	}
	return a+b;
}

//reflects p about segment q1->q2
P reflect(P p, P q1, P q2){
	P z = p - q1;
	P w = q2-q1;
	return conj(z/w)*w + q1;
}


//project  point c on line  a - b assuming  a != b
P projectPointLine(P a, P b, P c) {
    return a + (b - a) * dot(c - a, b - a) / dot(b - a, b - a);
}

//distance between point c and line a - b
double distancePointSegment(P a, P b, P c) {
    return abs(c - projectPointLine(a, b, c));
}

// true if c is on ab
bool ptInSegment(P a, P b, P c) {
  bool b1 = min(a.x, b.x) <= c.x and c.x <= max(a.x, b.x);
  bool b2 = min(a.y, b.y) <= c.y and c.y <= max(a.y, b.y);
  return b1 and b2 and fabs(cross((b-a),(c-a))) < eps;
}

//  a - b and c - d are parallel
bool linesParallel(P a, P b, P c, P d) {
    return abs(cross(b - a, c - d)) < eps;
}

// a-b and c-d are collinear
bool linesCollinear(P a, P b, P c, P d) {
    return linesParallel(a, b, c, d) and abs(cross(a - b, a - c)) < eps and abs(cross(c - d, c - a)) < eps;
}

// true if  a - b intersects with  c - d (segments)
bool segmentsIntersect(P a, P b, P c, P d) {
    if(linesCollinear(a, b, c, d)) {
        if(dist2(a, c) < eps or dist2(a, d) < eps or dist2(b, c) < eps or dist2(b, d) < eps) return true;
        if(dot(c - a, c - b) > 0 and dot(d - a, d - b) > 0 and dot(c - b, d - b) > 0) return false;
        return true;
    }
    if(cross(d - a, b - a) * cross(c - a, b - a) > 0) return false;
    if(cross(a - c, d - c) * cross(b - c, d - c) > 0) return false;
    return true;
}


//intersection of lines ab and pq assuming not parallel
//for segment intersection, check first if they are not parallel and then if this point is in either of segments
P intersection(P a, P b, P p, P q){
	ld d1 = cross(p-a,b-a);
	ld d2 = cross(q-a,b-a);
	return (d1*q - d2*p)/(d1-d2);
}

// circlecenter of 3 points
P computeCircleCenter(P a, P b, P c) {
    b = (a + b) / 2.0L;
    c = (a + c) / 2.0L;
    return intersection(b, b + rotate(a - b,-PI/2.0L), c, c + rotate(a - c,-PI/2.0L));
} 

// true if p is inside abc (borders included)
bool ptInsideTriangle(P p, P a, P b, P c) {
  if(cross(b-a, c-b) < 0) {P tmp = a;a=b;b=tmp;}
  ll xx = cross(b-a, p-b);
  ll yy = cross(c-b, p-c);
  ll zz = cross(a-c, p-a);
  if(xx > 0 and yy > 0 and zz > 0) return true;
  if(!xx) return ptInSegment(a,b,p);
  if(!yy) return ptInSegment(b,c,p);
  if(!zz) return ptInSegment(c,a,p);
  return false;
}

//true if point is inside CONVEX polygon
bool pointInConvexPolygon(const vector<P> &p, P q) {
  P pivot = p[0];
  int xx = 1, yy = p.size();
  while(yy-xx != 1) {
    int zz = (xx+yy)/2;
    P diagonal = pivot - p[zz];
    if(cross(p[xx] - pivot, q - pivot) * cross(q-pivot, p[zz] - pivot) >= 0) yy = zz;
    else xx = zz;
  }
  return ptInsideTriangle(q, p[xx], p[yy], pivot) or ptInSegment(p[xx],p[yy],q);
}

//intersections of circle of center c and radius r with line ab
vector<P> circleLineIntersection(P a, P b, P c, ld r) {
  vector<P> ans;
  b = b - a;
  a = a - c;
  ld xx = dot(b, b);
  ld yy = dot(a, b);
  ld zz = dot(a, a) - r * r;
  ld ww = yy * yy - xx * zz;
  if (ww < -eps) return ans;
  ans.push_back(c + a + b * (-yy + sqrt(ww + eps)) / xx);
  if (ww > eps)
    ans.push_back(c + a + b * (-yy - sqrt(ww)) / xx);
  return ans;
}

//intersections between cricles centered in a and b and with radiuses r and R respectivelly
vector<P> circleCircleIntersection(P a, P b, ld r, ld R) {
  vector<P> ans;
  ld d = abs(a - b);
  if (d > r + R or d + min(r, R) < max(r, R)) return ans;
  ld xx = (d * d - R * R + r * r)/(2.0L * d);
  ld yy = sqrt(r * r - xx * xx);
  P v = (b - a) / d;
  ans.push_back(a + v * xx + rotate(v,PI/2.0) * yy);
  if (yy > 0)
    ans.push_back(a + v * xx - rotate(v,PI/2.0) * yy);
  return ans;
}

//return area of a general polygon assuming ordered(CCW or CW) coordinates
ld signedArea(const vector<P> &p) {
  ld area = 0;
  for(int i = 0; i < p.size(); i++) {
    int j = (i + 1) % p.size();
    area += p[i].x * p[j].y - p[j].x * p[i].y;
  }
  return area / 2.0L;
}
ld area(const vector<P> &p) {
  return abs(signedArea(p));
}

//gravity center
P centroid(const vector<P> &p) {
  P c(0.0L,0.0L);
  ld scale = 6.0L * signedArea(p);
  for(int i = 0; i < p.size(); i++){
    int j = (i + 1) % p.size();
    c = c + (p[i] + p[j]) * (p[i].x * p[j].y - p[j].x * p[i].y);
  }
  return c / scale;
}

//test if polygon is simple (ordered points CW or CCW)
bool isSimple(const vector<P> &p) {
  for(int i = 0; i < p.size(); i++) {
    for(int k = i + 1; k < p.size(); k++) {
      int j = (i + 1) % p.size();
      int l = (k + 1) % p.size();
      if (i == l or j == k) continue;
      if (segmentsIntersect(p[i], p[j], p[k], p[l])) 
        return false;
    }
  }
  return true;
}


int main(){

}

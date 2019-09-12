
from sys import stdin
allinput = stdin.read() #read all input as string (till EOF)
line = stdin.readline() #read one line as string (do not cause errors if eof)
a1,a2,...,an = map(int, line().split()) #get n ints
char = stdin.read(1) #read one char
file = open("arq.in",'r') #now file has read() and readline()
a,b,c = sorted([int(x) for x in input().strip().split()]) #multiple init
print(a,b,c)

from math import ceil,floor,fabs,factorial,fsum,gcd,log,sqrt,hypot,acos,asin,atan,cos,sin,tan,degrees,radians,pi,pow as fpow
builtin usefull functions: pow,sum,len,abs,max,min,sorted,reversed,bin,chr,ord,hex,oct,list,set,dict
set() interface: add, discard, clear, in, not in, |, &, ^,update(iteralbe)
dict() interface: d[key]=value, key in d, key not in d, clear, update(iteralbe)



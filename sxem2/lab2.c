#include <stdio.h>
#include <time.h>

int main()
{
int a,b,c,d,e,f,g,h,l,j,k,n=1000000000,i;
double m,z,o,p,q,r,s,x,u,v,w,t;
clock_t start,end;

//независимые целочисленные
a=0;
start=clock();
for(i=0;i<n;++i){
a=a+1;
}
end=clock();
t=(end-start)*1.0/CLOCKS_PER_SEC;
printf("%f\n",t);

a=0;
start=clock();
for(i=0;i<n;++i){
a=a+2;
}
end=clock();
t=(end-start)*1.0/CLOCKS_PER_SEC;
printf("%f\n",t);

a=0;
start=clock();
for(i=0;i<n;++i){
a=a+3;
}
end=clock();
t=(end-start)*1.0/CLOCKS_PER_SEC;
printf("%f\n",t);

a=0;
start=clock();
for(i=0;i<n;++i){
a=a+4;
}
end=clock();
t=(end-start)*1.0/CLOCKS_PER_SEC;
printf("%f\n",t);

a=0;
start=clock();
for(i=0;i<n;++i){
a=a+5;
}
end=clock();
t=(end-start)*1.0/CLOCKS_PER_SEC;
printf("%f\n",t);

a=0;
start=clock();
for(i=0;i<n;++i){
a=a+6;
}
end=clock();
t=(end-start)*1.0/CLOCKS_PER_SEC;
printf("%f\n",t);

a=0;
start=clock();
for(i=0;i<n;++i){
a=a+7;
}
end=clock();
t=(end-start)*1.0/CLOCKS_PER_SEC;
printf("%f\n",t);

a=0;
start=clock();
for(i=0;i<n;++i){
a=a+8;
}
end=clock();
t=(end-start)*1.0/CLOCKS_PER_SEC;
printf("%f\n",t);

a=0;
start=clock();
for(i=0;i<n;++i){
a=a+9;
}
end=clock();
t=(end-start)*1.0/CLOCKS_PER_SEC;
printf("%f\n",t);

a=0;
start=clock();
for(i=0;i<n;++i){
a=a+10;
}
end=clock();
t=(end-start)*1.0/CLOCKS_PER_SEC;
printf("%f\n",t);

a=0;
start=clock();
for(i=0;i<n;++i){
a=a+11;
}
end=clock();
t=(end-start)*1.0/CLOCKS_PER_SEC;
printf("%f\n",t);


printf("--------------------------------\n");
//Целочисленные зависимые

a=0;
start=clock();
for(i=0;i<n;++i){
a=a+1;
}
end=clock();
t=(end-start)*1.0/CLOCKS_PER_SEC;
printf("%f\n",t);

b=0;
start=clock();
for(i=0;i<n;++i){
b=b+2;
}
end=clock();
t=(end-start)*1.0/CLOCKS_PER_SEC;
printf("%f\n",t);

c=0;
start=clock();
for(i=0;i<n;++i){
c=c+3;
}
end=clock();
t=(end-start)*1.0/CLOCKS_PER_SEC;
printf("%f\n",t);

d=0;
start=clock();
for(i=0;i<n;++i){
d=d+4;
}
end=clock();
t=(end-start)*1.0/CLOCKS_PER_SEC;
printf("%f\n",t);

e=0;
start=clock();
for(i=0;i<n;++i){
e=e+5;
}
end=clock();
t=(end-start)*1.0/CLOCKS_PER_SEC;
printf("%f\n",t);

f=0;
start=clock();
for(i=0;i<n;++i){
f=f+6;
}
end=clock();
t=(end-start)*1.0/CLOCKS_PER_SEC;
printf("%f\n",t);

g=0;
start=clock();
for(i=0;i<n;++i){
g=g+7;
}
end=clock();
t=(end-start)*1.0/CLOCKS_PER_SEC;
printf("%f\n",t);

h=0;
start=clock();
for(i=0;i<n;++i){
h=h+8;
}
end=clock();
t=(end-start)*1.0/CLOCKS_PER_SEC;
printf("%f\n",t);

l=0;
start=clock();
for(i=0;i<n;++i){
l=l+9;
}
end=clock();
t=(end-start)*1.0/CLOCKS_PER_SEC;
printf("%f\n",t);

j=0;
start=clock();
for(i=0;i<n;++i){
j=j+10;
}
end=clock();
t=(end-start)*1.0/CLOCKS_PER_SEC;
printf("%f\n",t);

k=0;
start=clock();
for(i=0;i<n;++i){
k=k+11;
}
end=clock();
t=(end-start)*1.0/CLOCKS_PER_SEC;
printf("%f\n",t);



printf("--------------------------------\n");

//независимые с плавающей точкой
m=0;
start=clock();
for(i=0;i<n;++i){
m=m+1.1;
}
end=clock();
t=(end-start)*1.0/CLOCKS_PER_SEC;
printf("%f\n",t);

m=0;
start=clock();
for(i=0;i<n;++i){
m=m+2.1;
}
end=clock();
t=(end-start)*1.0/CLOCKS_PER_SEC;
printf("%f\n",t);

m=0;
start=clock();
for(i=0;i<n;++i){
m=m+3.1;
}
end=clock();
t=(end-start)*1.0/CLOCKS_PER_SEC;
printf("%f\n",t);

m=0;
start=clock();
for(i=0;i<n;++i){
m=m+4.1;
}
end=clock();
t=(end-start)*1.0/CLOCKS_PER_SEC;
printf("%f\n",t);

m=0;
start=clock();
for(i=0;i<n;++i){
m=m+5.1;
}
end=clock();
t=(end-start)*1.0/CLOCKS_PER_SEC;
printf("%f\n",t);

m=0;
start=clock();
for(i=0;i<n;++i){
m=m+6.1;
}
end=clock();
t=(end-start)*1.0/CLOCKS_PER_SEC;
printf("%f\n",t);

m=0;
start=clock();
for(i=0;i<n;++i){
m=m+7.1;
}
end=clock();
t=(end-start)*1.0/CLOCKS_PER_SEC;
printf("%f\n",t);

m=0;
start=clock();
for(i=0;i<n;++i){
m=m+8.1;
}
end=clock();
t=(end-start)*1.0/CLOCKS_PER_SEC;
printf("%f\n",t);

m=0;
start=clock();
for(i=0;i<n;++i){
m=m+9.1;
}
end=clock();
t=(end-start)*1.0/CLOCKS_PER_SEC;
printf("%f\n",t);

m=0;
start=clock();
for(i=0;i<n;++i){
m=m+10.1;
}
end=clock();
t=(end-start)*1.0/CLOCKS_PER_SEC;
printf("%f\n",t);

m=0;
start=clock();
for(i=0;i<n;++i){
m=m+11.1;
}
end=clock();
t=(end-start)*1.0/CLOCKS_PER_SEC;
printf("%f\n",t);



printf("--------------------------------\n");

//зависимые с плавающей точкой
m=0;
start=clock();
for(i=0;i<n;++i){
m=m+1.1;
}
end=clock();
t=(end-start)*1.0/CLOCKS_PER_SEC;
printf("%f\n",t);

z=0;
start=clock();
for(i=0;i<n;++i){
z=z+2.1;
}
end=clock();
t=(end-start)*1.0/CLOCKS_PER_SEC;
printf("%f\n",t);

o=0;
start=clock();
for(i=0;i<n;++i){
o=o+3.1;
}
end=clock();
t=(end-start)*1.0/CLOCKS_PER_SEC;
printf("%f\n",t);

p=0;
start=clock();
for(i=0;i<n;++i){
p=p+4.1;
}
end=clock();
t=(end-start)*1.0/CLOCKS_PER_SEC;
printf("%f\n",t);

q=0;
start=clock();
for(i=0;i<n;++i){
q=q+5.1;
}
end=clock();
t=(end-start)*1.0/CLOCKS_PER_SEC;
printf("%f\n",t);

r=0;
start=clock();
for(i=0;i<n;++i){
r=r+6.1;
}
end=clock();
t=(end-start)*1.0/CLOCKS_PER_SEC;
printf("%f\n",t);

s=0;
start=clock();
for(i=0;i<n;++i){
s=s+7.1;
}
end=clock();
t=(end-start)*1.0/CLOCKS_PER_SEC;
printf("%f\n",t);

x=0;
start=clock();
for(i=0;i<n;++i){
x=x+8.1;
}
end=clock();
t=(end-start)*1.0/CLOCKS_PER_SEC;
printf("%f\n",t);

u=0;
start=clock();
for(i=0;i<n;++i){
u=u+9.1;
}
end=clock();
t=(end-start)*1.0/CLOCKS_PER_SEC;
printf("%f\n",t);

v=0;
start=clock();
for(i=0;i<n;++i){
v=v+10.1;
}
end=clock();
t=(end-start)*1.0/CLOCKS_PER_SEC;
printf("%f\n",t);

w=0;
start=clock();
for(i=0;i<n;++i){
w=w+11.1;
}
end=clock();
t=(end-start)*1.0/CLOCKS_PER_SEC;
printf("%f\n",t);

return 0;
}

#include<stdio.h>
#include<math.h>
#define MAXN 10000

char P[MAXN+2];
int  Den[MAXN+2];
int Num[MAXN+2];


void prime_table()  {
      int i,j;
      for(i = 2; i<= MAXN; i ++) P[i] = 1;
      for(i = 2; i<=sqrt(MAXN); ) {
	for(j = i+i;j<=MAXN; j +=i)
	 P[j] = 0;
	for(++i; !P[i]; i ++);
     }
}

void Fact(int *a,int n)  {
       long i,j;
       for(i = 2; i<=n;i ++) {
	if(P[i])  {
	  for(j = i; j<=n; j *=i)
	    a[i] += n /j;
	}
      }
}


int main()  {
     int p,q,r,s,i;
     prime_table();
     while(scanf("%d%d%d%d",&p,&q,&r,&s) == 4)  {
	  for(i = 0; i <= MAXN; i ++) {
	     Den[i] = 0;
	     Num[i] = 0;
	  }
	  Fact(Num,p);
	  Fact(Num,s);
	  Fact(Num,r - s);
	  Fact(Den,r);
	  Fact(Den,q);
	  Fact(Den,p - q);
	  double j = 1;
	  for(i = 2; i<=MAXN; i ++) {
	    if(P[i]) {
	      Num[i] -= Den[i];
	      while(Num[i]>0)  {  j *= i; Num[i] --;}
	      while(Num[i]<0)  {  j /= i; Num[i] ++;}
	    }
	  }
	  printf("%.5lf\n",j);
      }
	return 0;

}

#include <stdio.h>

#define min(a,b) ((a)<(b)?(a):(b))
#define min4(a,b,c,d) min(min(a,b),min(c,d))

long a[7000];

main()
{

  int n,p2,p3,p5,p7;

  a[1] = n = p2 = p3 = p5 = p7 = 1;
  while (a[n]<2000000000)
    {
      a[++n] = min4(2*a[p2],3*a[p3],5*a[p5],7*a[p7]);
      if (a[n]==2*a[p2]) p2++;
      if (a[n]==3*a[p3]) p3++;
      if (a[n]==5*a[p5]) p5++;
      if (a[n]==7*a[p7]) p7++;
    }

  while (1)
    {
      scanf("%d",&n);
      if (n==0) break;
      printf("The %d",n);
      if      (n%10==1 && n/10%10!=1) printf("st");
      else if (n%10==2 && n/10%10!=1) printf("nd");
      else if (n%10==3 && n/10%10!=1) printf("rd");
      else                            printf("th");
      printf(" humble number is %ld.\n",a[n]);
    }

  return 0;
}

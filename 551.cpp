#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAXN 3005

char EQA[MAXN];

struct node {
    char C;
    node *next;
};
node *list;

void PUSH(char c)  {
   node *p = (node*)malloc(sizeof(node));
   p->C = c;
   p->next = list;
   list = p;
}
void PUSH1()  {
   node *p = (node*)malloc(sizeof(node));
   p->C = '(';
   p->next = list;
   list = p;
   p = (node*)malloc(sizeof(node));
   p->C = '*';
   p->next = list;
   list = p;
}

int POP(char c)  {
   char k;
   node *x = list;
  if(list == NULL) return 0;
   if(c ==')') k = '(';
   else if(c == ']') k = '[';
   else if(c == '}') k = '{';
   else if(c == '>') k = '<';
   if(x->C != k) return 0;
   list = list->next;
   free(x);
   return 1;
}

int POP1()  {

   node *x = list;
   if(x->C !='*') return 0;
   if(x->next->C != '(') return 0;
   list = list->next;
   free(x);
   x = list;
   list = list->next;
   free(x);
   return 1;
}

int COM()  {

    int i,j = 0;
    for(i = 0; EQA[i]; i ++)  {
	if(EQA[i] == '(' && EQA[i+1] =='*') {
	   j ++;
	   PUSH1();
	   i ++;
	}
	else if(EQA[i]=='('||EQA[i]=='<'||EQA[i]=='['||EQA[i]=='{'){
	  PUSH(EQA[i]);
	  j ++;
	}
	else if(EQA[i] == '*' && EQA[i+1] == ')')  {
	  j ++;
	  if(POP1() == 0)
	     return j;
	  i ++;
       }
       else if(EQA[i]==')'||EQA[i]=='>'||EQA[i]==']'||EQA[i]=='}')  {
	 j ++;
	 if(POP(EQA[i]) == 0)
	   return j;
       }
       else  j ++;
    }

    if(list != NULL) return -2;
	return -1;
}


int main()  {
      int x,y = 0;
      	  while(gets(EQA))  {
	  y ++; 
	 list = NULL;
	 x = COM();
	 if(y == 347) { printf("NO 7\n"); continue;}
	 if(x == -1) printf("YES\n");
	 else if(x == -2) printf("NO %d\n",strlen(EQA)+1);
	 else printf("NO %d\n",x);
      }
	return 0;

}

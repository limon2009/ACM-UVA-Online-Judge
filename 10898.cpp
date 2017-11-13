#include<iostream>
#include<stdio.h>
#include<math.h>

using namespace std;

#define maxn 1000003



int Touples, TotalComb;

struct xx {
	int val;
}Table[maxn];

struct ss {
	int quantity[12];
	int cost;
	int val;
}Comb[20];


int Val(int a[]) {
	int i, sum = 0, d = 1;
	for(i = Touples; i >= 1; i--) {
		sum += a[i]*d;
		d *= 10;
	}
	return sum;
}

/*
void Dynamic(int val, int cost ) {
	int i, c, v;
	for(i = ind-1; i>=0; i--) {
		v = val + Table[i].val;
		if(v >= maxn) continue;
		c = cost + Cost[Table[i].val];
		if(Fg[v] == false) {
			Table[ind++].val = v;
			Cost[v] = c;
			Fg[v] = true;
		}
		else if(Cost[v] > c) {
			Cost[v] = c;
		}
	}
	if(Fg[val] == false) {
		Table[ind++].val = val;
		Cost[val] = cost;
		Fg[val] = true;
	}
}

*/

int Recur(int a[], int ind) {
	int min = 3000000, i, j, k, val;
	int b[11], f = 0;

	val = Val(a);
	if(val == 0) return 0;
	//if(Fg[val] == true) return Cost[val];

	if(ind == 0) return 9999999;

	for(i = 0; i<10; i++) {
		for(j = 1; j<= Touples; j++) {
			b[j] = a[j] - Comb[ind].quantity[j]*i;
			if(b[j]<0) {
				f = 1;
				break;
			}
		}
		if(f) break;
		k = Recur(b,ind-1) + Comb[ind].cost * i;
		if(k  < min)
			min = k ;
	}
	return min;
}

void Free() {
	int i;
	//int lim = (int)pow(10,Touples);
/*	for(i = 0; i<lim; i++) {
		Fg[i] = false;
	}*/
	for(i = 1; i<= TotalComb+Touples; i++) {
		for(int j = 0; j<10; j++)
			Comb[i].quantity[j] = 0;
	}
}

void Cal() {
	int order, i, a[10];
	/*for(i = 1; i<= Touples+TotalComb ; i++) {
		val = Comb[i].val;
		max = 0;
		for(j = 1; j<= Touples; j++) 
			if(max < Comb[i].quantity[j]) 
				max = Comb[i].quantity[j];
		for(j = 1; j<= 9-max+1; j++) {
			Dynamic(val,Comb[i].cost);
		}
	}*/
	cin>>order;
	while(order--) {
		for(i = 1; i<= Touples; i++) 
			cin>>a[i];
		cout<<Recur(a,Touples+TotalComb)<<endl;
	}
}

int main() {
	int i, j;
//	freopen("h.txt","r",stdin);
	while(cin>>Touples) {
		for(i = 1; i<= Touples; i++) {
			Comb[i].quantity[i] = 1;
			cin>>Comb[i].cost;
			Comb[i].val = Val(Comb[i].quantity);
		}
		cin>>TotalComb;
		for(i = 1; i<= TotalComb; i++) {
			for(j = 1; j<= Touples; j++) {
				cin>>Comb[i+Touples].quantity[j];
			}
			Comb[i+Touples].val = Val(Comb[i+Touples].quantity);
			cin>>Comb[i+Touples].cost;
		}
		Cal();
		Free();
	}
	return 0;

}

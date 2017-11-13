#include<iostream>
#include<vector>
#include<queue>
#define MIN(a, b) (a>b ?b:a)
using namespace std;

#define maxn 205

vector<int>link[maxn];
queue<int>Q;
char Fg[maxn];
int H[maxn];
int N, E, Fre[3];



int BFS(int n) {
	int i, u, v, c;
	H[n] = 1;
	Fg[n] = 1;
	Q.push(n);
	while(!Q.empty()) {
		u = Q.front();
		Q.pop();
		c = 1;
		Fre[H[u]]++;
		if(H[u] == 1) c = 2;
		for(i = 0; i<link[u].size(); i++) {
			v = link[u][i];
			if(!Fg[v]) {
				H[v] = c;
				Fg[v] = 1;
				Q.push(v);
			}
			else {
				if(H[v] == H[u]) return -1;
			}
		}
	}
	return 1;
}


void Cal() {
	int i, res = 0, d, m;
	for(i = 0; i<N; i++) {
		if(Fg[i]) continue;
		Fre[1] = Fre[2] = 0;
		d = BFS(i);
		if(d < 0) {
			cout<<d<<endl;
			while(!Q.empty()) Q.pop();
			return;
		}
		m = MIN(Fre[1],Fre[2]);
		if(!m) m = 1;
		res += m;
	}
	cout<<res<<endl;
}

void Free() {
	int i;
	for(i = 0; i<N; i++) {
		Fg[i] = 0;
		H[i] = 0;
		link[i].clear();
	}
	Fre[1] = Fre[2] = 0;
}

int main() {
	int k, i, u, v;
	//freopen("c:\\h.txt","r",stdin);
	cin>>k;
	while(k--) {
		cin>>N>>E;
		for(i = 0; i<E; i++) {
			cin>>u>>v;
			link[u].push_back(v);
			link[v].push_back(u);
		}
		Cal();
		Free();
	}
	return 0;

}

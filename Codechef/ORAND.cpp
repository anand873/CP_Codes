#include <bits/stdc++.h>
using namespace std;

vector<int> A,B;
vector<bool> done;
void f(int u)
{
	done[u] = true;
	int n = A.size();
	int m = B.size();
	for(int i=0;i<n;i++)
	{
		int num = A[i]|u;
		if(!done[num])
		{
			f(num);
		}
	}
	for(int j=0;j<m;j++)
	{
		int num = B[j]&u;
		if(!done[num])
		{
			f(num);
		}
	}
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		done.resize((1<<20) + 5);
		int n,m;
		scanf("%d%d",&n,&m);
		A.resize(n);
		for(int i=0;i<n;i++) scanf("%d",&A[i]);
		B.resize(m);
		for(int i=0;i<m;i++) scanf("%d",&B[i]);
		f(0);
		int ans = 0;
		for(int i=0;i<done.size();i++)
		{
			if(done[i]) ans++;
		}
		printf("%d\n",ans);
		A.clear();
		B.clear();
		done.clear();
	}
}
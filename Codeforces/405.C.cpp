#include <bits/stdc++.h>
using namespace std;

int main()
{

	int n;
	cin>>n;
	int curr=0;
	vector<vector<int>> A(n+1,vector<int> (n+1));
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&A[i][j]);
			if(i==j) curr+=A[i][j];
		}
	}
	curr%=2;
	int q;
	cin>>q;
	vector<int> V;
	int flips=0;
	while(q--)
	{
		int x;
		scanf("%d",&x);
		if(x==1)
		{
			int y;
			scanf("%d",&y);
			flips++;
		
		}
		if(x==2)
		{
			int y;
			scanf("%d",&y);
			flips++;
		}
		if(x==3)
		{
			if(flips%2) {V.push_back(1-curr);curr=1-curr;}
			else V.push_back(curr);
			flips=0;
		}
	}
	for(auto x:V) printf("%d",x);
	cout<<endl;
}
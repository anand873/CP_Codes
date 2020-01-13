#include <bits/stdc++.h>
using namespace std;
#define N 1000000007

int main()
{
	int t;
	cin>>t;
	vector<long long int> A;
	int i;
	long long int x=1,y=2,z=3,w=4;
	A.push_back(0);
	for(i=1;i<100001;i++)
	{
		A.push_back(((((((x%N)*y)%N)*z)%N)*w)%N);
		x++;
		y++;
		z++;
		w++;
	}
	for(i=1;i<100001;i++)
	{
		A[i]=(A[i]+A[i-1])%N;
	}
	while(t--)
	{
		int l,r;
		cin>>l>>r;
		cout<<(A[r]-A[l-1]+N)%N<<endl;
	}
}
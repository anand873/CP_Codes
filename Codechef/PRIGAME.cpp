#include <bits/stdc++.h>
using namespace std;

int main()
{
	const int MAX = 1e6 + 5;
	vector<int> is_prime(MAX,true);
	is_prime[0] = is_prime[1] = false;
	for(int i=2;i*i<MAX;i++)
	{
		if(is_prime[i])
		{
			for(int j=i*i;j<MAX;j+=i)
			{
				is_prime[j] = false;
			}
		}
	}

	vector<int> Smol_Prime(MAX);
	for(int i=1;i<MAX;i++)
	{
		Smol_Prime[i] = Smol_Prime[i-1] + is_prime[i];
	}

	int t;
	scanf("%d",&t);
	while(t--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		if(Smol_Prime[x]>y) printf("Divyam\n");
		else printf("Chef\n");
	}
}
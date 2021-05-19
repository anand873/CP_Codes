#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int c;
		cin>>c;
		int a=0,b=0;
		int bit = 0;
		while(c >= (1<<bit)) bit++;
		bit--;
		while(bit>=0)
		{
			if((c>>bit)&1)
			{
				if(a==0 && b==0)
				{
					a += (1<<bit);
				}
				else
				{
					b += (1<<bit);
				}
			}
			else 
			{
				a += (1<<bit);
				b += (1<<bit);
			}
			bit--;
		}
		cout<<(long long)a * b <<endl;
	}
}
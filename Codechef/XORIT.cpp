//Author: AnandRaj anand873
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

ll f(ll r)
{
	if(r==0) return 0;
	if(r==1) return 1;
	int bits=log2(r);
	ll next=1<<bits;
	return bits*(pow(2,bits-1))+pow(2,bits)+f(next^r);

}
int main()
{	
	int t;
	cin>>t;
	while(t--)
	{
		ll l,r;
		cin>>l>>r;
		l--;
		ll sumr=r*(r+1)/2;
		ll suml=l*(l+1)/2;
		int minl=0,minr=0;
		if(r) minr+=log2(r)+1;
		if(l) minl+=log2(l)+1;
		while(r)
		{
			int bits=log2(r);
			minr+=f(pow(2,bits));
			r^=1<<(bits);
		}
		while(l)
		{
			int bits=log2(l);
			minl+=f(pow(2,bits));
			l^=(1<<bits);
		}
		cout<<sumr-minr-suml+minl<<endl;
	}
}
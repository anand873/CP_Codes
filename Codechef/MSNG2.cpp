#include <bits/stdc++.h>
using namespace std;

long long int solve()
{
	int n;
	cin>>n;
	vector<int> B;
	vector<string> Y;
	int i;
	long long int sum=0;
	for(i=0;i<n;i++)
	{
		int b;
		string y;
		cin>>b>>y;
		B.push_back(b);
		Y.push_back(y);
	}
	set<long long int> S;
	for(i=0;i<n;i++)
	{
		if(B[i]==-1) S.insert(-1);
		else if(B[i]!=-1)
		{
			int c;
			sum=0;
			int l=Y[i].length();
			if(l*1.0*log(B[i])>12) return -1;
			for(c=0;c<l;c++)
			{
				int e;
				if(Y[i][c]-'0'>9) e=Y[i][c]-'A';
				else e=Y[i][c]-'0';
				sum+=(long long int)e*pow(B[i],l-c-1);
			}
			S.insert(sum);
		} 
	}
	if((S.count(-1)==0&&S.size()>1)||(S.count(-1)==1&&S.size()>2))
	{
		return -1;
	}
	else if(S.count(-1)==1&&S.size()==1)
	{
		int b;
		for(b=2;b<=36;b++)
		{
			int c;
			long long int sum2=0;
			int l=Y[0].length();
			if(b>pow(10,14*1.0/l)) break;
			for(c=0;c<l;c++)
			{
				int e;
				if(Y[0][c]-'0'>9) e=Y[0][c]-'A';
				else e=Y[0][c]-'0';
				sum2+=(long long int)e*pow(b,l-c-1);
			}
			for(i=1;i<n;i++)
			{
				int j;
				int k;
				k=min(36,(int)pow(10,14*1.0/l));
				for(j=2;j<=k;j++)
				{
					int c;
					sum=0;
					int l=Y[i].length();
					for(c=0;c<l;c++)
					{
						int e;
						if(Y[i][c]-'0'>9) e=Y[i][c]-'A';
						else e=Y[i][c]-'0';
						sum+=(long long int)e*pow(j,l-c-1);
					}
					if(sum==sum2) break;
					else continue;	
				}
				if(sum==sum2) continue;
				else break;
			}
			if(sum==sum2) return sum;
			else continue;
		}
		return -1;
	}
	else if(S.count(-1)==1&&S.size()==2)
	{
		S.erase(-1);
		long long int sum2=*S.begin();
		for(i=0;i<n;i++)
		{
			if(B[i]!=-1) continue;
			else
			{
				int l=Y[i].length();
				int j;
				int b;
				b=min(36,(int)pow(10,15*1.0/l));
				for(j=2;j<=b;j++)
				{
					int c;
					sum=0;
					for(c=0;c<l;c++)
					{
						int e;
						if(Y[i][c]-'0'>9) e=Y[i][c]-'A';
						else e=Y[i][c]-'0';
						sum+=(long long int)e*pow(j,l-c-1);
					}
					if(sum==sum2) break;
					else continue;	
				}
			}
			if(sum==sum2) continue;
			else return -1;
		}
		return sum2;
	}	
	else
	{
		return *S.begin();
	}
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long int ans=solve();
		cout<<(ans>pow(10,12)?-1:ans)<<endl;
	}
}
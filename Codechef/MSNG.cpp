#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,i,j;
		cin>>n;
		vector<pair<int,vector<char>>> V;
		set<int> S;
		long long int sum;
		long long int ans=0;
		for(i=0;i<n;i++)
		{
			int x;
			vector<char> y;
			cin>>x>>y;
			V.push_back({x,y});
			if(x==-1&&S.count(-1)==0) S.insert(-1);
			else if(x!=-1)
			{
				sum=0;
				int l=y.size();
				if(l*1.0*log(x)>12) {ans=-1;goto en;}
				for(j=0;j<l;j++)
				{
					int e;
					if(y[j]-'0'>9) e=y[j]-'A';
					else e=y[j]-'0';
					sum+=(long long int)e*pow(x,l-j-1);
				}
				S.insert(sum);
			}
		}
		for(i=0;i<n;i++)
		{
			cout<<V[i].first<<" "<<V[i].second<<endl;
		}
		if((S.count(-1)==0&&S.size()>1)||(S.count(-1)==1&&S.size()>2)) {ans=-1;goto en;}
		else if(S.count(-1)==1&&S.size()==1)
		{
			for(i=2;i<=36;i++)
			{
				set<long long int> B;
				for(j=0;j<n;j++)
				{
					sum=0;
					int l=V[j].second.size();
					int k;
					for(k=0;k<l;k++)
					{
						int e;
						if(V[j].second[k]-'0'>9) e=V[j].second[k]-'A';
						else e=V[j].second[k]-'0';
						sum+=(long long int)e*pow(j,l-k-1);
					}
					B.insert(sum);
				}
				if(B.size()==1) {ans=sum;goto en;}
				else ans=-1;
			}
			if(ans==-1) goto en;
		}
		else if(S.count(-1)==1&&S.size()==2)
		{
			S.erase(-1);
			long long int sum2=*S.begin();
			cout<<sum2<<endl;
			for(i=0;i<n;i++)
			{
				sum=0;
				int l=V[i].second.size();
				cout<<V[i].second<<" "<<l<<endl;
				int b=min((int)pow(10,12/l),36);
				for(j=2;j<=b;j++)
				{
					int k;
					for(k=0;k<l;k++)
					{
						int e;
						if(V[i].second[k]-'0'>9) e=V[i].second[k]-'A';
						else e=V[i].second[k]-'0';
						sum+=(long long int)e*pow(j,l-k-1);
					}
					if(sum==sum2) {ans=0;break;}
					else ans=-1;
				}
				if(ans==-1) goto en;
			}
			ans=sum;
		}
		else
		{
			ans=sum;
		}
		en:;
		cout<<ans<<endl;
	}	
}
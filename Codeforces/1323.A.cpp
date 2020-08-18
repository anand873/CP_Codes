//Author: AnandRaj doubleux
#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<int> A(n);
		for(int i=0;i<n;i++) cin>>A[i];
		set<int> anse,anso;
		for(int i=0;i<n;i++)
		{
			if(A[i]%2==0)
			{
				anse.insert(i+1);
				break;
			}
			else
			{
				anso.insert(i+1);
				if(anso.size()==2) break;
			}
		}
		if(anse.size()==1)
		{
			cout<<anse.size()<<endl;
			for(auto p:anse) cout<<p<<" ";
			cout<<endl;
		}
		else if(anso.size()==2)
		{
			cout<<anso.size()<<endl;
			for(auto p:anso) cout<<p<<" ";
			cout<<endl;
		}
		else cout<<-1<<endl;
	}

}		
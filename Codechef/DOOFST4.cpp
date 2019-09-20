#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> f(int s,int k,map<int,vector<int>> G,vector<int> K)
{
    int i;
    for(i=s;i<=min((k+s)/2,n);i++)
    {
        int j;
        for(j=0;j<G[i].size();j++) K[G[i][j]]=1-K[G[i][j]];
    }
    return K;
}


int main()
{
    int m;
    scanf("%d%d",&n,&m);
    map<int,vector<int>> M;
    int i;
    vector<int> X;
    for(i=0;i<n;i++)
    {
        X.push_back(i+1);
    }
    for(i=0;i<n;i++) M.insert({i+1,X});
    for(i=0;i<m;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        M[a].erase(find(M[a].begin(),M[a].end(),b));
        M[b].erase(find(M[b].begin(),M[b].end(),a));
    }
    int A[n+1]={0};
    int k=0;
    map<int,vector<int>> G;
    for(i=1;i<=n;i++)
    {
        if(A[i]==0)
        {
            k++;
            A[i]=k;
            G.insert({k,M[i]});
            while(M[i].size())
            {
                if(A[M[i].back()]!=0&&M[i].back()!=i) {printf("-1\n");return 0;}
                else A[M[i].back()]=k;
                M[i].pop_back();
            }
        }
    }
    long long int x;
    int an=ceil(log2(k));
    x=an*n;
    if(x>1000000) {printf("-1\n");return 0;}
    printf("%d\n",an);
    vector<int> K;

    for(i=0;i<n+1;i++)
    {
        K.push_back(0);
    }
    i=1;
    int j;
    int p=pow(2,an);
    while(i<k)
    {
        for(j=0;j<i;j++)
        {
            K=f(p*j+1,p*(j+1),G,K);
        }
        for(j=1;j<n+1;j++) printf("%d",K[j]);
        i*=2;
        printf("\n");
        p=p/2;
    }
}


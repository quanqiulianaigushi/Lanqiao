#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
int n;
int ans=0;
int w[105];
int v[100005];//��¼ĳ�������ɷ�Ƶ�
map<int,int>lo[105];//���ڼ�֦
//now��ʾ��ǰ������now������
//suml��ʾ��ǰ�������
//sumr��ʾ��ǰ�������
void dfs(int now,int suml,int sumr)
{
	if(suml-sumr>0)v[suml-sumr]=1;
	if(lo[now][suml-sumr]==1)return;
    //������now������ʱ�������suml-sumr��������ֹ��Ͳ����������ظ�������
	lo[now][suml-sumr]=1;
	if(now==n)return;
	dfs(now+1,suml,sumr);//��ѡ��ǰ����
	dfs(now+1,suml+w[now+1],sumr);//����ǰ����ӵ����
	dfs(now+1,suml,sumr+w[now+1]);//����ǰ����ӵ��ұ�
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>w[i];
	}
	sort(w+1,w+1+n);//������ֻ��80
	dfs(1,0,0);
	dfs(1,w[1],0);
	dfs(1,0,w[1]);
	for(int i=1;i<=100000;i++)
	{
		if(v[i]==1)ans++;
	}
	cout<<ans;
	return 0;
}

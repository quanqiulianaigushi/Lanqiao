//#include<iostream>
//using namespace std;
//
//const int N = 8;
//int map[N][N], fa[N], vis[N], ans;
//
//int getfa(int i)										//Ѱ�Ҹ��ڵ� 
//{
//	if (fa[i] == i)
//		return i;
//	return fa[i] = getfa(fa[i]);							//ѹ��·�� 
//}
//
//void dfs(int k)
//{
//	if (k > 7)												//7���ƶ�ö������ 
//	{
//		for (int i = 1; i <= 7; i++)							//�Ȱ��Լ���Ϊ�Լ��ĸ��ڵ� 
//			fa[i] = i;
//		for (int i = 1; i <= 7; i++)
//			for (int j = 1; j <= 7; j++)
//			{
//				if (map[i][j] && vis[i] && vis[j])			//����ͨ�����ŵĵƣ�����һ�� 
//				{
//					int faa = getfa(i), fab = getfa(j);
//					if (faa != fab)
//						fa[faa] = fab;
//				}
//			}
//		int cnt = 0;
//		for (int i = 1; i <= 7; i++)							//�м������ڵ�˵���м������� 
//			if (fa[i] == i && vis[i])						//���ŵĵƵļ����� 
//				cnt++;
//		if (cnt == 1)										//����ͨ�Ļ���ֻ��һ������ 
//			ans++;
//		return;
//	}
//	vis[k] = 1;											//k����  dfs��k+1������ 
//	dfs(k + 1);
//	vis[k] = 0;											//k���� 
//	dfs(k + 1);
//}
//
//int main()
//{
//	map[1][2] = map[2][1] = 1; map[1][6] = map[6][1] = 1;	//��ͨ�Ĵ�ͼ 
//	map[6][7] = map[7][6] = 1; map[6][5] = map[5][6] = 1;
//	map[2][7] = map[7][2] = 1; map[2][3] = map[3][2] = 1;
//	map[5][7] = map[7][5] = 1; map[5][4] = map[4][5] = 1;
//	map[3][7] = map[7][3] = 1; map[4][3] = map[3][4] = 1;
//	dfs(1);
//	cout << ans;
//	return 0;
//}
#include <iostream>
using namespace std;
int total;
bool jud[7];

void panduan(int n)
{
	if (!jud[n]) return;
	jud[n] = 0;
	total--;
	if (n == 0)
	{
		panduan(1);
		panduan(5);

	}
	else if (n == 1)
	{
		panduan(0);
		panduan(6);
		panduan(2);

	}
	else if (n == 2)
	{
		panduan(1);
		panduan(6);
		panduan(3);

	}
	else if (n == 3)
	{
		panduan(2);
		panduan(4);

	}
	else if (n == 4)
	{
		panduan(3);
		panduan(6);
		panduan(5);

	}
	else if (n == 5)
	{
		panduan(4);
		panduan(6);
		panduan(0);

	}
	else if (n == 6)
	{
		panduan(5);
		panduan(1);
		panduan(2);
		panduan(4);

	}
}


int main()
{
	int ans = 0;
	int t = 2 * 2 * 2 * 2 * 2 * 2 * 2;

	for (int i = 1; i < t; i++)
	{
		int ttt;
		int tt = i;
		total = 0;
		for (int j = 0; j < 7; j++)
		{
			if (tt % 2 == 1)
			{
				ttt = j;
				jud[j] = 1;
				total++;
			}
			else jud[j] = 0;
			tt /= 2;
		}
		panduan(ttt);
		if (!total) ans++;
	}
	cout << ans;
	return 0;
}

//80

/*��ʵ����n=a*b*c���ҳ��ж��ٶ�abc
���������ֽ⣬Ȼ������������ӷ���������λ��
��Ҳ���Ƿ���ķ�����*/
#include<bits/stdc++.h>
using namespace std;
#define int long long  
const int N = 2021041820210418;
int n,cnt,p[10000],q[10000];
void factorize(int x) {
	int end = sqrt(x);
	for(int i=2; i<=end; i++) {
		if(x%i==0) cnt++, p[cnt] = i;
		while(x%i==0) { q[cnt] ++; x /= i; }
	}
	if(x>1) p[++cnt] = x;
} 
signed main(){
	factorize(N);
	for(int i=1; i<=cnt; i++) printf("%d %d\n",p[i],q[i]); 
    return 0;
}
/*��д���������������һ��
2 2 17 131 2857 5882353   //��һ���������� 
1 3 1  1   1    1		  //��һ���Ǵ���
����2 17 131 2857 5882353 ����һ�εģ�������3^5�� 
����2��3�εģ�����003,012,021,030,102,111,120,201,210,300,ʮ�� 
���Դ𰸾���3^5*10 = 2430
*/ 
 

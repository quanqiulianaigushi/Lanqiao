/*����⻻���Ƕ�����������ǣ�
��1��ʼ��������������ʱ��0-9�е�һ����������2021��
����3181*/ 
#include<bits/stdc++.h>
using namespace std;
int num[10],n=1,ans;

int main(){
	do {
		int tmp = n;
		while(tmp) {
			int a = tmp%10;
			num[a] ++;
			if(num[a]==2021) { ans=n; break; }
			tmp /= 10;
		}
		if(ans!=0) break;
	} while(n++);
	printf("%d\n",ans);
    return 0;
}


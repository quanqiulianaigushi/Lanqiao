/* ��һ���������ӵķ����� 
��������һ�� 1 �� 10 ��ȫ���У� 10��= 3628800 �� 
Ȼ�����ÿһ��ȫ�����ж�һ���Ƿ�������� 
������42 */
#include<bits/stdc++.h>
using namespace std;
int a[10] = {1,2,3,4,5,6,7,8,9,10};
int k = 3628800, cnt=0;
int main(){
	while(k--) {
		next_permutation(a,a+10);
		bool flag = 0;
		for(int i=0; i<=3; i++) //��һ�������ж� 
			if(a[i]>a[i+1]) { flag=1; break; }
		if(flag==1) continue;
		
		for(int i=5; i<=8; i++) //�ڶ��������ж� 
			if(a[i]>a[i+1]) { flag=1; break; }
		if(flag==1) continue;
		
		for(int i=0; i<=4; i++) //�����ж� 
			if(a[i]>a[i+5]) { flag=1; break; } 
		if(flag==1) continue;
		
		cnt++;		
	}	
	printf("%d\n",cnt);
    return 0;
}
 

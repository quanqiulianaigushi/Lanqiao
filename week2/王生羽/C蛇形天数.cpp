#include<bits/stdc++.h>
using namespace std;
int a[50][50];
int main(){
	/*
	���������ż��������� 	
	
	*/ 
	int id=0;//Ҫ����� 
	for(int i=1;i<=40;i++){
		for(int j=0;j<i;j++)  //б����
		{
		  if(i&1){   //����
		  a[i-j][j+1]=++id;	  
		} 
		  else{
		  a[j+1][i-j]=++id;	
		} 
	}
}
	      cout<<a[20][20]<<endl; 
	return 0;
} 


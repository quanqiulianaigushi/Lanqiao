#include <bits/stdc++.h>
using namespace std;

#define ll long long
int main(){
    ll n =  2021041820210418L;
    ll ans = 0;
    for(ll i = 1;i*i*i <=n;i++){
        if(n%i != 0) continue;	//����i����n�����ӣ���continue��
        ll tmp = n / i;
        for(ll j = 1;j*j<= tmp;j++){
            if(tmp % j != 0) continue;//��j����(n/i)�����ӣ���continue��
            ll k = tmp / j;
            if(k < j || i > j)  continue;//������������ǵ�������continue��ȥ��
            if(i == j && i == k) ans +=1;
            else if(i == j || i==k || j==k) ans +=3;
            else ans += 6;
        }
    }
    cout<< ans <<endl;
    return 0;
}


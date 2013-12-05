/*
	IMPLEMENTATION OF SEGMENTED SIEVE
	GIVES PRIME NUMBERS BETWEEN A SPECIFIEDE RANGE
*/
#include<cmath>
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<map>
#include<vector>

using namespace std;
typedef unsigned long long int dt;

#define FOR(i,a,b) for(int i=a;i<b;i++)
#define nl "\n"
#define MOD 10
#define TEN5 100000
#define TEN6 1000000
#define tb "\t"

vector<int> prime(100000);
vector<dt> prs;			// contains the first TEN5 prime numbers
void seg_sieve(dt m,dt n);

int main(void){
	cout.sync_with_stdio(false);
	cin.sync_with_stdio(false);
	dt k,t,m,j,n=TEN5+1,i;
	prs.clear();
	prime[0]=0,prime[1]=0;
	for(k=2;k<n+1;k++)
		prime[k]=1;
	for(k=2;k<n+1;k++)
		if(prime[k]==1){
			prs.push_back(k);
			j=2*k;
			while(j<n+1){
				prime[j]=0;
				j+=k;
			}
		}
	cin>>t;
	while(t--){
		cin>>m>>n;
		if(m>TEN5)
			seg_sieve(m,n);
		else
			if(n>TEN5){
				i=m;
				while(i<TEN5){
					if(prime[i])
						cout<<i<<nl;
				}
				seg_sieve(i,n);	
			}
				
			else
				FOR(i,m,n+1)
					if(prime[i])
						cout<<i<<nl;	
		cout<<nl;
	}
	return 0;
}
void seg_sieve(dt m,dt n){
	dt l=n-m+1,j,k,i,p,x;
	int funp[l];				// CONTAINS THE PRIME NUMBERS BETWEEN RANGE M AND N BOTH INCLUSIVE
	for(k=0;k<l;k++){
		funp[k]=1;
	}
	for(i=0;prs[i]*prs[i]<=n;i++){	
		p=prs[i];
		x=ceil((double)m/(double)p);		// CONTAINS A MULTIPLE OF PRIME WHICH IS JUST >= M
		j=x*p;
		while(j<n+1){
			funp[j-m]=0;
			j+=p;
		
		}		
	}
	for(k=0;k<l;k++){
		if(funp[k]==1)
			cout<<m+k<<nl;
	}		
}

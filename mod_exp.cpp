/*

CALCULATES A^B: 	B = 50 ==> 	B = 32 + 16 + 2		50= 110 010
					  50		32		  16			  2
					A	=    A	*	A	    *		A




*/
int mod_exp(int a,int b){
	int ans=1;
	while(b){
		if(b&1)
			ans=(ans*a) % MOD;
		b>>=1;
		a=(a*a) % MOD;
	}
	return ans;
}		

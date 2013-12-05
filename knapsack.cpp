/*

EXAMPLE TABLE FOR VALUE[] = {16, 19, 23, 28}  WEIGHT[] = {2, 3, 4, 5}

									V=16	V=19	V=23	V=28
									W=2		W=3		W=4		W=5
			CAPACITY	N = 0		1		2		3		4
			0				0		0		0		0		0
			1				0		0		0		0		0
			2				0		16		16		16		16
			3				0		16		19		19		19
			4				0		16		19		23		23
			5				0		16		35		35		35
			6				0		16		35		39		39
			7				0		16		35		42		44
			
			

*/
int knapsack(int capacity,int weight[], int value[]){
	int i,w,table[n+1][capacity+1];
	for(i=0;i<=n;i++){
		for(w=0;w<=capacity;w++){
			if (i==0 || w==0)
				table[i][w]=0;
			else
				if(weight[i-1] <= w)
					table[i][w]=max(value[i-1] + table[i-1][w-weight[i-1]],  table[i-1][w]);
				else
					table[i][w]=table[i-1][w];
		}	
	}
}

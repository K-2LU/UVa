#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAXN 2 << 31
#define L 81

int main() {
	
	char bestname[L];
	char currentname[L];
	int t = 0;
	int n = 0;
	int p = 0;
	int r = 0;
	float price = 0;
	float bestprice = MAXN;
	int naux = n;
	int compliance = 0;
	int bestcompliance = -1;
	bool flag = false;

	while(true) {
		t++;
		scanf("%d%d\n",&n,&p);
		if (n == 0 && p == 0) 
			break;

		if(flag) printf("\n");
		
		naux = n;
		bestprice = MAXN;
		bestcompliance = -1;

		while(naux--) {
			gets(bestname);
			scanf("\n");
		}

		while(p--) {
			gets(currentname);
			scanf("\n");
			scanf("%f%d\n",&price,&r);
						
			compliance = r;

			if (compliance > bestcompliance || (compliance == bestcompliance && bestprice > price)) {
				bestprice = price;
				bestcompliance = compliance;
				strcpy(bestname , currentname);
			}

			while(r--) {
				gets(currentname);
				scanf("\n");
			}
		}

		printf("RFP #%d\n" , t);
		printf("%s\n" , bestname);
		flag = true;
	}

	//system("pause");
	return 0;
}
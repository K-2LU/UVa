#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define N 10000
#define D 11

static char names[N][D];
static int sizes[N];
static int dimensions[D];
static int B[N];
static int L[N][D];
static int U[N][D];
static int C[N][D];
static int idxs[D];

int get_index(char* str) {

	for (int i = 0; i < N; i++) 
		if(strcmp(names[i],str) == 0) return i;
	
	return -1;
}

int main() {
	
	int n = 0;
	int r = 0;
	
	char aux_name[D];

	scanf("%d %d",&n,&r);

	for (int i = 0; i < n; i++) {
		scanf("%s %d %d %d",&names[i],&B[i],&sizes[i],&dimensions[i]);

		for (int j = 0; j < dimensions[i]; j++) {
			scanf("%d",&L[i][j + 1]);
			scanf("%d",&U[i][j + 1]);
		}

		C[i][dimensions[i]] = sizes[i];
		int aux = C[i][dimensions[i]] * L[i][dimensions[i]];

		for (int d = dimensions[i] - 1; d > 0; d--) {
			C[i][d] = C[i][d + 1] * (U[i][d + 1] - L[i][d + 1] + 1);
			
			aux += C[i][d] * L[i][d];
		}

		C[i][0] = B[i] - aux;
	}

	for (int i = 0; i < r; i++) 	{
		scanf("%s",&aux_name);

		int index = get_index(aux_name);
		int result = 0;
		int d = dimensions[index];

		for (int j = 0; j < d; j++) {
			scanf("%d",&idxs[j]);
			result += idxs[j] * C[index][j + 1];
		}

		result += C[index][0];
		printf("%s[",aux_name);

		for (int j = 0; j < d - 1; j++) {
			printf("%d, ",idxs[j]);
		}

		printf("%d] = %d\n",idxs[d - 1],result);
	}

	//system("pause");
	return 0;
}
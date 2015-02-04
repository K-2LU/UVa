#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define N 21

static bool devices[N];
static int capacity[N];

int main() {
	int t = 0;
	int n = 0;
	int m = 0;
	int c = 0;
	int current_capacity = 0;
	int max_capacity = 0;
	int index = 0;
	bool blown = false;

	while(true) {
		memset(devices,false,sizeof(devices));
		current_capacity = 0;
		max_capacity = 0;
		blown = false;
		t++;
		scanf("%d %d %d", &n, &m, &c);

		if(n == 0 && m == 0 && c == 0) break;

		for (int i = 0; i < n; i++) 
			scanf("%d", &capacity[i]);

		for (int i = 0; i < m; i++) {
			scanf("%d", &index);
			index--;
			if (!devices[index]) {
				current_capacity += capacity[index];

				if(current_capacity > c)
					blown = true;

				if(current_capacity > max_capacity)
					max_capacity = current_capacity;
			}
			else 
				current_capacity -= capacity[index];

			devices[index] = !devices[index];
		}

		printf("Sequence %d\n", t);
		if(blown)
			printf("Fuse was blown.\n\n");
		else {
			printf("Fuse was not blown.\n");
			printf("Maximal power consumption was %d amperes.\n\n",max_capacity);
		}
	}

	//system("pause");
	return 0;
}
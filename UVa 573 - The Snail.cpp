#include <stdlib.h>
#include <stdio.h>

#define N 1000

int main() {
	
	int H = 0;
	int U = 0;
	int D = 0;
	int F = 0;
	int day = 0;
	bool sucess = false;
	float factor = 0;
	float height = 0;
	float current_distance = 0;

	while(1) {
		scanf("%d %d %d %d",&H,&U,&D,&F);

		if(H == 0) break;
		
		day = 1;
		sucess = false;
		factor = (F * U) / 100.0;
		height = 0;
		current_distance = U;
		
		while(true) {
			height += (current_distance < 0) ? 0 : current_distance;

			if (height > H) {
				sucess = true;
				break;
			}

			current_distance -= factor; //substract the factor
			height -= D;

			if (height < 0) 
				break;

			day++;
		}

		printf("%s on day %d\n",sucess ? "success":"failure" , day);
	}

	//system("pause");
	return 0;
}
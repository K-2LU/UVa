#include <stdlib.h>
#include <stdio.h>

double get_hour(int h, int m, int s) {
	return h + m / 60.0 + s / 3600.0;
}

int main() {
	
	int h = 0; int hc = 0;
	int m = 0; int mc = 0;
	int s = 0; int sc = 0;
	float speed = 0;
	float distance = 0;
	float t = 0;
	char x = ' ';

	while(scanf("%d:%d:%d",&hc,&mc,&sc) != EOF) {
		x = getchar();

		t = get_hour(hc,mc,sc) - get_hour(h,m,s);
		distance += t * speed;

		if (x == ' ') {
			scanf("%f\n",&speed);
		}
		else {
			if(hc < 10) printf("0"); printf("%d:",hc);
			if(mc < 10) printf("0"); printf("%d:",mc);
			if(sc < 10) printf("0"); printf("%d",sc);
			printf(" %.2f km\n",distance);
		}
		h = hc; m = mc; s = sc;
	}
	//system("pause");
	return 0;
}
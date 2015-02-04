#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define N 1000

static char buffer[N];
static char copybuffer[N];

int main() {
	
	int n = 0;
	const char s[2] = " ";
	char *token;
	int total= 0;
	
	while(gets(buffer) != NULL) {

		total = 0;	
		token = strtok(buffer,s);

		while(token != NULL) {
			n = strlen(token);

			for (int i = n - 1; i >= 0; i--) 
				copybuffer[total++] = token[i];
			
			copybuffer[total++] = ' ';
			token = strtok(NULL, s);
		}
		
		copybuffer[--total] = '\0';
		printf("%s\n",copybuffer);
	}

	//system("pause");
	return 0;
}
#include <stdlib.h>
#include <stdio.h>

int main() {
	bool open = true;
	char aux = ' ';

	while((aux = getchar()) != EOF) {
		if(aux == '"') {
			if(open) 
				printf("``");
			else 
				printf("''");
			open = !open;
		}
		else printf("%c",aux);
	}
	//system("pause");
	return 0;
}
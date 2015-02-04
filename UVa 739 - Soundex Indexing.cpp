#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define N1 21
#define N2 5

char S[N1];
char CODE[N2];

char get_code(char ch) {
	if (ch == 'B' || ch == 'P' || ch == 'F' || ch == 'V') return '1';
	if (ch == 'C' || ch == 'S' || ch == 'K' || ch == 'G' || ch == 'J' || ch == 'Q' || ch == 'X' || ch == 'Z') return '2';
	if (ch == 'D' || ch == 'T') return '3';
	if (ch == 'L') return '4';
	if (ch == 'M' || ch == 'N') return '5';
	if (ch == 'R') return '6';

	return '0';
}

int main() {
	
	printf("         NAME                     SOUNDEX CODE\n");
	while(scanf("%s",&S) != EOF) {
		CODE[0] = S[0];
		int n = strlen(S);
		int code_index = 1;

		for (int i = 1; i < n && code_index < N2 - 1; i++) {
			if (get_code(S[i]) == '0') continue;
			if (get_code(S[i - 1]) == get_code(S[i])) {
				continue;
			}
			//if (i > 0)
			CODE[code_index++] = get_code(S[i]);
		}
		//padding
		while(code_index < N2 - 1) CODE[code_index++] = '0';

		printf("         %s",S); //10 spaces
		int s = 25 - n;
		while(s--) printf(" ");
		
		CODE[N2] = '\0';
		printf("%s\n", CODE);
	}
	printf("                   END OF OUTPUT\n");

	//system("pause");
	return 0;
}
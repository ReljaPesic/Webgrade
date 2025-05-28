#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {
	if(argc < 2) {
		printf("-1\n");
		return 1;
	}

	int max_duzina = -1;
	for(int i = 1; i < argc; i++) {
	  if((int)strlen(argv[i]) > max_duzina) {
	  	max_duzina = (int)strlen(argv[i]);
	  }
	}

	printf("%d\n", max_duzina);


	return 0;
}

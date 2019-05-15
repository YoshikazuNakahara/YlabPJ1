#include <stdio.h>
#include <stdlib.h>
#include "../stack/stack.h"
#include "keywords.h"

int
main(void){
	Keywords key;
	Keywords* kp = &key;
	char* buf;
	readkeywords(kp);
	for (int i = 0;key.left[i] != NULL;i++) {
			printf("Keywords: ");
			printf("%s, ", key.left[i]);
	}

	printf("\n");

	for (int i = 0;key.right[i] != NULL;i++) {
			printf("Keywords: ");
			printf("%s, ", key.right[i]);
		return 0;
	}
//void checkLeftKeywords(const Keywords, const char);
//void checkRightKeywords(const Keywords, const char);

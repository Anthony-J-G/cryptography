#include "hash.h"
#include <stdio.h>

#include <iostream>

int main() {

	printf("Library Initialization: %d\n\n\n", sha256::init());
	sha256::execute("abc", 1);




}
#include "hash.h"



namespace sha256 {

	/*
	*  Just a simple function to test the linker
	*/
	int init() {
		return 1;
	}

	/*
	*  Actual hash function execution
	*/
	std::string execute(const std::string& word, bool debug) {

		if (debug == true) {
			printf("plaintext: %s\n", word.c_str());
			printf("byte array: [");
			for (int i = 0; i < word.length(); i++) {
				if (i != word.length() - 1) { printf("%d, ", word[i]); }
				else { printf("%d]", word[i]); }
			}
			printf("\n");



			std::cin.get();

			
		}
		

		return u8"Test";

	}

}
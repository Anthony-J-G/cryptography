#include "hash.h"


using namespace binary_functions;
using namespace std;

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
	string execute(const string& plaintext, bool debug = 0) {

		// Initialization Step
		Sentence bit_words = Sentence(plaintext);
		// Visualization
		if (debug) {
			printf("---------------\n");
			printf("Initialization:\n");
			printf("---------------\n");
			printf("plaintext: %s\n", plaintext.c_str());
			printf("byte array: [");
			for (unsigned int i = 0; i < plaintext.length(); i++) {
				if (i != plaintext.length() - 1) { printf("%d, ", plaintext[i]); }
				else { printf("%d", plaintext[i]); }
			}
			printf("]\n");
			printf("bin string: %s", bit_words.to_string().c_str());
			printf("\n\n");
			cin.get();
		}

		// Padding Step
		int num_blocks = ((int) bit_words.size / BLOCK_SIZE) + 1;
		int padding_size = (num_blocks * BLOCK_SIZE) - bit_words.size - SENTENCE_LENGTH_SPACING;

		bitset<BLOCK_SIZE> padded_sentences[num_blocks];

		for (unsigned int i = 0; i < bit_words.size; i++) {


		}


		
		// Visualization
		if (debug) {
			printf("---------------\n");
			printf("Padding: (%d bits + %d bits + %d bits = %d bits)\n", bit_words.size, padding_size, SENTENCE_LENGTH_SPACING, bit_words.size + padding_size + SENTENCE_LENGTH_SPACING);
			printf("---------------\n");
			printf("%s\n", padded_sentences[0].to_string().c_str());


			cin.get();
		}

		return u8"Test";

	}

}
#include "hash.h"


using namespace binary_functions;
using namespace std;


namespace sha256 {

	// Supplementary functions
	bitset<BLOCK_SIZE> sigma_0();

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
				if (i > 10) {
					printf("...");
					break;
				}
			}
			printf("] (%d characters)\n", bit_words.length);
			printf("bin string: %s (%d bits)", bit_words.to_string().c_str(), bit_words.size);
			
			printf("\n\n");
			cin.get();
		}

		// Padding Step
		int num_blocks = ((int) bit_words.size / BLOCK_SIZE) + 1;
		int padding_size = (num_blocks * BLOCK_SIZE) - bit_words.size - SENTENCE_LENGTH_SPACING;

		bitset<BLOCK_SIZE> *padded_sentences;
		padded_sentences = new bitset<BLOCK_SIZE>[num_blocks];

		// Fill the Padded Sentence with Original Sentence data
		unsigned int i = 0;
		int j = WORD_LEN - 1;
		int k = 0;
		int w = BLOCK_SIZE - 1;
		int x = 0;
		for (i; i < bit_words.size; i++) {
			if ( (i != 0) * (i % WORD_LEN == 0) ) {
				j = WORD_LEN - 1;
				k++;
			}
			if ( (i != 0) * (i % BLOCK_SIZE == 0) ) {
				w = BLOCK_SIZE - 1;
				x++;
			}
			padded_sentences[x].set( w, bit_words.words[k].test(j) );

			j--;
			w--;
		}

		// Set 1st Padding Bit to 1
		if (w == -1) {
			w = BLOCK_SIZE - 1;
			x++;
		}
		padded_sentences[x].set(w, 1);

		// Set last 64 bits to record the length of the message
		bitset<SENTENCE_LENGTH_SPACING> s(bit_words.size);
		x = num_blocks - 1;
		w = SENTENCE_LENGTH_SPACING;
		for (i = 0; i < SENTENCE_LENGTH_SPACING; i++) {
			padded_sentences[x].set( i, s.test(i) );
		}		
		// Visualization
		if (debug) {
			printf("---------------\n");
			printf("Padding: (%d bits + %d bits + %d bits = %d bits)\n", bit_words.size, padding_size, SENTENCE_LENGTH_SPACING, bit_words.size + padding_size + SENTENCE_LENGTH_SPACING);
			printf("Number of Blocks: %d\n", num_blocks);
			printf("---------------\n");
			printf("Block 0:\t");
			printf("%s\n", padded_sentences[0].to_string().c_str());


			cin.get();
		}

		delete[] padded_sentences;

		return u8"Test";

	}

	bitset<BLOCK_SIZE> sigma_0() {

		bitset<BLOCK_SIZE> tmp;

		return tmp;

	}

}
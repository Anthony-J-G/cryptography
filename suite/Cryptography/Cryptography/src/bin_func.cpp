#include "support.h"




using namespace std;


namespace binary_functions {

	Sentence::Sentence(const std::string& msg) {
		length = msg.length();
		size = length * WORD_LEN;

		words = (bitset<WORD_LEN>*) malloc(sizeof(bitset<WORD_LEN>) * length);

		for (unsigned int i = 0; i < length; i++) {
			bitset<WORD_LEN> temp(msg[i]);
			*(words + i) = temp;	
		}

	}

	Sentence::~Sentence() {
		
	}

	string Sentence::to_string() {

		string representation = "";
		for (unsigned int i = 0; i < length; i++) {
			string temp = words[i].to_string();
			representation = representation + temp;
			
		}


		return representation;
	}

	string Sentence::decode() {
		return "temp";
	}




	void temp() {

	}
}

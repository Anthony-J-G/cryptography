#include "support.h"




using namespace std;


namespace binary_functions {

	Sentence::Sentence(const std::string& msg) {
		length = msg.length();
		size = length * WORD_LEN;
		words = new bitset<WORD_LEN>[length];

		for (unsigned int i = 0; i < length; i++) {
			bitset<WORD_LEN> temp(msg[i]);
			words[i] = temp;
		}

	}

	Sentence::~Sentence() {
		
	}

	string Sentence::to_string() {

		string representation = "";
		unsigned int i_max = length;
		if (length > MAX_STRING_LEN) {
			i_max = MAX_STRING_LEN - 2;
		}
		for (unsigned int i = 0; i < i_max; i++) {
			string temp = words[i].to_string();
			representation = representation + temp;
		}

		if (length <= MAX_STRING_LEN) {
			return representation;
		}

		representation = representation + " . . . ";
		for (unsigned int i = length - 2; i < length; i++) {
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

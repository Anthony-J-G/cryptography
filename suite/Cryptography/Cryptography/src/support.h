#pragma once

// C Includes
#include <stdlib.h>
#include <stdio.h>

// C++ Includes
#include <iostream>
#include <string>
#include <vector>
#include <bitset>



// Constants
#define WORD_LEN 8
#define BLOCK_SIZE 512
#define SENTENCE_LENGTH_SPACING 64



namespace binary_functions {

	/*	Structure that holds an array of binary represented words
	*		as well as any useful supporting data
	
	*/
	class Sentence
	{
		public:
			// Variables
			unsigned int length; // Length of the initial string
			unsigned int size; // Size of the result bit array in bits
			std::bitset<WORD_LEN>* words;
			

			// Functions
			Sentence(const std::string& msg);
			~Sentence();
			std::string to_string();
			std::string decode();


		private:

	};

	void temp();
}
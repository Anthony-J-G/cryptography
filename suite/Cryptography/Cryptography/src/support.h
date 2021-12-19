#pragma once

// C Includes
#include <stdlib.h>
#include <stdio.h>

// C++ Includes
#include <iostream>
#include <string>
#include <vector>
#include <bitset>






namespace binary_functions {
	// Constants
	#define WORD_LEN 8
	#define MAX_STRING_LEN 50

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
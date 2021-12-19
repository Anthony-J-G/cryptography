
// C Includes
#include <stdio.h>
#include <stdlib.h>

// C++ Includes
#include <fstream>
#include <istream>
#include <iostream>
#include "hash.h"


// Constants
#define FILE_FLAG_1 "-F"
#define FILE_FLAG_2 "-file"

#define OUTPUT_FLAG_1 "-O"
#define OUTPUT_FLAG_2 "-output"

#define INPUT_FLAG_1 "-I"
#define INPUT_FLAG_2 "-input"

#define VISUALIZE_FLAG_1 "-V"
#define VISUALIZE_FLAG_2 "-visualize"



using namespace std;


int main(int argc, char* argv[]) {

	// File Flag
	bool fflag = 0; 
	string ifilename = "";

	// Output Flag
	bool oflag = 0; 
	string ofilename = "";

	// Input Flag
	bool iflag = 0; 
	int input_loc;

	bool vflag = 0;


	// Parse arguments
	for (uint16_t i = 1; i < argc; i++) {
		string tmp = argv[i];
		bool fflag_check = (tmp.compare(FILE_FLAG_1) == 0) + (tmp.compare(FILE_FLAG_2) == 0);
		if (fflag_check * (i != (argc - 1))) {
			fflag = 1; // Set flie flag if file input is wanted
			ifilename = argv[i + 1];
		}
		bool oflag_check = (tmp.compare(OUTPUT_FLAG_1) == 0) + (tmp.compare(OUTPUT_FLAG_2) == 0);
		if (oflag_check * (i != (argc - 1))) {
			oflag = 1; // Set output flag if execution produces an output file
			string ofilename = argv[i + 1];

		}
		bool iflag_check = (tmp.compare(INPUT_FLAG_1) == 0) + (tmp.compare(INPUT_FLAG_2) == 0);
		if (iflag_check) {
			iflag = 1;
			input_loc = i + 1;
		}
		bool vflag_check = (tmp.compare(VISUALIZE_FLAG_1) == 0) + (tmp.compare(VISUALIZE_FLAG_2) == 0);
		if (vflag_check) {
			vflag = 1;
		}
	}
	// Check to see if file exists
	ifstream fptr{ ifilename };
	if (fflag && !fptr) {
		printf("Error: file '%s' not found in local directory\n", ifilename.c_str());
		system("pause");
		return 1;
	}
	// Read data from a file
	string fileread = "";
	while (fflag && fptr) {
		// Read strings from the file and store in 'fileread' var
		string file_data;
		getline(fptr, file_data);
		fileread = fileread + file_data;
	}

	string input = "";
	if (iflag) {
		for (int i = input_loc; i < argc ; i++) {
			string tmp = argv[i];
			input = input + tmp;
		}
	}

	// Running sha256 Encryption
	printf("**Library Initialization: %d**\n\n", sha256::init());

	if (fflag) {
		sha256::execute(fileread, vflag);
	}

	if (iflag) {
		sha256::execute(input, vflag);
	}
	
	
	cin.get();
}
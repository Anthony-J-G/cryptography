#pragma once

// C Includes
#include <stdio.h>
#include <stdlib.h>

// C++ Includes
#include <string>
#include <iostream>
#include "support.h"


// Constants
#define BLOCK_SIZE 512
#define SENTENCE_LENGTH_SPACING 64





namespace sha256 {

	int init();

	std::string execute(const std::string& word, bool debug);

}
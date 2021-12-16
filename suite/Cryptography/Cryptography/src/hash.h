#pragma once

// C Includes
#include <stdio.h>
#include <stdlib.h>

// C++ Includes
#include <string>
#include <iostream>


// Constants





namespace sha256 {

	int init();

	std::string execute(const std::string& word, bool debug);

}
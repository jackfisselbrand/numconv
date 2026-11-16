#include "numconv.h"

#include <iostream>
#include <cstdlib>
#include <string>

std::string convert(std::string input, int inbase, int outbase) {
	std::string digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	/* Convert the input string to an integer */
	char *end = &input.at(input.size() - 1);
	long long num = strtol(input.c_str(), &end, inbase);
	if (*end != '\0') {
		return "Not a valid number.";
	}

	/* Convert the integer num to a (backwards) result string */
	std::string tmp = {};
	for (int i=0; num>0; i++) {
		tmp.push_back(digits.at(num % outbase));
		num /= outbase;
	}

	/* Flip the result string so that the output isn't backwards */
	std::string output = "\0";
	for (int i=0; i<tmp.length(); i++) {
		output.push_back(tmp.at(tmp.length()-(i+1)));
	}

	return output;
}
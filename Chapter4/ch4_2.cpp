#include <math.h>
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

std::vector<double> squares(int range) {
	std::vector<double> result;
	for (std::vector<double>::size_type i = 0; i <= range; i++) {
		result.push_back(i * i);
	}
	return result;
}

unsigned int digitLength(double num) {
	unsigned int len = 0;
	while (num >= 1) {
		num /= 10;
		len++;
	}
	return len;
}

std::ostream& print_squares(std::ostream& out, std::vector<double>& squares) {
	if (out) {
		std::streamsize s_size = out.width();
		unsigned int square_len = 1 + digitLength(squares[squares.size() - 1]);
		unsigned int num_len = 1 + square_len % 2 == 0 ? square_len / 2 + 1 : square_len / 2;
		for (std::vector<double>::size_type i = 1; i < squares.size(); i++) {
			out << std::setw(num_len) << i << std::setw(square_len)
				<< squares[i] << std::endl;
			out.width(s_size);
		}
	}
	return out;
}

int ch4_2(int num) {
	std::vector<double> v = squares(num);
	print_squares(std::cout, v);
	return 0;
}
#include <iostream>
#include <sstream>
#include <math.h>

int main() {
	std::string retStr = "P2\n";
	std::stringstream ss;
	float num;
	int max = 1;
	int i = 0;
	while (std::cin.read(reinterpret_cast<char *>(&num), sizeof(float))) {
		++i;
		if ((int)num > max) {
			max = (int)num;
		}
		if (i % 17 == 0) { // this ensures that no line will be longer than 70 characters
			ss << "\n";
		}
		ss << " " << (int)num << " ";
	}

	int dim = (int)sqrt(i);
	retStr = retStr + std::to_string(dim) + " " + std::to_string(dim) + "\n" + std::to_string(max) + "\n" + ss.str();
	std::cout << retStr;
	return 0;
}

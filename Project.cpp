#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstdint>

int main() {
	uint32_t iterations;// = 0;
	float epsilon;// = 0.1;
	//uint32_t SIZE = 1024;
	uint32_t HSIZE;// = SIZE; //num columns
	uint32_t VSIZE;// = SIZE; //num rows

	//std::cout.write(reinterpret_cast<char const *>(&iterations), sizeof(uint32_t));
	//std::cout.write(reinterpret_cast<char const *>(&epsilon), sizeof(float));
	//std::cout.write(reinterpret_cast<char const *>(&VSIZE), sizeof(uint32_t));
	//std::cout.write(reinterpret_cast<char const *>(&HSIZE), sizeof(uint32_t));

	std::cin.read(reinterpret_cast<char *>(&iterations), sizeof(uint32_t));
	std::cin.read(reinterpret_cast<char *>(&epsilon), sizeof(float));
	std::cin.read(reinterpret_cast<char *>(&VSIZE), sizeof(uint32_t));
	std::cin.read(reinterpret_cast<char *>(&HSIZE), sizeof(uint32_t));

	std::vector<std::vector<float>> theArray(VSIZE, std::vector<float>(HSIZE));
	std::vector<std::vector<float>> tempArray(VSIZE, std::vector<float>(HSIZE));

	bool cont = true;

	for (uint32_t i = 0; i < VSIZE; i++) {
		for (uint32_t j = 0; j < HSIZE; j++) {
			/*if (i == 0 || i == HSIZE - 1 ||
				j == 0 || j == VSIZE - 1) {
				theArray[i][j] = 0;
				tempArray[i][j] = 0;
			}
			else {
				theArray[i][j] = 50;
				tempArray[i][j] = 50;
			}*/
			std::cin.read(reinterpret_cast<char *>(&theArray[i][j]), sizeof(float));
			//std::cout.write(reinterpret_cast<char const *>(&theArray[i][j]), sizeof(float));
		}
	}

	while (cont) {
		++iterations;
		for (uint32_t i = 1; i < VSIZE - 1; i++) {
			for (uint32_t j = 1; j < HSIZE - 1; j++) {
				tempArray.at(i).at(j) = (theArray.at(i - 1).at(j) + theArray.at(i + 1).at(j) + theArray.at(i).at(j - 1) + theArray.at(i).at(j + 1)) / 4.0f;
			}
		}
		std::swap(tempArray, theArray);
		bool stable = true;
		for (uint32_t i = 1; i < VSIZE - 1; i++) {
			for (uint32_t j = 1; j < HSIZE - 1; j++) {
				bool s;
				float avg = (theArray.at(i - 1).at(j) + theArray.at(i + 1).at(j) + theArray.at(i).at(j - 1) + theArray.at(i).at(j + 1)) / 4.0f;
				if (std::abs(theArray.at(i).at(j) - avg) < epsilon) {
					s = true;
				}
				else {
					s = false;
				}
				if (!s) {
					stable = false;
				}
			}
		}
		if (stable) {
			cont = false;
			//std::cout << iterations;
			//std::cout.write(reinterpret_cast<char const *>(&iterations), sizeof(uint32_t));
		}
	}

	for (uint32_t i = 0; i < VSIZE; i++) {
		for (uint32_t j = 0; j < HSIZE; j++) {
			std::cout.write(reinterpret_cast<char const *>(&theArray[i][j]), sizeof(float));
		}
	}

//	system("pause");
	return 0;
}

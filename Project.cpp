#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

unsigned const int SIZE = 1024;

unsigned const int HSIZE = SIZE;
unsigned const int VSIZE = SIZE;

int main() {

	std::vector<std::vector<float>> theArray(SIZE, std::vector<float>(SIZE));
	std::vector<std::vector<float>> tempArray(SIZE, std::vector<float>(SIZE));
	int countReps = 0;
	bool cont = true;

	for (unsigned int i = 0; i < VSIZE; i++) {
		for (unsigned int j = 0; j < HSIZE; j++) {
			if (i == 0 || i == HSIZE - 1 ||
				j == 0 || j == VSIZE - 1) {
				theArray[i][j] = 0;
				tempArray[i][j] = 0;
			}
			else {
				theArray[i][j] = 50;
				tempArray[i][j] = 50;
			}
		}
	}

	while (cont) {
		++countReps;
		for (unsigned int i = 1; i < VSIZE - 1; i++) {
			for (unsigned int j = 1; j < HSIZE - 1; j++) {
				tempArray.at(i).at(j) = (theArray.at(i - 1).at(j) + theArray.at(i + 1).at(j) + theArray.at(i).at(j - 1) + theArray.at(i).at(j + 1)) / 4.0f;
			}
		}
		std::swap(tempArray, theArray);
		bool stable = true;
		for (unsigned int i = 1; i < VSIZE - 1; i++) {
			for (unsigned int j = 1; j < HSIZE - 1; j++) {
				bool s;
				float threshold = 0.1;
				float avg = (theArray.at(i - 1).at(j) + theArray.at(i + 1).at(j) + theArray.at(i).at(j - 1) + theArray.at(i).at(j + 1)) / 4.0f;
				if (std::abs(theArray.at(i).at(j) - avg) < threshold) {
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
			std::cout << "\nIt ran " << countReps << " times.\n\n";
		}
	}

	return 0;
}

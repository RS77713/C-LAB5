#include <iostream>
#include <cstdlib>
#include <time.h>

/*int main() {

	int taskVarCount = 30;
	int studentCode = 83994;
	int taskNr = studentCode % taskVarCount;
	std::cout << "Task number is: " << taskNr << std::endl;
	//task 24
}*/

void fillArrayManual(int** arr,int rows, int cols) {
	std::cout << "Enter elements for array: " << std::endl;
	int i = 0, j = 0;
	while (i < rows) { j = 0; 
		while (j < cols) {
		std::cout << "Enter element at position (" << i << ", " << j + 1 << "): " << std::endl;
		std::cin >> arr[i][j];
		j++;
		}
		i++;
	}
}

void fillWithRandomArray(int** arr, int rows, int cols, int min, int max) {
	srand(time(0));

	int i = 0, j = 0;
	while (i < rows) {
		j = 0;
		while (j < cols) {
			arr[i][j] = rand() % (max - min + 1) + min;
			j++;
		}
		i++;
	}
}

void calculateColumnAVG(int** arr, int rows, int cols, double* AVG) {
	int j = 0;
	while (j < cols) {
		double sum = 0;
		int i = 0;
		while (i < rows) {
			sum += arr[i][j];
			i++;
		}
		AVG[j] = sum / rows;
		j++;
	}
}

void displayArray(int** arr, int rows, int cols) {
	std::cout << "Array: " << std::endl;
	int i = 0;
	while (i < rows) {
		int j = 0;
		while (j < cols) {
			std::cout << arr[i][j] << "\t";
			j++;
		}
		std::cout << std::endl;
		i++;
	}
}

int main() {
	int rows, cols;
	std::cout << "Enter how many rows: " << std::endl;
	std::cin >> rows;
	std::cout << "Enter how many columns: " << std::endl;
	std::cin >> cols;

	int** array = new int*[rows];
	int i = 0;
	while (i < rows) {
		array[i] = new int[cols];
		i++;
	}

	int choose;
	bool validChoice = false;
	int wrongAttemts = 0;
	const int maxwrongAttempts = 3;
	while (!validChoice) {
		std::cout << "Select way how to fill array:\n";
		std::cout << "Manually: 1 \n";
		std::cout << "Automatically: 2 \n";
		std::cout << "Enter your choice 1 or 2?:\n";
		std::cin >> choose;

		if (choose == 1) {

			fillArrayManual(array, rows, cols);
			validChoice = true;
		}
		else if (choose == 2) {
			int min, max;
			std::cout << "Enter the MIN range for random numbers: " << std::endl;
			std::cin >> min;
			std::cout << "Enter the MAX range for random numbers: " << std::endl;
			std::cin >> max;
			fillWithRandomArray(array, rows, cols, min, max);
			validChoice = true;
		}
		else {
			wrongAttemts++;
			std::cout << "Invalid choice. Please choose again how to fill array!" << std::endl;
			if (wrongAttemts == maxwrongAttempts) {
				std::cout << "Too many wrong attempts. Exiting the program." << std::endl;
				return 1;
			}else{
				std::cout << "You have " << maxwrongAttempts - wrongAttemts << " attepmts left!" << std::endl;
			}
		}
	}

	displayArray(array, rows, cols);

	double threshold;
	std::cout << "Enter the threshold value for column AVG: " << std::endl;
	std::cin >> threshold;

	double* columnAVG = new double[cols];
	calculateColumnAVG(array, rows, cols, columnAVG);

	std::cout << "Columns with average greater than " << threshold << ":" << std::endl;
	int j = 0;
	while (j < cols) {
		if (columnAVG[j] > threshold) {
			std::cout << "Column " << j + 1 << " has average: " << columnAVG[j] << std::endl;
		}
		j++;
	}

	i = 0;
	while (i < rows) {
		delete[] array[i];
		i++;
	}
	delete[] array;
	delete[] columnAVG;
	
	return 0;
}
//Create an algorithm that solves individual task by using 2D arrays.
//Define number of columns where element average is greater than some value specified by user.
//based on created algorithm by using dynamic two-dimensional array of integer(!) numbers with size nxm (n and m are entered by user). 
// Implement two ways of array filling: manual (array elements are entered by user) and automatic (array elements are random numbers generated in user specified range). 
//User should be able to select a way of filling (for this create a menu for the user).
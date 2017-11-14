#include <cstdlib>
#include <iostream>
#include <ctime>

//returns the index of the chosen individuals
int* getIndividualsFromCumulativeProbability(float cumulative[], float random_probability[], int size) {
	//all values in arrays shall be in the range [0, 1]
	int *individuals = new int[size];
	for (int i = 0; i < size; i++) {
		//TODO: implement binary search
		for (int j = 0; j < size; j++) {
			if (random_probability[i] <= cumulative[j]) {
				individuals[i] = j;
				break;
			}
		}
	}
	return individuals;
}

//returns indexes of individuals chosen for reproduction
//fitness stores the fitness value of each individual. Ordered by index
//size is the size of the fitness[] array
int* selection(int fitness[], int size) {
	//Generates array with cumulative probability on a given individual to be chosen
	float total_fitness = 0;
	for (int i = 0; i < size; i++) {
		total_fitness += fitness[i];
	}

	float probabilities [size];
	probabilities[0] = fitness[0] / total_fitness;
	for (int i = 1; i < size - 1; i++) {
		probabilities[i] = fitness[i] / total_fitness;
		probabilities[i] += probabilities[i - 1];
	}
	probabilities[size - 1] = 1;

	//generates random numbers in the range [0, 1] to select the individuals
	//accordingly to the cumulative probability
	std::srand(std::time(0));
	float random_probability[size];
	for (int i = 0; i < size; i++) {
		random_probability[i] = (float)std::rand() / (RAND_MAX);
	}
	return getIndividualsFromCumulativeProbability(probabilities, random_probability, size);
}

int main() {
	int fitness[3] = {10, 7, 4};
	int* individuals = selection(fitness, 3);
	for (int i = 0; i < 3; i++) {
		std::cout << individuals[i] << " ";
	}
	std::cout << std::endl;
	//REMEMBER TO DEALLOCATE
	delete[] individuals; //TODO: remember to deallocate
	//REMEMBER TO DEALLOCATE
	return 0;
}
#include <iostream>
#include <iomanip>
#include <random>

void mutacao(bool *sol_nelite, bool *sol_elite, int qtd_vertices){

	bool filho[qtd_vertices];
	std::random_device rd;
	std::mt19937 e2(rd());
	std::normal_distribution<> dist(0.0, 1.0);
	srand(time(NULL));

	for (int i = 0; i < qtd_vertices; ++i)
	{
		
		float alfa = dist(e2);
		float gama = 0.6;
		if (alfa <= gama){

			filho[i] = sol_elite[i];

		}
	}

	for (int i = 0; i < qtd_vertices; ++i)
	{
		if (filho[i] == NULL){
			filho[i] = sol_nelite[i];
		}
	}

	for (int i = 0; i < qtd_vertices; ++i)
	{
		if (filho[i] == NULL){
			filho[i] = true;
		}
	}
	
	
	

}
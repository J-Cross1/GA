#include <iostream>
#include <fstream>
#include <random>
#include <string>

struct individual
{
	int chromosone[16];
	float fitness;
	float Dx = 1, Dy = 1;
} ind;

float fitness(float Dx, float Dy, float fitness);
void print(std::vector<int> const &input);


int main()
{
	std::default_random_engine generator;
	std::uniform_real_distribution<double> distribution(0.0, 1.0);
	//int random = distribution(generator);
	int moveLimit = 30;
	int populationSize[20000];
	float mutationChance = 0.5;

	std::ifstream file("../Labs15and16TerrainFile2.txt");
	//std::string str;

	//file.open("../Labs15and16TerrainFile2.txt");
	std::string str[10], string;

	int loop = 0;

	//std::vector< double > values;
	//double val;
	//while (file >> val)
	//{
	//	values.push_back(val);
	//}

	if (file.is_open())
	{
		while (!file.eof())
		{
			std::getline (file, string);
			str[loop] = string;
			std::cout << str[loop] << std::endl;
			loop++;
		}
	}

	if (!file.is_open())
	{
		std::cout << "file is not open";
	}
	
	std::cout << str[0] << std::endl;

	for (int i = 0; i < 16; i++)
	{
		double random = distribution(generator);
		if (random >= 0.5)
		{
			ind.chromosone[i] = 1;
		}
		else
		{
			ind.chromosone[i] = 0;
		}
		std::cout << ind.chromosone[i];
	}

	ind.fitness = fitness(ind.Dx, ind.Dy, ind.fitness);
	std::cout << std::endl << ind.fitness << std::endl;

	file.close();

	system("PAUSE");
	return 0;
}

float fitness(float Dx, float Dy, float fitness)
{
	fitness = 1/( Dx + Dy + 1);

	return fitness;
}

void print(std::vector<int> const &input)
{
	//std::cout << "     " << input.size << std::endl;
	for (int i = 0; i < input.size(); i++)
	{
		std::cout << input.at(i) << " ";
	}
}
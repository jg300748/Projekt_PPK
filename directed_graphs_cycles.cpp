#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include "functions.h"

int main(int argc, char* argv[])
{
	if (argc < 2)
	{
		std::cout << "Program zostal wywolany bez parametrow. Poprawne wywolanie programu powinno wygladac w taki sposob:\ndirected_graphs_cycles.exe -g <PLIK_Z_DANYMI_WEJSCIOWYMI> -c <PLIK_Z_DANYMI_WYJSCIOWYMI>\n";
		return 0;
	}

	int input_file{ 0 }, output_file{ 0 };
	for (int i = 0; i < argc; i++)
	{
		if (std::string(argv[i]) == "-g")
			input_file = i + 1;
		else if (std::string(argv[i]) == "-c")
			output_file = i + 1;
	}
	if (input_file == 0 || output_file == 0)
	{
		std::cout << "Zostały podane nieprawidłowe parametry!\n";
		return 0;
	}

	Digraph digraph;
	std::vector<std::vector<int>> vCycles;
	std::ifstream iFile(argv[input_file]);
	std::ofstream oFile(argv[output_file]);

	if (!iFile || !oFile) { iFile.close(); oFile.close(); std::cerr << "Wystapil blad podczas otwierania pliku!"; return 0; }

	if (not make_digraph(iFile, digraph))
	{
		std::cerr << "Wystapil blad podczas odczytywania danych z pliku. Sprawdz czy format danych jest prawidlowy, czyli:\n<WIERZCHOLEK> -> <WIERZCHOLEK>\nPoszczegolne krawedzie powinny byc oddzielone przecinkiem.";
		iFile.close();
		oFile.close();
		return 0;
	}
	
	if (search_cycles(digraph, vCycles))
	{
		for (int i = 0; i < vCycles.size(); i++)
		{
			for (int j = 0; j < vCycles[i].size() - 1; j++)
			{
				oFile << vCycles[i][j] << " -> ";
			}
			oFile << vCycles[i].back() << std::endl;
		}
	}
	else
	{
		std::cout << "Nie znaleziono cykli.";
		oFile << "Nie znaleziono cykli.";
	}


	iFile.close();
	oFile.close();
	return 0;
}
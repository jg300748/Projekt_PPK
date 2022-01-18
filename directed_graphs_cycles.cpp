#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include "functions.h"

int main()
{
	Digraph digraph;
	std::vector<std::vector<int>> vCycles;
	std::ifstream iFile("input_data.txt");
	std::ofstream oFile("output_data.txt");

	if (!iFile || !oFile) { iFile.close(); oFile.close(); std::cerr << "FILE ERROR: cannot open file"; return 0; }

	if (not make_digraph(iFile, digraph))
	{
		std::cout << "...doesn't work...";		//dodac info zwrotne ze zly format
		iFile.close();
		oFile.close();
		return 0;
	}
	/*std::cout << "Vertices:\n";
	for (int i = 0; i < digraph.vVertices.size(); i++)
		std::cout << digraph.vVertices[i] << std::endl;
	std::cout << "Arcs:\n";
	for (int i = 0; i < digraph.vArcs.size(); i++)
	{
		for (int j = 0; j < 2; j++)
			std::cout << digraph.vArcs[i][j] << " ";
		std::cout << std::endl;
	}*/

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
		std::cout << "None cycles were found.";
		oFile << "None cycles were found.";
	}


	iFile.close();
	oFile.close();
	return 0;
}
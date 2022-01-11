#include <iostream>
#include <vector>
#include <fstream>
#include "functions.h"

int main()
{
	Digraph digraph;
	std::ifstream iFile("input_data.txt");
	std::ofstream oFile("output_data.txt");

	if (!iFile || !oFile) { iFile.close(); oFile.close(); std::cerr << "FILE ERROR"; return 0; }

	make_digraph(iFile, digraph); // sprawdzic zwracana wartiosc
	std::cout << "Vertices:\n";
	for (int i = 0; i < digraph.vVertices.size(); i++)
		std::cout << digraph.vVertices[i] << std::endl;
	std::cout << "Arcs:\n";
	for (int i = 0; i < digraph.vArcs.size(); i++)
	{
		for (int j = 0; j < 2; j++)
			std::cout << digraph.vArcs[i][j] << " ";
		std::cout << std::endl;
	}


	iFile.close();
	oFile.close();
	return 0;
}
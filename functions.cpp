#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "functions.h"

bool make_digraph(std::ifstream& iFile, Digraph& digraph)
{
	std::vector<int> v;
	std::string s;
	int n1, n2;
	bool b = false;

	if (!(iFile >> n1 >> s >> n2))
		return false;

	v.push_back(n1); v.push_back(n2);
	digraph.vArcs.push_back(v);
	if (n1 != n2)
	{
		digraph.vVertices.push_back(n1); digraph.vVertices.push_back(n2);
	}
	else
	{
		digraph.vVertices.push_back(n1);
	}

	while (iFile >> s)
	{
		if (s == ",")
		{
			iFile >> n1 >> s >> n2;
			v[0] = n1; v[1] = n2;
			digraph.vArcs.push_back(v);
			if (!check_vertex(digraph.vVertices, n1))
				digraph.vVertices.push_back(n1);
			if (!check_vertex(digraph.vVertices, n2))
				digraph.vVertices.push_back(n2);
		}
	}
	return true;
}

bool check_vertex(std::vector<int>& v, int n)
{
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] == n)
			return true;
	}
	return false;
}

std::vector<std::vector<int>> search_cycles(Digraph& digraph, int nStart, int nFinish)
{
	std::vector<std::vector<int>> vCycles;
	std::vector<int> vOneCycle;
	std::vector<int> vVisited, vVisiting;
	std::vector<int> vNotVisited = digraph.vVertices;
	
	if ( !digraph.vVertices.empty() || (vVisited.size() == digraph.vVertices.size()))
		return vCycles;


}

//bool make_digraph(std::ifstream& iFile, Digraph &digraph)
//{
//	std::vector<int> v;
//	std::string s;
//	int n1, n2; 
//	bool b = false;
//
//	if (!(iFile >> n1 >> s >> n2))
//		return false;
//
//	v.push_back(n1); v.push_back(n2);
//	digraph.vArcs.push_back(v);
//	if (n1 != n2)
//	{
//		digraph.vVertices.push_back(n1); digraph.vVertices.push_back(n2);
//	}
//	else
//	{
//		digraph.vVertices.push_back(n1);
//	}
//
//	while (iFile >> s)
//	{
//		if (s == ",")
//		{
//			iFile >> n1 >> s >> n2;
//			v[0] = n1; v[1] = n2;
//			digraph.vArcs.push_back(v);
//			for (int i = 0; i < digraph.vVertices.size(); i++)
//			{
//				if (digraph.vVertices[i] == n1)
//				{
//					b = true;
//					break;
//				}
//			}
//			if (!b)
//			{
//				digraph.vVertices.push_back(n1);
//			}
//			b = false;
//			if (n1 != n2)
//			{
//				for (int i = 0; i < digraph.vVertices.size(); i++)
//				{
//					if (digraph.vVertices[i] == n2)
//					{
//						b = true;
//						break;
//					}
//				}
//				if (!b)
//				{
//					digraph.vVertices.push_back(n2);
//				}
//				b = false;
//			}
//		}
//	}
//	return true;
//}
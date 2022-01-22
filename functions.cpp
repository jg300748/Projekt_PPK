#include <iostream>
#include <vector>
#include <fstream>
#include <map>
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

bool search_cycles(Digraph& digraph, std::vector<std::vector<int>>& vCycles)
{
	std::vector<int> vStack;
	std::map<int, bool> mVisited;
	for (int i = 0; i < digraph.vVertices.size(); i++)
	{
		mVisited[digraph.vVertices[i]] = false;
	}
	DFS(digraph, digraph.vVertices[0], mVisited, vStack, vCycles, 0);
	if (vCycles.empty())
		return false;
	return true;
}

void DFS(Digraph& digraph, int nVertex, std::map<int, bool> mVisited, std::vector<int>& vStack, std::vector<std::vector<int>>& vCycles, int nIteration)
{
	mVisited[nVertex] = true;
	vStack.push_back(nVertex);
	for (int i = 0; i < digraph.vArcs.size(); i++)
	{
		if (digraph.vArcs[i][0] == nVertex)
		{
			if (digraph.vArcs[i][1] == vStack[0])
			{
				vStack.push_back(digraph.vArcs[i][1]);
				vCycles.push_back(vStack);
				vStack.pop_back();
			}
			if (!mVisited[digraph.vArcs[i][1]])
			{
				DFS(digraph, digraph.vArcs[i][1], mVisited, vStack, vCycles, nIteration + 1);
			}
		}
	}
	vStack.pop_back();
	if (nIteration == 0)
	{
		for (int i = 1; i < digraph.vVertices.size(); i++)
		{
			for (auto it = mVisited.begin(); it != mVisited.end(); it++)
				it->second = false;
			DFS(digraph, digraph.vVertices[i], mVisited, vStack, vCycles, nIteration + 1);
		}
	}
	return;
}
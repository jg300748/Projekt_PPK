#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include "functions.h"

bool make_digraph(std::ifstream& iFile, Digraph& digraph)
{
	std::string s;
	int n1, n2;
	bool b {false};

	if (iFile >> n1)
	{
		digraph.mVertices[n1] = false;
	}
	else
		return false;

	while (iFile >> s)
	{
		if (s == "->")
		{
			if (!(iFile >> n2))
				return false;
			if (digraph.mVertices.find(n2) == digraph.mVertices.end())
				digraph.mVertices[n2] = false;
			for (int i = 0; i < digraph.mArcs[n1].size(); i++)
			{
				if (digraph.mArcs[n1][i] == n2)
				{
					b = true;
					break;
				}
			}
			if (!b)
			{
				digraph.mArcs[n1].push_back(n2);
				b = false;
			}
		}
		else if (s == ",")
		{
			if(!(iFile >> n1))
				return false;
			if (digraph.mVertices.find(n1) == digraph.mVertices.end())
				digraph.mVertices[n1] = false;
		}
		else
		{
			return false;
		}
	}
	return true;
}

bool search_cycles(Digraph& digraph, std::vector<std::vector<int>>& vCycles)
{
	std::vector<int> vStack;
	std::map<int, bool> mVisited = digraph.mVertices;
	DFS(digraph.mVertices, digraph.mArcs, mVisited, digraph.mVertices.begin()->first, vStack, vCycles, 0);
	if (vCycles.empty())
		return false;
	return true;
}

void DFS(std::map<int, bool> mVertices, std::map<int, std::vector<int>>& mArcs, std::map<int, bool>& mVisited, int nVertex, std::vector<int>& vStack, std::vector<std::vector<int>>& vCycles, int nIteration)
{
	mVertices[nVertex] = true;
	vStack.push_back(nVertex);
	for (int i = 0; i < mArcs[nVertex].size(); i++)
	{
		if (mArcs[nVertex][i] == vStack[0])
		{
			vStack.push_back(mArcs[nVertex][i]);
			vCycles.push_back(vStack);
			vStack.pop_back();
		}
		else if (!mVertices[mArcs[nVertex][i]])
		{
			DFS(mVertices, mArcs, mVisited, mArcs[nVertex][i], vStack, vCycles, nIteration + 1);
		}
	}
	vStack.pop_back();
	if (nIteration == 0)
	{
		mVisited[nVertex] = true;
		mVertices[nVertex] = false;
		for (auto i = mVisited.begin(); i != mVisited.end(); i++)
		{
			if (!(i->second))
			{
				DFS(mVertices, mArcs, mVisited, i->first, vStack, vCycles, nIteration + 1);
			}
		}
	}
	return;
}
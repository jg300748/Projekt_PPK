#ifndef define
#define define

struct Digraph
{
	std::vector<int>			  vVertices;
	std::vector<std::vector<int>> vArcs;
};

bool make_digraph(std::ifstream &iFile, Digraph &digraph);
bool check_vertex(std::vector<int>& v, int n);
bool search_cycles(Digraph& digraph, std::vector<std::vector<int>>& vCycles);
void DFS(Digraph& digraph, int nVertex, std::map<int, bool> mVisited, std::vector<int>& vStack, std::vector<std::vector<int>>& vCycles, int nIteration);
#endif
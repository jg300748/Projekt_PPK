#ifndef define
#define define

struct Digraph
{
	std::vector<int>			  vVertices;
	std::vector<std::vector<int>> vArcs;
};

bool make_digraph(std::ifstream &iFile, Digraph &digraph);
bool check_vertex(std::vector<int>& v, int n);
std::vector<std::vector<int>> search_cycles(Digraph& digraph, int nStart, int nFinish);
#endif
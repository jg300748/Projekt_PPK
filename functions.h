/** @file functions.h */
#ifndef define
#define define

/** \brief Struktura Digraph reprezentuje graf skierowany.
*
*	Struktura Digraph posiada dwie sk³adowe reprezentuj¹ce kolejno wierzcho³ki i krawêdzie grafu.
*/
struct Digraph
{
	std::map<int, bool>	mVertices; ///< Mapa o kluczu typu int i wartoœci typu bool. Klucz reprezentuje wierzcho³ek grafu, a wartoœci s¹ przydatne w póŸniejszym szukaniu cykli.
	std::map<int, std::vector<int>> mArcs; ///< Mapa o kluczu typu int i wartoœci bêd¹cej wektorem intów. Klucz reprezentuje wierzcho³ek grafu, a wartoœæ przechowuje wszystkie wierzcho³ki do których mo¿na dostaæ siê z wierzcho³ka danego kluczem.
};

/** \brief Funkcja make_digraph s³u¿y do wype³nienia zmiennej typu Digraph danymi z pliku wejœciowego.
* 
*	@param iFile Zmienna plikowa z danymi wejœciowymi, które bêd¹ u¿yte do wype³nienia zmiennej Digraph.
*	@param digraph Zmienna typu Digraph, która bêdzie wype³niana danymi.
*	@returns Funkcja zwraca wartoœæ false, jeœli dane wejœciowe s¹ podane w z³ym formacie (np. pojawia siê niepo¿¹dany znak). Funkcja zwraca wartoœæ true, jeœli zmienna digraph zosta³a pomyœlnie zape³niona danymi.
*/
bool make_digraph(std::ifstream& iFile, Digraph& digraph);

/** \brief Funkcja search_cycles przygotowuje potrzebne zmienne dla funkcji DFS, któr¹ nastêpnie wywo³uje. 
* 
*	@param digraph Graf w którym szukane bêd¹ cykle.
*	@param vCycles Wektor wektorów intów, w którym przechowywane bêd¹ znalezione cykle.
*	@returns Funkcja zwraca wartoœæ true, jeœli jakieœ cykle zosta³y znalezione. Funkcja zwraca false jeœli ¿aden cykl nie zosta³ znaleziony.
*/
bool search_cycles(Digraph& digraph, std::vector<std::vector<int>>& vCycles);

/** \brief Funkcja DFS s³u¿y do szukanania cykli w grafie skierowanym. Funkcja korzysta z rekurencyjnego algorytmu przeszukiwania w g³¹b.
* 
*	@param mVertices Mapa reprezentuj¹ca wierzcho³ki grafu. Wartoœci informuj¹ czy dany wierzcho³ek by³ ju¿ odwiedzony podczas szukania cykli.
*	@param mArcs Mapa reprezentuj¹ca krawêdzi grafu.
*	@param mVisited Mapa przechowuj¹c¹ informacjê, czy dla danego wierzcho³ka by³y ju¿ szukane cykle.
*	@param nVertex Wierzcho³ek dla którego wywo³ywana jest funkcja.
*	@param vStack Wektor u¿ywany jako stos, do którego odk³adane s¹ kolejne wierzcho³ki wywo³añ funkcji. Jeœli jego pocz¹tkowy i ostatni element s¹ sobie równe, to znajduje siê w nim cykl.
*	@param vCycles Wektor wektrów przechowuj¹cy znalezione cykle.
*	@param nIteration Licznik iteracji funkcji.
*	@note Mapa krawêdzi oraz wierzcho³ków przekazywana jest osobno, a nie jako pojedyncza struktura dla oszczêdnoœci pamiêci. Mapa krawêdzi mo¿e zostaæ przekazana przez referencje, jednak mapa wierzcho³ków dla poprawnego dzia³ania funkcji musi zostaæ przekazana przez kopiê.
*/
void DFS(std::map<int, bool> mVertices, std::map<int, std::vector<int>>& mArcs, std::map<int, bool>& mVisited, int nVertex, std::vector<int>& vStack, std::vector<std::vector<int>>& vCycles, int nIteration);
#endif
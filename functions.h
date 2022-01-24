/** @file functions.h */
#ifndef define
#define define

/** \brief Struktura Digraph reprezentuje graf skierowany.
*
*	Struktura Digraph posiada dwie sk�adowe reprezentuj�ce kolejno wierzcho�ki i kraw�dzie grafu.
*/
struct Digraph
{
	std::map<int, bool>	mVertices; ///< Mapa o kluczu typu int i warto�ci typu bool. Klucz reprezentuje wierzcho�ek grafu, a warto�ci s� przydatne w p�niejszym szukaniu cykli.
	std::map<int, std::vector<int>> mArcs; ///< Mapa o kluczu typu int i warto�ci b�d�cej wektorem int�w. Klucz reprezentuje wierzcho�ek grafu, a warto�� przechowuje wszystkie wierzcho�ki do kt�rych mo�na dosta� si� z wierzcho�ka danego kluczem.
};

/** \brief Funkcja make_digraph s�u�y do wype�nienia zmiennej typu Digraph danymi z pliku wej�ciowego.
* 
*	@param iFile Zmienna plikowa z danymi wej�ciowymi, kt�re b�d� u�yte do wype�nienia zmiennej Digraph.
*	@param digraph Zmienna typu Digraph, kt�ra b�dzie wype�niana danymi.
*	@returns Funkcja zwraca warto�� false, je�li dane wej�ciowe s� podane w z�ym formacie (np. pojawia si� niepo��dany znak). Funkcja zwraca warto�� true, je�li zmienna digraph zosta�a pomy�lnie zape�niona danymi.
*/
bool make_digraph(std::ifstream& iFile, Digraph& digraph);

/** \brief Funkcja search_cycles przygotowuje potrzebne zmienne dla funkcji DFS, kt�r� nast�pnie wywo�uje. 
* 
*	@param digraph Graf w kt�rym szukane b�d� cykle.
*	@param vCycles Wektor wektor�w int�w, w kt�rym przechowywane b�d� znalezione cykle.
*	@returns Funkcja zwraca warto�� true, je�li jakie� cykle zosta�y znalezione. Funkcja zwraca false je�li �aden cykl nie zosta� znaleziony.
*/
bool search_cycles(Digraph& digraph, std::vector<std::vector<int>>& vCycles);

/** \brief Funkcja DFS s�u�y do szukanania cykli w grafie skierowanym. Funkcja korzysta z rekurencyjnego algorytmu przeszukiwania w g��b.
* 
*	@param mVertices Mapa reprezentuj�ca wierzcho�ki grafu. Warto�ci informuj� czy dany wierzcho�ek by� ju� odwiedzony podczas szukania cykli.
*	@param mArcs Mapa reprezentuj�ca kraw�dzi grafu.
*	@param mVisited Mapa przechowuj�c� informacj�, czy dla danego wierzcho�ka by�y ju� szukane cykle.
*	@param nVertex Wierzcho�ek dla kt�rego wywo�ywana jest funkcja.
*	@param vStack Wektor u�ywany jako stos, do kt�rego odk�adane s� kolejne wierzcho�ki wywo�a� funkcji. Je�li jego pocz�tkowy i ostatni element s� sobie r�wne, to znajduje si� w nim cykl.
*	@param vCycles Wektor wektr�w przechowuj�cy znalezione cykle.
*	@param nIteration Licznik iteracji funkcji.
*	@note Mapa kraw�dzi oraz wierzcho�k�w przekazywana jest osobno, a nie jako pojedyncza struktura dla oszcz�dno�ci pami�ci. Mapa kraw�dzi mo�e zosta� przekazana przez referencje, jednak mapa wierzcho�k�w dla poprawnego dzia�ania funkcji musi zosta� przekazana przez kopi�.
*/
void DFS(std::map<int, bool> mVertices, std::map<int, std::vector<int>>& mArcs, std::map<int, bool>& mVisited, int nVertex, std::vector<int>& vStack, std::vector<std::vector<int>>& vCycles, int nIteration);
#endif
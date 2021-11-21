#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class AstarAlgorithm
{
public:
    AstarAlgorithm(
        int numberOfNodes,
        vector<string> namesOfNodes,
        int** XYs,
        int* numberOfEdgesPerNode,
        int** indexOfNeighbor,
        int** costOfEdge);

    void run(string startName, string finishName);

private:
    int numberOfNodes;//liczba wszystkich wierzcholkow
    vector<string> namesOfNodes;//tablica nazw wierzcholkow
    int** XYs;//tablica z punktami X oraz Y
    int* numberOfEdgesPerNode;//ilosc krawedzi wychodzacych z jednego wierzcholka
    int** indexOfNeighbor;//tablica z numerami sasiadow
    int** costOfEdge;//wagi krawedzi do sasadow dla konkretnego node'a
    vector<double> costsToFinish;//tablica z kosztami do celu
    vector<bool> orVisited;//tablica z statusami czy wierzcholek zostal odwiedziony (domyslnie falsz)

    int getIndexOfNodeByName(string name);//zwraca indeks node'a o podanej nazwie 
    double calcHeuristicValue(int x1, int y1); //oblicza heurystyke (jezeli cel jest na poczatku ukladu wspolrzednych)
    double calcHeuristicValue(int x1, int y1, int x2, int y2);//oblicza heurtystyczna wartosc
    double getIndexOfUnvisitedCheapestNode();//zwraca id najtanszego nieodwiedzonego wierzcholka

};


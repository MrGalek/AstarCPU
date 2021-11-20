#include <string>
#include <vector>
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


};


#include "AstarAlgorithm.h"

AstarAlgorithm::AstarAlgorithm(int numberOfNodes, vector<string> namesOfNodes, int** XYs, int* numberOfEdgesPerNode, int** indexOfNeighbor, int** costOfEdge)
{
	this->numberOfNodes = numberOfNodes;
	this->namesOfNodes = namesOfNodes;
	this->XYs = XYs;
	this->numberOfEdgesPerNode = numberOfEdgesPerNode;
	this->indexOfNeighbor = indexOfNeighbor;
	this->costOfEdge = costOfEdge;
}

void AstarAlgorithm::run(string startName, string finishName)
{
	double* costsFromStart = new double[numberOfNodes];//tablica z kosztami od startu
	int* indexOfPreviousNodes = new int[numberOfNodes];//tablica z indeksami poprzednikow danej krawedzi
	double* heuristic = new double[numberOfNodes];//tablica z heurystykami

	for (int i = 0; i < numberOfNodes; i++)//poczatkowo te trzy wartosci sa nieznane - maksymalna dostepna wartosc
	{
		costsFromStart[i] = DBL_MAX;
		heuristic[i] = DBL_MAX;

		costsToFinish.push_back(DBL_MAX);
		orVisited.push_back(false);
	}

	int indexOfFinishNode = getIndexOfNodeByName(finishName);
	int indexOfCurrentNode = getIndexOfNodeByName(startName);
	costsFromStart[indexOfCurrentNode] = 0;//ustawiam koszt od startu na 0 - bo to poczatkowy NODE

	bool finishFlag = false;
	int chipestFoundPath = INT_MAX; //wartosc najtanszej znalezionej sciezki

	do
	{
		orVisited[indexOfCurrentNode] = true;

		if (indexOfCurrentNode == indexOfFinishNode) //sprawdzam czy aktualnie sprawdzany node ma ten sam indeks co szukany node
		{

		}
		else //jezeli nie to sprawdzam dalej
		{
			for (int i = 0; i < numberOfEdgesPerNode[indexOfCurrentNode]; i++)//przegladam wszystkie krawedzie od danego wierzcholka
			{
				int indexOfEdgeNeighborNode = indexOfNeighbor[indexOfCurrentNode][i]; //indeks celu krawedzi
				double costOfEdgeNeighborNode = costOfEdge[indexOfCurrentNode][i]; //koszt tej krawedzi

				heuristic[indexOfEdgeNeighborNode] = calcHeuristicValue(XYs[indexOfEdgeNeighborNode][0], XYs[indexOfEdgeNeighborNode][1]);//pobieram wartosc heurystyczna dla node'a po drugiej stronie krawedzi
				if (costsFromStart[indexOfEdgeNeighborNode] > costsFromStart[indexOfCurrentNode] + costOfEdgeNeighborNode)
				{
					indexOfPreviousNodes[indexOfEdgeNeighborNode] = indexOfCurrentNode;
					costsFromStart[indexOfEdgeNeighborNode] = costsFromStart[indexOfCurrentNode] + costOfEdgeNeighborNode;
					costsToFinish.at(indexOfEdgeNeighborNode) = costsFromStart[indexOfEdgeNeighborNode] + heuristic[indexOfEdgeNeighborNode];
				}
				
			}

			indexOfCurrentNode = getIndexOfUnvisitedCheapestNode();
			indexOfCurrentNode = indexOfCurrentNode;
		}

	} while (finishFlag == false);

}

int AstarAlgorithm::getIndexOfNodeByName(string name)
{
	for (int i = 0; i < numberOfNodes; i++)
	{
		if (namesOfNodes.at(i) == name) return i;
	}
}

double AstarAlgorithm::calcHeuristicValue(int x1, int y1)
{
	return calcHeuristicValue(x1, y1, 0, 0);
}

double AstarAlgorithm::calcHeuristicValue(int x1, int y1, int x2, int y2)
{
	return sqrt(pow(((double)x2 - (double)x1), 2) + pow(((double)y2 - (double)y1), 2));
}

double AstarAlgorithm::getIndexOfUnvisitedCheapestNode()
{
	vector<double> tmpCostsToFinish = costsToFinish;

	for (int i = 0; i < numberOfNodes; i++) //szukam najtanszego noda, ale sprawdzam czy jest odwiedzony, jezeli tak to maxuje jego koszt w tymczasowym wektorze 
	{
		int indexOfCheapestNode = std::min_element(tmpCostsToFinish.begin(), tmpCostsToFinish.end()) - tmpCostsToFinish.begin();
		if (orVisited[indexOfCheapestNode]) tmpCostsToFinish[indexOfCheapestNode] = INT_MAX;
		else return indexOfCheapestNode;
	}
}


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

}

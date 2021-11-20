// Astar.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "AstarAlgorithm.h"
using namespace std;

int main(int argc, char* argv[])
{ 
    int numberOfNodes;//liczba wszystkich wierzcholkow
    vector<string> namesOfNodes;//tablica nazw wierzcholkow
    int** XYs;//tablica z punktami X oraz Y
    int* numberOfEdgesPerNode;//ilosc krawedzi wychodzacych z jednego wierzcholka
    int** indexOfNeighbor;//tablica z numerami sasiadow
    int** costOfEdge;//wagi krawedzi do sasadow dla konkretnego node'a

    //CZYTANIE PLIKU i DEFINICJA TABLIC
    ifstream inputFile(argv[1]);
    string inputString;

    if (inputFile.is_open())
    {
        inputFile >> inputString;
        numberOfNodes = stoi(inputString);

        XYs = new int* [numberOfNodes];//tablica z punktami X oraz Y
        for (int i = 0; i < numberOfNodes; i++)
        {
            XYs[i] = new int[2];
        }
        numberOfEdgesPerNode = new int[numberOfNodes];//ilosc krawedzi wychodzacych z jednego wierzcholka
        indexOfNeighbor = new int* [numberOfNodes];//tablica z numerami sasiadow
        costOfEdge = new int* [numberOfNodes];//wagi krawedzi do sasadow dla konkretnego node'a

        for (int i = 0; i < numberOfNodes; i++)
        {
            inputFile >> inputString;
            namesOfNodes.push_back(inputString);
            inputFile >> inputString;
            XYs[i][0] = stoi(inputString);
            inputFile >> inputString;
            XYs[i][1] = stoi(inputString);
            inputFile >> inputString;
            numberOfEdgesPerNode[i] = stoi(inputString);

            indexOfNeighbor[i] = new int[numberOfEdgesPerNode[i]];//tworze tyle komorek pamieci ile jest sasiadow dla noda
            costOfEdge[i] = new int[numberOfEdgesPerNode[i]];//tworze tyle komorek pamieci ile jest sasiadow dla wag krawedzi od noda

            for (int j = 0; j < numberOfEdgesPerNode[i]; j++)
            {
                inputFile >> inputString;
                indexOfNeighbor[i][j] = stoi(inputString);
                inputFile >> inputString;
                costOfEdge[i][j] = stoi(inputString);
            }
        }

        ///

        AstarAlgorithm astarAlgorithm(numberOfNodes, namesOfNodes, XYs, numberOfEdgesPerNode, indexOfNeighbor, costOfEdge);
        astarAlgorithm.run(argv[2], argv[3]);

        ////WYSWIETLANIE PLIKU WEJSCIOWEGO
        //for (int i = 0; i < numberOfNodes; i++)
        //{
        //    cout << namesOfNodes.at(i) << " " << XYs[i][0] << " " << XYs[i][1] << " "<< numberOfEdgesPerNode[i] << " ";
        //    for (int j = 0; j < numberOfEdgesPerNode[i]; j++)
        //    {
        //        cout << indexOfNeighbor[i][j] << " " << costOfEdge[i][j]<<" ";
        //    }
        //    cout << "\n";

        //}
    }
}
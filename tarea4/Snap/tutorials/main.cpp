#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <iomanip>
#include <map>
#include "Snap.h"
#define INF 1000000
using namespace std;

const int NUM_NODES = 15;
PNGraph graph ;
int vVal[NUM_NODES][NUM_NODES];

vector<pair<int,int> > getChildIds(int);



int main(int argc, char* argv[])
{
    //Inicializar grafo
    graph = TNGraph::New();
	for (int i = 1; i < NUM_NODES; ++i)
        insertNode(i);

    insertVertex(1 ,3 ,8);
    insertVertex(1 ,4 ,8);
    insertVertex(2 ,5 ,7);
    insertVertex(3 ,2 ,7);
    insertVertex(3 ,5 ,8);
    insertVertex(3 ,10,4);
    insertVertex(4 ,5 ,1);
    insertVertex(4 ,7 ,3);
    insertVertex(4 ,8 ,2);
    insertVertex(5 ,6 ,9);
    insertVertex(6 ,13,4);
    insertVertex(7 ,4 ,6);
    insertVertex(8 ,7 ,3);
    insertVertex(8 ,9 ,3);
    insertVertex(9 ,10,2);
    insertVertex(9 ,12,4);
    insertVertex(10,3 ,10);
    insertVertex(10,6 ,6);
    insertVertex(11,12,6);
    insertVertex(12,9 ,2);
    insertVertex(12,11,8);
    insertVertex(12,14,9);
    insertVertex(13,14,6);
    insertVertex(14,13,2);

    //Ejecutar algoritmos
    bool visited[NUM_NODES];
    fill(visited, visited+NUM_NODES, false);
    cout << endl << "--- DFS ---" << endl;
    printDFS(visited,1);
    cout << endl << "--- BFS ---" << endl;
    printBFS(1);
    cout << endl << "--- Prim ---" << endl;
    printPrim();
    cout << endl << "--- Krustal ---" << endl;
    printKrustal();
    cout << endl << "--- Dijkstra ---" << endl;
    printDijkstra(1);
    cout << endl << "--- Floyd ---" << endl;
    printFloyd();
}


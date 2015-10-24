/*
 * =====================================================================================
 *
 *       Filename:  grafo.cpp
 *
 *    Description:  Main de un grafo
 *
 *        Version:  1.0
 *        Created:  15/10/15 10:00:55
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Daniel Monzalvo 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <iostream>
#include <queue>
#include <vector>
#include <limits>

typedef struct Nodo{
	int valor;
	std::vector<struct Vertice*> salen;
}*nodo;

typedef struct Vertice{
	int peso;
	struct Nodo* derecha;
	struct Nodo* izquierda;
}*vertice;

typedef struct Grafo{
	std::vector<struct Vertice*> vertices;
	std::vector<struct Nodo*> nodos;
}*g;

nodo crearNodo(int, g);
nodo buscarNodo(g, int);
nodo buscarOCrearNodo(g, int);
vertice crearVertice(nodo, nodo, int);
void agregarVertice(g, int iz, int der, int peso);
void imprimirGrafo(g);

int main(){
	g grafo = new (struct Grafo);

	agregarVertice(grafo, 1, 2, 10);
	agregarVertice(grafo, 1, 3, 15);
	agregarVertice(grafo, 2, 3, 3);

	imprimirGrafo(grafo);

	return 0;
}



nodo crearNodo(int v, g graph){
	nodo NuevoNodo = new (struct Nodo);
	NuevoNodo->valor = v;
	graph->nodos.push_back(NuevoNodo);
	return NuevoNodo;
}

nodo buscarNodo(g graph, int v){
	for (auto item:graph->nodos){
		if (item->valor == v)
			return item;
	}
	return NULL;
}

nodo buscarOCrearNodo(g graph, int v){
	nodo temp = buscarNodo(graph, v);
	if (temp != NULL){
		return temp;
	}
	return crearNodo(v, graph);
}

vertice crearVertice(nodo ni, nodo nd, int p){
	vertice VerticeNuevo = new (struct Vertice);
	VerticeNuevo->derecha = nd;
	VerticeNuevo->izquierda = ni;
	VerticeNuevo->peso = p;
	ni->salen.push_back(VerticeNuevo);
	return VerticeNuevo;
}

void agregarVertice(g graph, int v1, int v2, int p){
	nodo ni = buscarOCrearNodo(graph, v1);
	nodo nd = buscarOCrearNodo(graph, v2);
	graph->vertices.push_back(crearVertice(ni, nd, p));
}

void imprimirGrafo(g graph){
	for (auto item:(graph->nodos)){
		std::cout << "Nodo " << item->valor << ":" << std::endl;
		if (!item->salen.empty()){
			for (auto aristas:(item->salen)){
				std::cout << "--(" << aristas->peso << ")->" << aristas->derecha->valor << std::endl;
			}
		}
	}
}


typedef struct d{
	int dist;
	Nodo p;
	Nodo n;
}*distancia;

void Dijkstra(g graph, nodo s){
	std::vector<distancia> D;
	std::vector<Nodo> Q;

	// Inizialisacion
	for (auto item:(graph->nodos)){
		q.push_back(item);
		distancia temp = new distancia;
		temp->dist = std::numeric_limits<int>::max();
		temp->p = nullptr;
		temp->n = item;
	}

}

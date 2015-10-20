/*
 * =====================================================================================
 *
 *       Filename:  boostGraph.cpp
 *
 *    Description:  Solución al Problema 2, con la libreria Boost Graph
 *
 *        Version:  1.0
 *        Created:  16/10/15 14:51:04
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <iostream>
#include <boost/graph/graph_traits.hpp>
#include <boost/config.hpp>
#include <boost/graph/directed_graph.hpp>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/dijkstra_shortest_paths.hpp>
#include <boost/graph/kruskal_min_spanning_tree.hpp>
#include <boost/graph/depth_first_search.hpp>
#include <boost/graph/breadth_first_search.hpp>
#include <boost/graph/prim_minimum_spanning_tree.hpp>
#include <boost/property_map/property_map.hpp>
#include <boost/graph/graphviz.hpp>
#include <boost/graph/johnson_all_pairs_shortest.hpp>
#include <algorithm>
#include <time.h>




using namespace std;
using namespace boost;

// Definicion del grafo
typedef property<edge_weight_t, int> arista_peso;
typedef adjacency_list<boost::listS, boost::vecS, boost::directedS, no_property, arista_peso> Graph;
// Definicion de ayudantes
typedef graph_traits<Graph>::vertex_descriptor nodo_t;
typedef graph_traits<Graph>::edge_descriptor arista_t;




int main(){
	bool b;

	// Instancia del grafo
	Graph g;
	
	// Agregar aristas y vertices, formato: (vertice1, vertice2, peso, grafo)
	clock_t t;
	t = clock();
	add_edge(1,4,8,g);
	add_edge(1,3,8,g);
	add_edge(3,2,7,g);
	add_edge(2,5,7,g);
	add_edge(3,5,8,g);
	add_edge(3,10,4,g);
	add_edge(4,8,2,g);
	add_edge(4,7,3,g);
	add_edge(4,5,1,g);
	add_edge(5,6,9,g);
	add_edge(6,13,4,g);
	add_edge(7,4,6,g);
	add_edge(8,7,3,g);
	add_edge(8,9,3,g);
	add_edge(9,10,2,g);
	add_edge(9,12,4,g);
	add_edge(10,3,10,g);
	add_edge(10,6,6,g);
	add_edge(11,12,6,g);
	add_edge(12,11,8,g);
	add_edge(12,9,2,g);
	add_edge(12,14,9,g);
	add_edge(13,14,6,g);
	add_edge(14,13,2,g);
	t = clock() -t;
	cout << "Tiempo en insertar 23 aristas y 14 vertices: " << (((float)t) / CLOCKS_PER_SEC) << " segundos." << endl;

	// Mapa de vertices
	typedef property_map<Graph, vertex_index_t>::type MapaVer;
	MapaVer index = get(vertex_index, g);
	graph_traits<Graph>::edge_iterator ei, ei_end;

	for (tie(ei,ei_end) = edges(g); ei != ei_end; ++ei){
		cout << "(" << index[source(*ei,g)] << "," << index[target(*ei,g)] << ")" << endl;
	}

	cout << "Busqueda de profundidad" << endl;
	default_dfs_visitor v;
	depth_first_search(g, visitor(v));

	return 0;
}

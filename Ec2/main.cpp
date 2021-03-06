/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  15/10/15 13:21:16
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (),
 *   Organization:
 *
 * =====================================================================================
 */


 #include <iostream>
 #include <cstdlib>
 #include <boost/graph/graph_archetypes.hpp>
 #include <boost/graph/graph_traits.hpp>
 #include <boost/graph/directed_graph.hpp>
 #include <boost/graph/adjacency_list.hpp>
 #include <boost/graph/dijkstra_shortest_paths.hpp>
 #include <boost/graph/kruskal_min_spanning_tree.hpp>
 #include <boost/graph/directed_graph.hpp>
 #include <boost/graph/depth_first_search.hpp>
 #include <boost/config.hpp>
 #include <boost/graph/breadth_first_search.hpp>
 #include <boost/graph/prim_minimum_spanning_tree.hpp>
 #include <boost/property_map/property_map.hpp>
 #include <boost/graph/graphviz.hpp>
 #include <boost/graph/johnson_all_pairs_shortest.hpp>
 #include <utility>
 #include <algorithm>
 #include <time.h>
 #include <array>
 #include <fstream>
 #include <iomanip>
 #include <vector>

 using namespace boost;
 using namespace std;

 int main()
{
	typedef property<edge_weight_t, int> EdgeWeight; //definimos el peso de las aristas
	typedef adjacency_list<listS, vecS, directedS, no_property, EdgeWeight > grafo; //definimos que propiedades tiene el grafo
	typedef grafo::edge_descriptor Edge; //defines la descipcion de la arista
	grafo g;

	//agregamos las aristas
	clock_t t;
	t = clock();
	add_edge(3, 7, 2, g);
	add_edge(3, 2, 1, g);
	add_edge(2, 1, 6, g);
	add_edge(2, 8, 8, g);
	add_edge(1, 4, 7, g);
	add_edge(1, 5, 9, g);
	add_edge(5, 11, 9, g);
	add_edge(6, 9, 9, g);
	add_edge(7, 14, 2, g);
	add_edge(7, 8, 3, g);
	add_edge(7, 6, 4, g);
	add_edge(8, 6, 2, g);
	add_edge(8, 10, 6, g);
	add_edge(9, 8, 9, g);
	add_edge(10, 12, 7, g);
	add_edge(10,11, 8, g);
	add_edge(11, 13, 2, g);
	add_edge(14, 10, 4, g);

	typedef property_map<grafo, vertex_index_t>::type IndexMap; //definimos un mapa indexeado de los vertices
	IndexMap index = get(vertex_index, g);
	cout << "aristas = ";
	graph_traits<grafo>::edge_iterator ei, ei_end; //tener un iterador que pase por casa arista para que pueda imprimir

	for (tie(ei, ei_end) = edges(g)/*separa el numero de aristas en ei, ei_end*/; ei != ei_end /*mientras ei no alcance el final*/; ++ei)
	{
		cout << "(" << index[source(*ei, g)] << "," << index[target(*ei, g)] << ")" << endl; /*imprimimos...*/
	}

	property_map<grafo, edge_weight_t>::type weight = get(edge_weight, g);/*mapa de propiedades*/
	vector<Edge> spanning_tree;

	cout << "Algoritmo de Dijkstra" << endl << endl;
	t = clock();
	vector<graph_traits<grafo>::vertex_descriptor> pp(num_vertices(g));/*vector con descripcion de cada vertice*/
	vector<int> d(num_vertices(g)); /*vector con el numero de vertices*/
	graph_traits<grafo>::vertex_descriptor s = vertex(a, g);/*descripcion del vertice en turno*/

	dijkstra_shortest_paths(g, s, predecessor_map(make_iterator_property_map(pp.begin(), get(vertex_index, g))).distance_map(make_iterator_property_map(d.begin(), get(vertex_index, g))));/*asi se llama dijkstra o.o*/

	char name[] = "ABCDEFGHIJKLMNO";
	cout << "las distancias y los padres son: " << endl;
	graph_traits<grafo>::vertex_iterator vi, vend;
	for (tie(vi, vend) = vertices(g); vi != vend; ++vi)
		cout << "Distancia(" << name[*vi] << ")= " << d[*vi] << ", parent(" << name[*vi] << ")= " << name[p[*vi]] << endl;

	t = clock() - t;
	cout << "tardo " << t << "clicks, y " << (((float)t) / CLOCKS_PER_SEC) << "segundos en Dijkstra" << endl;

	

	cout << "Borrando" << endl << endl;
	graph_traits<grafo>::vertex_iterator vii, vii_end, next;
	tie(vii, vii_end) = vertices(g);
	tie(ei, ei_end) = edges(g);
	t = clock();
	for (next = vii; vii != vii_end; vii = next)
	{
		++next;
		remove_edge(source(*ei, g), target(*ei, g), g);
		remove_vertex(*vii, g);
		break;
	}
	t = clock() - t;
	cout << "tardo " << t << "clicks, y " << (((float)t) / CLOCKS_PER_SEC) << "segundos en borrar" << endl;
	/*impresion despues de borrar*/
	cout << "Despues del borrado" << endl << endl;
	for (tie(ei, ei_end) = edges(g); ei != ei_end; ++ei)
		cout << "(" << index[source(*ei, g)] << "," << index[target(*ei, g)] << ")";
	cout << endl;


	cin.get();
	return 0;
}

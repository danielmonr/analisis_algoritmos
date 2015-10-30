#include <iostream>
#include <fstream>
#include "Snap.h"


using namespace std;
ofstream file;

void GrapmlExp(PNGraph graph){
    file.open("Wiki.graphml");

    file << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n<graphml xmlns=\"http://graphml.graphdrawing.org/xmlns\"\n\t xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\"\n\t xsi:schemaLocation=\"http://graphml.graphdrawing.org/xmlns\n\thttp://graphml.graphdrawing.org/xmlns/1.0/graphml.xsd\">";

    file << "\n <graph id=\"graph\" edgedefault=\"directed\">\n";
    for (PNGraph::TObj::TNodeI nodes = graph->BegNI(); nodes < graph->EndNI(); nodes++) {
        file << "<node id=\"" << nodes.GetId() <<"\"/>\n";
    }
    for (PNGraph::TObj::TEdgeI edges = graph->BegEI(); edges < graph->EndEI(); edges++) {
        file << "<edge source=\"" << edges.GetSrcNId() << "\" target=\"" << edges.GetDstNId() << "\"/>\n";
    }

    file << "</graph>" << "\n</graphml>";
    file.close();
}

void GexfExp(PNGraph graph){

    file.open("Wiki.gexf");
    /*Insert Header*/
    file << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n<gexf xmlns=\"http://www.gexf.net/1.2draft\"\n xmlns:xsi=\"http://www.w3.org/2001/XMLSchema−instance\"\n xsi:schemaLocation=\"http://www.gexf.net/1.2draft\n\t\thttp://www.gexf.net/1.2draft/gexf.xsd\"\nversion=\"1.2\">";
    /*Insert Definition*/
    file << "\n<graph defaultedgetype=\"directed\">";
    /*Insert Nodes*/
    file << "<nodes>";
    for (PNGraph::TObj::TNodeI nodes = graph->BegNI(); nodes < graph->EndNI(); nodes++) {
        file << "<node id=\"" << nodes.GetId() <<"\"/>\n";
    }
    file << "</nodes>";
    /*Insert Edges*/
    file << "<edges>";
    int id = 1;
    for (PNGraph::TObj::TEdgeI edges = graph->BegEI(); edges < graph->EndEI(); edges++) {
        file << "<edge id=\"" << id << "\" source=\"" << edges.GetSrcNId() << "\" target=\"" << edges.GetDstNId() << "\"/>\n";
        id++;
    }
    file << "</edges>";
    file << "</graph>";
    file << "</gexf>";
    file.close();
}

void GdfExp(PNGraph graph){
    file.open("Wiki.gdf");

    file << "nodedef>id VARCHAR\n";

    for (PNGraph::TObj::TNodeI nodes = graph->BegNI(); nodes < graph->EndNI(); nodes++) {
        file << nodes.GetId() <<"\n";
    }

    file << "edgedef>source VARCHAR, destination VARCHAR\n";
    for (PNGraph::TObj::TEdgeI edges = graph->BegEI(); edges < graph->EndEI(); edges++) {
        file << edges.GetSrcNId() << "," << edges.GetDstNId() << "\n";
    }
    file.close();

}

void JsonExp(PNGraph graph){
    file.open("Wiki.json");

    file << "{ \"graph\": {\n\"nodes\": [\n" ;

    for (PNGraph::TObj::TNodeI nodes = graph->BegNI(); nodes < graph->EndNI(); nodes++) {
        file << "{ \"id\": \"" << nodes.GetId() << "\" }";
        if (nodes++ != graph->EndNI()){
          file << " ,\n";
        }
        else{
          file << " ]\n";
        }
    }
    file << "\"edges\": [\n";

    for (PNGraph::TObj::TEdgeI edges = graph->BegEI(); edges < graph->EndEI(); edges++) {
        file << "{ \"source\": \"" << edges.GetSrcNId() << "\", \"target\": \"" << edges.GetDstNId() << "\" }";
        if (edges++ != graph->EndEI()){
          file << " ,\n";
        }
        else{
          file << " ]\n";
      }
    }
    file << "} }";
    file.close();
}


int main(int argc, char* argv[])
{

  PNGraph grafo = TSnap::LoadEdgeList<PNGraph>("./wiki-Vote.txt", 0, 1);
  GrapmlExp(grafo);
  GexfExp(grafo);
  GdfExp(grafo);
  JsonExp(grafo);
}

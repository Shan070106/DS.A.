#include <iostream>
#include "graph.h"  

using namespace std;

int main() {
    // Create an empty graph of strings
    graph<string> g(3);

    // Add unweighted undirected edge
    g.add_edge("A", "B", "ud");

    // Add weighted directed edge
    g.add_edge("A", "C", 5, "d");

    // Add weighted undirected edge
    g.add_edge("B", "C", 2, "ud");

    // Printing all vertices
    cout<<"All vertices:"<<endl;
    for (const string& v : g.all_vertices) {
        cout<<"- "<<v<<endl;
    }

    // Printing all edges
    cout << "\nEdges (from, to, weight):"<<endl;
    for (const auto& e : g.edges) {
        cout<<g.all_vertices[e.from]<< " -> " 
             <<g.all_vertices[e.to]<<" (weight "<<e.weight<< ")"<<endl;
    }

    // Printing neighbors of a vertex
    cout<<"\nNeighbors of B:"<<endl;
    for (const auto& neighbor : g.get_neighbors("B")) {
        cout<<"- "<<neighbor<<endl;
    }

    // Printing degree information
    cout<<"\nDegrees for A:"<<endl;
    cout<<"In-degree: "<<g.get_indegree("A")<<endl;
    cout<<"Out-degree: "<<g.get_outdegree("A")<<endl;
    cout<<"Total degree: "<<g.get_degree("A")<<endl;

    return 0;
}

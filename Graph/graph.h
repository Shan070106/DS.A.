#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;

typedef long long int LL;
template<typename T>
class graph{
    private:
        unordered_map<T,LL> data_to_index; // data points to it's index in a graph
        struct edge{
            LL from,to; 
            LL weight;
        };

        bool cycle_on_component(LL node,bool visited[]){
            queue<pair<LL,LL>> q;
            q.push({node,-1});
            visited[node] = true;

            while(!q.empty()){
                LL node = q.front().first,
                LL parent = q.front().seocnd;
                q.pop();
                
                for(LL adjacent_node: adjacency_list[node]){
                    if(!visited[adjacent_node]){
                        visited[adjacent_node] = true;
                        q.push({adjacent_node,node});
                    }
                    else if(parent != adjacent_node)
                        return true;
                }
            }
            return false;
        }

    public:
        vector<T> all_vertices; // it stores the all kind of data in a vector
        long long V = 0,E = 0; // V - number of vertices, E - number of edges
        bool is_directed = false;
        vector<edge> edges;   // it stores the all edges of a graph
        vector<vector<pair<LL,LL>>> adjacency_list; // it stores adjacency list
        vector<vector<LL>> adjacency_matrix; // it stores adjacency matirx

        vector<LL> in_degree; // it stores the in-degree of all vertices
        vector<LL> out_degree; // it stores the out-degree of all vertices

        graph(long long n){    // creates an empty object with number of vertices
            V = n; 
            all_vertices = vector<T>(n);
            adjacency_list = vector<vector<pair<LL,LL>>>(n);
            adjacency_matrix = vector<vector<LL>>(n,vector<LL>(n,0));

            in_degree = vector<LL>(n,0);
            out_degree = vector<LL>(n,0);
        }

        graph(vector<T> all_nodes){   // creates an object with all the vertices provided, edge connection, in-degree and out-degree has not been given
            all_vertices = all_nodes;
            V = all_nodes.size();
            
            for(LL i=0;i<V;i++)  data_to_index[all_nodes[i]] = i;

            adjacency_list = vector<vector<pair<LL,LL>>>(V);
            adjacency_matrix = vector<vector<LL>>(V,vector<LL>(V,0));

            in_degree = vector<LL>(V,0);
            out_degree = vector<LL>(V,0);
        }

        graph(long long n, vector<T> all_nodes){ // number of vertices and all the vertices data has been given
            V = n;
            all_vertices = all_nodes;

            for(LL i=0;i<n;i++)  data_to_index[all_nodes[i]] = i;
            
            adjacency_list = vector<vector<pair<LL,LL>>>(n);
            adjacency_matrix = vector<vector<LL>>(n,vector<LL>(n,0));

            in_degree = vector<LL>(n,0);
            out_degree = vector<LL>(n,0);
        }

        void add_edge(T data1, T data2, string direction){ // adds edges to the graph if it is unweighted graph and weight as considered as unit weight
            LL s = data_to_index.size(),n1,n2;
            if(data_to_index.find(data1) == data_to_index.end()){
                data_to_index[data1] = s++;
                all_vertices.push_back(data1);
            }
            
            if(data_to_index.find(data2) == data_to_index.end()){
                data_to_index[data2] = s;
                all_vertices.push_back(data2);
            }

            n1 = data_to_index[data1]; 
            n2 = data_to_index[data2];
            edge e = {n1,n2,1};
            edges.push_back(e);

            if(direction == "ud"){
                adjacency_matrix[n1][n2] = 1;
                adjacency_matrix[n2][n1] = 1;

                adjacency_list[n1].push_back({n2,1});
                adjacency_list[n2].push_back({n1,1});
                
                in_degree[n1]++; out_degree[n1]++;
                in_degree[n2]++; out_degree[n2]++;
            }
            else{
                is_directed = true;

                adjacency_matrix[n1][n2] = 1;
                adjacency_list[n1].push_back({n2,1});

                in_degree[n2]++; out_degree[n1]++;
            }
            E += 1;
        }

        void add_edge(T data1, T data2, LL weight, string direction){   // adds edges to the graph  if it is weighted
            LL s = data_to_index.size(),n1,n2; 
            if(data_to_index.find(data1) == data_to_index.end()){
                data_to_index[data1] = s++;
                all_vertices.push_back(data1);
            }
            
            if(data_to_index.find(data2) == data_to_index.end()){
                data_to_index[data2] = s;
                all_vertices.push_back(data2);
            }

            n1 = data_to_index[data1]; 
            n2 = data_to_index[data2];
            edge e = {n1,n2,weight};
            edges.push_back(e);

            if(direction == "ud"){
                adjacency_matrix[n1][n2] = weight;
                adjacency_matrix[n2][n1] = weight;

                adjacency_list[n1].push_back({n2,weight});
                adjacency_list[n2].push_back({n1,weight});

                in_degree[n1]++; out_degree[n1]++;
                in_degree[n2]++; out_degree[n2]++;
            }
            else{
                is_directed = true;

                adjacency_matrix[n1][n2] = weight;
                adjacency_list[n1].push_back({n2,weight});

                in_degree[n2]++; out_degree[n1]++;
            }
            E += 1;
        }

        vector<T> get_neighbors(T data){   // gets all the neighbors of an vertices
            vector<T> neighbors;
            for(pair<LL,LL> ngh_index: adjacency_list[data_to_index[data]]){
                neighbors.push_back(all_vertices[ngh_index.first]);
            }
            return neighbors;
        }

        LL get_degree(T data){   // gets degree of a vertices if it is undirected
            return in_degree[data_to_index[data]] + out_degree[data_to_index[data]];
        }

        LL get_indegree(T data){  // gets in-degree of a vertices if it is directed
            return in_degree[data_to_index[data]];
        }

        LL get_outdegree(T data){  // gets out-degree of a vertices if it is directed
            return out_degree[data_to_index[data]];
        }

        namespace bfs{
            bool detect_cycle(){
                if(!is_directed){
                    bool visited[V];
                    visited[0] = false;

                    for(LL ith_node=0; ith_node<V; ith_node++){
                        if(!visited[ith_node]){
                            if(cycle_on_component(ith_node,visited))
                                return true;
                        }
                    }
                    return false;
                }
                else{
                    /* call toposort */
                }
            }
        }

        namespace dfs{
            bool detect_cycle(){
                /* code */
            }
        }
};

#include<iostream>
#include<vector>
void print_dfs(std::vector<std::vector<int>> matrix,const int& start_vertex,std::vector<bool>& visited)
{
    std::cout << start_vertex << " ";
    visited[start_vertex] = true;
    int size = matrix.size();
    for(int i=0;i<size;i++)
    {
        if(visited[i] == false && matrix[start_vertex][i] == 1)
        {
            print_dfs(matrix,i,visited);
        }
    }
}





std::vector<int> vec;

int main()
{
    int num_nodes{},num_edges{};
    std::cout << "Enter the number of nodes: ";
    std::cin >> num_nodes;
    std::cout << "Enter the number of edges: ";
    std::cin >> num_edges;

    std::vector<std::vector<int> > matrix(num_nodes,std::vector<int>(num_nodes,0));

    for(int i=1;i<=num_edges;i++)
    {
        int first_vertex{},second_vertex{};
        std::cout << "Enter the first vertex: ";
        std::cin >> first_vertex;
        std::cout << "Enter the second vertex: ";
        std::cin >> second_vertex;
        matrix[first_vertex][second_vertex] = 1;
        matrix[second_vertex][first_vertex] = 1;
    }

    std::vector<bool> visited(num_nodes,false);
    std::cout << "Depth First Search Traversal: ";
    print_dfs(matrix,0,visited);
    return 0;
}


BFS:queue :::  A (BCD) (E) (G) (F) (IH)
            
            
            
        

            QUEUE:      G F H I F
            VISI[9]:A(T) C(T) B(T) D(T) G(T) E(T)
            BFS:A C B E














DFS:
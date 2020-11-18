#include<iostream>
#include<vector>

void print_dfs(std::vector<std::vector<int>> matrix,const int start_vertex,std::vector<bool>& visited)
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

void dfs(std::vector<std::vector<int>> matrix)
{
    int size = matrix.size();
    std::vector<bool> visited(size,false);
    for(int i=0;i<size;i++)
    {
        if(!visited[i])
        {
            print_dfs(matrix,i,visited);
        }
    }
}


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
    dfs(matrix);
    std::cout << std::endl;
    return 0;
}
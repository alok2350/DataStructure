#include<iostream>
#include<vector>
#include<queue>

void print_bfs(std::vector<std::vector<int>> matrix,const int& start_vertex)
{
    int size = matrix.size();
    std::vector<bool> visited(size,false);
    std::queue<int> q;
    q.push(start_vertex);
    visited[start_vertex] = true;
    while(!q.empty())
    {
        int n = q.front();
        q.pop();
        std::cout << n << " ";
        for(int i=0;i<size;i++)
        {
            if(matrix[n][i] == 1 && visited[i] == false)
            {
                q.push(i);
                visited[i] = true;
            }
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

    std::vector<std::vector<int>> matrix(num_nodes,std::vector<int>(num_nodes,0));
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
    std::cout << "Breadth First Search Traversal: ";
    print_bfs(matrix,0);
    std::cout << std::endl;
    return 0;
}




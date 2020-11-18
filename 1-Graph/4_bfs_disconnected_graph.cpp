#include<iostream>
#include<vector>
#include<queue>

void print_bfs(std::vector<std::vector<int>> matrix,const int& start_vertex,std::vector<bool>& visited)
{
    int size = matrix.size();
    std::cout << start_vertex << " ";
    visited[start_vertex] = true;
    std::queue<int> q;
    q.push(start_vertex);
    while(!q.empty())
    {
        int s = q.front();
        q.pop();
        for(int i=0;i<size;i++)
        {
            if(visited[i] == false && matrix[s][i] == 1)
            {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

void bfs(std::vector<std::vector<int>> matrix)
{
    int size = matrix.size();
    std::vector<bool> visited(size,false);
    for(int i=0;i<size;i++)
    {
        if(!visited[i])
        {
            print_bfs(matrix,i,visited);
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
    
    for(int i=0;i<num_edges;i++)
    {
        int first_vertex{},second_vertex{};
        std::cout << "Enter the first vertex: ";
        std::cin >> first_vertex;
        std::cout << "Enter the second vertex: ";
        std::cin >> second_vertex;
        matrix[first_vertex][second_vertex] == 1;
        matrix[second_vertex][first_vertex] == 1;
    }
    bfs(matrix);
    std::cout << std::endl;
    return 0;

}
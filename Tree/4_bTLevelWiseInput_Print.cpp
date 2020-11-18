#include<iostream>
#include<queue>



template<typename T>
class node
{
    public:
        T data{};
        node* left{};
        node* right{};
        node(T data)
        {
            this->data = data;
            left = nullptr;
            right = nullptr;
        }
};

node<int>* takeInput()
{
    int rootdata{};
    std::cout << "Enter the data: ";
    std::cin >> rootdata;
    node<int>* root = new node<int>(rootdata);
    std::queue<node<int>*> q;
    q.push(root);
    while(!q.empty())
    {
        node<int>* f = q.front();
        q.pop();
        std::cout << "Enter left child of " << f->data << std::endl;
        int leftchilddata{};
        std::cin >> leftchilddata;
        if(leftchilddata != -1)
        {
            node<int>* child = new node<int>(leftchilddata);
            q.push(child);
            f->left = child;
        }
        std::cout << "Enter right child of " << f->data << std::endl;
        int rightchilddata{};
        std::cin >> rightchilddata;
        if(leftchilddata != -1)
        {
            node<int>* child = new node<int>(rightchilddata);
            q.push(child);
            f->right = child;
        }
    }
    return root;
}





int main()
{

}
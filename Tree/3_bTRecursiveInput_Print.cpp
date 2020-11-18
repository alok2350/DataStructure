//binary tree

#include<iostream>
#include<vector>

template<typename T>
class Treenode
{
    public:
        T data{};
        Treenode* left{};
        Treenode* right{};
        Treenode(T data)
        {
            this->data = data;
            left = nullptr;
            right = nullptr;
        }
        ~Treenode()
        {
            delete left;
            delete right;
        }
};

Treenode<int>* takeInput()
{
    int rootdata{};
    std::cout << "Enter the data: " <<std::endl;
    std::cin >> rootdata;
    if(rootdata == -1)
    {
        return nullptr;
    }
    Treenode<int>* root = new Treenode<int>(rootdata);
    Treenode<int>* leftChild = takeInput();
    Treenode<int>* rightChild = takeInput();
    root->left = leftChild;
    root->right = rightChild;
    return root;
}

void printTree(Treenode<int>* root)
{
    if(root == nullptr)
    {
        return;
    }
    std::cout << root->data << ":";
    if(root->left!=nullptr)
    {
        std::cout << "L" << root->left->data;
    }
    if(root->right != nullptr)
    {
        std::cout << "R" << root->right->data;
    }
    std::cout << std::endl;
    printTree(root->left);
    printTree(root->right);
}

int main()
{
    Treenode<int>* root = takeInput();
    printTree(root);
    return 0;
}
//general tree

#include<iostream>
#include<vector>

template<typename T>
class TreeNode
{
    public:
        T data{};
        std::vector<TreeNode<T>*> children{};
        TreeNode(T data)
        {
            this->data = data;
        }
};



void printTree(TreeNode<int>* root)
{
    if(root == nullptr)
    {
        return;
    }
    std::cout << root->data << ":";
    for(int i=0;i<root->children.size();i++)
    {
        std::cout << root->children[i]->data << ",";
    }
    std::cout<<std::endl;
    for(int i=0;i<root->children.size();i++)
    {
        printTree(root->children[i]);
    }
}

TreeNode<int>* takeInput()
{
    int rootData{};
    std::cout << "Enter the data: ";
    std::cin >> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);
    int numChild{};
    std::cout << "Enter the number of children of " << rootData << std::endl;
    std::cin >> numChild;
    for(int i=0;i<numChild;i++)
    {
        TreeNode<int>* child = takeInput();
        root->children.push_back(child);
    }
    return root;
}

int main()
{
    TreeNode<int>* root = takeInput();
    printTree(root);
    return 0;
}
#include <iostream>
#include <vector>
#include <queue>


template <typename T>
class TreeNode
{
public:
    T data{};
    std::vector<TreeNode<T>*> children{};
    TreeNode(T data)
    {
        this->data = data;
    }
    ~TreeNode()
    {
        for (int i = 0; i < children.size(); i++)
        {
            delete children[i];
        }
    }
};

void printTreeLevelWise(TreeNode<int> *root)
{
    std::queue<TreeNode<int> *> q;
    q.push(root);
    while (!q.empty())
    {
        TreeNode<int> *f = q.front();
        q.pop();
        std::cout << f->data << ":";
        for (int i = 0; i < f->children.size(); i++)
        {
            std::cout << f->children[i]->data << ";";
        }
        std::cout << std::endl;
        for (int i = 0; i < f->children.size(); i++)
        {
            q.push(f->children[i]);
        }
    }
}

TreeNode<int> *takeInputLevelWise()
{
    int rootdata{};
    std::cout << "Enter the data: ";
    std::cin >> rootdata;
    TreeNode<int> *root = new TreeNode<int>(rootdata);
    std::queue<TreeNode<int>*> q;
    q.push(root);
    while (!q.empty())
    {
        TreeNode<int> *f = q.front();
        q.pop();
        std::cout << "Enter the number of children of " << f->data << std::endl;
        int numChild{};
        std::cin >> numChild;
        for (int i = 1; i <= numChild; i++)
        {
            int childData{};
            std::cout << "Enter " << i << "th child of " << f->data << std::endl;
            std::cin >> childData;
            TreeNode<int> *child = new TreeNode<int>(childData);
            q.push(child);
            f->children.push_back(child);
        }
    }
    return root;
}
int CountNodes(TreeNode<int> *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    int ans = 1;
    for (int i = 0; i < root->children.size(); i++)
    {
        ans += CountNodes(root->children[i]);
    }
    return ans;
}

int height(TreeNode<int> *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    int mx = 0;
    for (int i = 0; i < root->children.size(); i++)
    {
        int childHeight = height(root->children[i]);
        if (childHeight > mx)
        {
            mx = childHeight;
        }
        //mx = std::max(mx,height(root->children[i]));
    }
    return mx + 1;
}

void printAtLevelK(TreeNode<int> *root, int k)
{
    if (root == nullptr)
    {
        return;
    }
    if (k == 0)
    {
        std::cout << root->data << std::endl;
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        printAtLevelK(root->children[i], k - 1);
    }
}

int countLeafNodes(TreeNode<int> *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    if (root->children.size() == 0)
    {
        return 1;
    }
    int ans = 0;
    for (int i = 0; i < root->children.size(); i++)
    {
        ans += countLeafNodes(root->children[i]);
    }
    return ans;
}

void preOrder(TreeNode<int> *root)
{
    if (root == nullptr)
    {
        return;
    }
    std::cout << root->data << " ";
    for (int i = 0; i < root->children.size(); i++)
    {
        preOrder(root->children[i]);
    }
}

void PostOrder(TreeNode<int> *root)
{
    if (root == nullptr)
    {
        return;
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        PostOrder(root->children[i]);
    }
    std::cout << root->data << " ";
}

void deleteTree(TreeNode<int> *root)
{
    if (root == nullptr)
    {
        return;
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        deleteTree(root->children[i]);
    }
    delete root;
}

int main()
{
    TreeNode<int> *root = takeInputLevelWise();
    printTreeLevelWise(root);
    // std::cout << "Number of Nodes: " << CountNodes(root) << std::endl;
    // std::cout << "Height of the Tree: " << height(root) << std::endl;
    // int level{};
    // std::cout << "Enter the Level to print Nodes at that level: ";
    // std::cin >> level;
    // printAtLevelK(root,level);
    // std::cout << "Number of leaf Nodes: " << countLeafNodes(root) << std::endl;
    std::cout << "Pre-order: ";
    preOrder(root);
    std::cout << std::endl;
    std::cout << "Post-order: ";
    PostOrder(root);
    std::cout << std::endl;
    delete root;
    return 0;
}
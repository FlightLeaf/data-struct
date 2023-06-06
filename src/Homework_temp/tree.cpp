
//////////实验5：二叉树的链式存储（6月30日截止）///////////

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <iomanip>
using namespace std;
class BinaryTree;
class BinTreeNode
{ // 结点类的定义
    friend BinaryTree;

public:
    BinTreeNode()
    {
        leftChild = NULL;
        rightChild = NULL;
    }
    BinTreeNode(char x, BinTreeNode *left = NULL, BinTreeNode *right = NULL) : data(x), leftChild(left), rightChild(right) {} // 构造函数
    ~BinTreeNode() {}                                                                                                         // 析构函数
private:
    BinTreeNode *leftChild, *rightChild; // 左、右子女链域
    char data;                           // 数据域
};
class BinaryTree
{
public:
    BinaryTree() : root(NULL){};
    BinaryTree(char value)
    {
        RefValue = value;
        root = NULL;
    }
    ~BinaryTree() { destroy(root); }
    /// @brief 创建书
    void CreateBinTree() { CreateBinTree(root); }

    /// @brief 是否为空
    /// @return true 空
    bool IsEmpty() { return (root == NULL) ? true : false; }

    /// @brief 获取双亲节点
    /// @param current 带获取对象
    /// @return 双亲结点指针
    BinTreeNode *Parent(BinTreeNode *current)
    {
        return (root == NULL || root == current) ? NULL : Parent(root, current);
    }

    /// @brief 获取左孩子
    /// @param current 带获取对象
    /// @return 左孩子指针
    BinTreeNode *LeftChild(BinTreeNode *current)
    {
        return (current != NULL) ? current->leftChild : NULL;
    }

    /// @brief 获取右孩子
    /// @param current 带获取对象
    /// @return 右孩子指针
    BinTreeNode *RightChild(BinTreeNode *current)
    {
        return (current != NULL) ? current->rightChild : NULL;
    }
    /// @brief 计算树高度
    /// @return 高度
    int Height() { return Height(root); }

    /// @brief 计算树的大小
    /// @return 树的大小
    int Size() { return Size(root); }

    /// @brief 叶子节点计算
    /// @return 叶子节点个数
    int countLeaves() { return countLeaves(root); }

    /// @brief 获取根节点
    /// @return 根节点指针
    BinTreeNode *GetRoot() const { return root; }

    /// @brief 前序遍历
    void preOrder() { preOrder(root); }

    /// @brief 中序遍历
    void inOrder() { inOrder(root); }

    /// @brief 后序遍历
    void postOrder() { postOrder(root); }

    /// @brief 查找目标在树中的个数
    /// @param target 待查找的目标
    /// @return 个数
    int countFind(char &target) { return countFind(root, target); };

    void outPrint() { outPrint(root); };

private:
    BinTreeNode *root; // 二叉树的根指针
    char RefValue;     // 数据输入停止标志

    void CreateBinTree(BinTreeNode *&subTree);
    BinTreeNode *Parent(BinTreeNode *subTree, BinTreeNode *current);
    int Height(BinTreeNode *subTree);
    int Size(BinTreeNode *subTree);
    int countLeaves(BinTreeNode *subTree);
    int countFind(BinTreeNode *subTree, char &target);
    void outPrint(BinTreeNode *subTree, int indent = 0);
    void preOrder(BinTreeNode *subTree);  // 前序遍历
    void inOrder(BinTreeNode *subTree);   // 中序遍历
    void postOrder(BinTreeNode *subTree); // 后序遍历
    void destroy(BinTreeNode *&subTree){};
};

void BinaryTree ::CreateBinTree(BinTreeNode *&subTree)
{ // 私有函数: 建立根为subTree的子树
    char item;
    cin >> item;
    if (item != RefValue)
    {
        subTree = new BinTreeNode(item);
        CreateBinTree(subTree->leftChild);
        CreateBinTree(subTree->rightChild);
    }
    else
        subTree = NULL;
};

void BinaryTree ::inOrder(BinTreeNode *subTree)
{
    if (subTree != NULL)
    {
        inOrder(subTree->leftChild);
        cout << subTree->data << " ";
        inOrder(subTree->rightChild);
    }
}
void BinaryTree ::preOrder(BinTreeNode *subTree)
{
    if (subTree != NULL)
    {
        cout << subTree->data << " ";
        preOrder(subTree->leftChild);
        preOrder(subTree->rightChild);
    }
}
void BinaryTree ::postOrder(BinTreeNode *subTree)
{
    if (subTree != NULL)
    {
        postOrder(subTree->leftChild);
        postOrder(subTree->rightChild);
        cout << subTree->data << " ";
    }
}

BinTreeNode *BinaryTree::Parent(BinTreeNode *subTree, BinTreeNode *current)
{
    if (subTree == NULL)
        return NULL;
    if (subTree->leftChild == current || subTree->rightChild == current)
        return subTree;
    BinTreeNode *temp;
    if ((temp = Parent(subTree->leftChild, current)) != NULL)
        return temp;
    else
        return Parent(subTree->rightChild, current);
}

int BinaryTree::Height(BinTreeNode *subTree)
{
    if (subTree == NULL)
        return 0;
    else
    {
        int i = Height(subTree->leftChild);
        int j = Height(subTree->rightChild);
        return (i < j ? j + 1 : i + 1);
    }
}

int BinaryTree::Size(BinTreeNode *subTree)
{
    if (subTree == NULL)
        return 0;
    else
        return 1 + Size(subTree->leftChild) + Size(subTree->rightChild);
}

int BinaryTree::countFind(BinTreeNode *subTree, char &target)
{
    int count = 0;
    if (subTree == NULL)
        return count;
    if (target == subTree->data)
        count++;
    count += countFind(subTree->leftChild, target);
    count += countFind(subTree->rightChild, target);
    return count;
}

int BinaryTree::countLeaves(BinTreeNode *subTree)
{
    if (subTree == NULL)
    { // 如果节点为空，返回0
        return 0;
    }
    else if (!subTree->leftChild && !subTree->rightChild)
    { // 如果节点是叶子节点，返回1
        return 1;
    }
    else
    { // 否则递归计算左右子树的叶子节点数
        return countLeaves(subTree->leftChild) + countLeaves(subTree->rightChild);
    }
}

void BinaryTree::outPrint(BinTreeNode *root, int indent)
{
    if (root == NULL)
    {
        return;
    }
    cout << setw(indent)<< root->data << endl;
    cout<<" ";
    outPrint(root->leftChild, indent + 2);
    outPrint(root->rightChild, indent + 2);
}

int main()
{
    char option;
    BinaryTree a = BinaryTree('#');
    while (cin >> option)
    {
        if (option == 'C')
        {
            a.CreateBinTree();
            cout << "Created success!" << endl;
        }
        else if (option == 'H')
        {
            cout << "Height=" << a.Height() << "." << endl;
        }
        else if (option == 'L')
        {
            cout << "Leaf=" << a.countLeaves() << "." << endl;
        }
        else if (option == 'N')
        {
            cout << "Nodes=" << a.Size() << "." << endl;
        }
        else if (option == '1')
        {
            cout << "Preorder is:";
            a.preOrder();
            cout << "." << endl;
        }
        else if (option == '2')
        {
            cout << "Inorder is:";
            a.inOrder();
            cout << "." << endl;
        }
        else if (option == '3')
        {
            cout << "Postorder is:";
            a.postOrder();
            cout << "." << endl;
        }
        else if (option == 'F')
        {
            char item;
            cin >> item;
            cout << "The count of " << item << " is " << a.countFind(item) << "." << endl;
        }
        else if (option == 'P')
        {
            cout <<"The tree is:"<<endl;
            a.outPrint();
        }
    }
    return 0;
}

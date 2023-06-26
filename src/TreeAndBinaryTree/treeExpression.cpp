
////////// 实验6：二叉树与表达式（6月30日截止）///////////

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <iomanip>
using namespace std;

template <class T>
class BinaryTree;

template <class T>
class BinTreeNode
{
    friend class BinaryTree<T>;

public:
    BinTreeNode()
    {
        leftChild = NULL;
        rightChild = NULL;
    }
    BinTreeNode(T x, BinTreeNode<T> *left = NULL, BinTreeNode<T> *right = NULL) : data(x), leftChild(left), rightChild(right) {} // 构造函数
    ~BinTreeNode() {}                                                                                                            // 析构函数
private:
    BinTreeNode<T> *leftChild, *rightChild; // 左、右子女链域
    T data;                                 // 数据域
};
template <class T>
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
    /// @brief 创建树
    void CreateBinTree() { CreateBinTree(root); }

    /// @brief 是否为空
    /// @return true 空
    bool IsEmpty() { return (root == NULL) ? true : false; }

    /// @brief 获取双亲节点
    /// @param current 带获取对象
    /// @return 双亲结点指针
    BinTreeNode<T> *Parent(BinTreeNode<T> *current)
    {
        return (root == NULL || root == current) ? NULL : Parent(root, current);
    }

    /// @brief 获取左孩子
    /// @param current 带获取对象
    /// @return 左孩子指针
    BinTreeNode<T> *LeftChild(BinTreeNode<T> *current)
    {
        return (current != NULL) ? current->leftChild : NULL;
    }

    /// @brief 获取右孩子
    /// @param current 带获取对象
    /// @return 右孩子指针
    BinTreeNode<T> *RightChild(BinTreeNode<T> *current)
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
    BinTreeNode<T> *GetRoot() const { return root; }

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

    /// @brief 输出缩进图
    void outPrint() { outPrint(root); };

    /// @brief 计算表达式的值
    /// @return 结果值
    int result(){ return result(root); }

private:
    BinTreeNode<T> *root; // 二叉树的根指针
    char RefValue;        // 数据输入停止标志

    void CreateBinTree(BinTreeNode<T> *&subTree);
    BinTreeNode<T> *Parent(BinTreeNode<T> *subTree, BinTreeNode<T> *current);
    int Height(BinTreeNode<T> *subTree);
    int Size(BinTreeNode<T> *subTree);
    int countLeaves(BinTreeNode<T> *subTree);
    int countFind(BinTreeNode<T> *subTree, T &target);
    void outPrint(BinTreeNode<T> *subTree, int indent = 0);
    void preOrder(BinTreeNode<T> *subTree);  // 前序遍历
    void inOrder(BinTreeNode<T> *subTree);   // 中序遍历
    void postOrder(BinTreeNode<T> *subTree); // 后序遍历
    void destroy(BinTreeNode<T> *&subTree){};
    int result(BinaryTree<T> *subTree);
};

template <class T>
void BinaryTree<T>::CreateBinTree(BinTreeNode<T> *&subTree)
{
    T item;
    cin >> item;
    if (item != RefValue)
    {
        subTree = new BinTreeNode<T>(item); // 先序建立
        CreateBinTree(subTree->leftChild);
        CreateBinTree(subTree->rightChild);
    }
    else
        subTree = NULL;
};

template <class T>
void BinaryTree<T>::inOrder(BinTreeNode<T> *subTree)
{
    if (subTree != NULL)
    {
        inOrder(subTree->leftChild);
        cout << subTree->data << " ";
        inOrder(subTree->rightChild);
    }
}

template <class T>
void BinaryTree<T>::preOrder(BinTreeNode<T> *subTree)
{
    if (subTree != NULL)
    {
        cout << subTree->data << " ";
        preOrder(subTree->leftChild);
        preOrder(subTree->rightChild);
    }
}

template <class T>
void BinaryTree<T>::postOrder(BinTreeNode<T> *subTree)
{
    if (subTree != NULL)
    {
        postOrder(subTree->leftChild);
        postOrder(subTree->rightChild);
        cout << subTree->data << " ";
    }
}

template <class T>
BinTreeNode<T> *BinaryTree<T>::Parent(BinTreeNode<T> *subTree, BinTreeNode<T> *current)
{
    if (subTree == NULL)
        return NULL;
    if (subTree->leftChild == current || subTree->rightChild == current)
        return subTree;
    BinTreeNode<T> *temp;
    if ((temp = Parent(subTree->leftChild, current)) != NULL)
        return temp;
    else
        return Parent(subTree->rightChild, current);
}

template <class T>
int BinaryTree<T>::Height(BinTreeNode<T> *subTree)
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

template <class T>
int BinaryTree<T>::Size(BinTreeNode<T> *subTree)
{
    if (subTree == NULL)
        return 0;
    else
        return 1 + Size(subTree->leftChild) + Size(subTree->rightChild);
}

template <class T>
int BinaryTree<T>::countFind(BinTreeNode<T> *subTree, T &target)
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

template <class T>
int BinaryTree<T>::countLeaves(BinTreeNode<T> *subTree)
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

template <class T>
void BinaryTree<T>::outPrint(BinTreeNode<T> *root, int indent)
{
    if (root == NULL)
    {
        return;
    }
    cout << setw(indent) << root->data << endl;
    cout << " ";
    outPrint(root->leftChild, indent + 2);
    outPrint(root->rightChild, indent + 2);
}

template<class T>
int BinaryTree<T>::result(BinaryTree<T> *subTree)
{
    
    return 0;
}


int main()
{
    BinaryTree<char> binaryTree = BinaryTree<char>('@');
    binaryTree.CreateBinTree();
    binaryTree.inOrder();
    binaryTree.outPrint();
    return 0;
}
#include <iostream>
#include <stdlib.h>
using namespace std;

class SingleList;

class LinkNode
{
    friend class SingleList;

private:
    LinkNode *left;
    LinkNode *right;
    int data;

public:
    LinkNode(LinkNode *btr = NULL, LinkNode *ptr = NULL) { left = btr, right = ptr; };
    LinkNode(const int &item, LinkNode *btr = NULL, LinkNode *ptr = NULL)
    {
        data = item;
        left = btr;
        right = ptr;
    };
    ~LinkNode(){};
};

class SingleList
{
private:
    LinkNode *first;

public:
    SingleList() { first = new LinkNode(); };
    ~SingleList() { makeEmpty(); };
    int length();
    int locate(int i);
    void makeEmpty();
    void input(int num);
    void add(SingleList *a);
    void insert(int num);
    void output();
};

int SingleList::length()
{
    LinkNode *temp = first->right;
    int length = 0;
    while (temp != NULL)
    {
        length++;
        temp = temp->right;
    }
    return length;
}

int SingleList::locate(int i)
{
    LinkNode *temp = first;
    if (i <= 0)
        exit(1);
    int j = 0;
    while (temp != NULL && j < i)
    {
        temp = temp->right;
        j++;
    }
    return temp->data;
}

void SingleList::makeEmpty()
{
    LinkNode *temp;
    while (first->right != NULL)
    {
        temp = first->right;
        first->right = temp->right;
        delete temp;
    }
}

void SingleList::input(int num)
{
    int da;
    for (int i = 0; i < num; i++)
    {
        cin >> da;
        LinkNode *temp = new LinkNode(da);
        LinkNode *right_temp = first;
        LinkNode *left_temp = first;
        while (1)
        {
            if (first->right == NULL)
            {
                first->right = temp;
                temp->left = first;
                break;
            }
            else
            {
                left_temp = right_temp;
                right_temp = right_temp->right;
                if (da < right_temp->data)
                {
                    temp->right = right_temp;
                    temp->left = left_temp;
                    left_temp->right = temp;
                    right_temp->left = temp;
                    break;
                }
                else if (da == right_temp->data)
                {
                    break;
                }
                if (right_temp->right == NULL)
                {
                    right_temp->right = temp;
                    temp->left = right_temp;
                    break;
                }
            }
        }
    }
}

void SingleList::output()
{
    LinkNode *temp = first;
    while (temp->right != NULL)
    {
        temp = temp->right;
        cout << temp->data << endl;
    }
}

void SingleList::insert(int index)
{
    LinkNode *temp = new LinkNode(index);
    LinkNode *right_temp = first;
    LinkNode *left_temp = first;
    while (1)
    {
        if (first->right == NULL)
        {
            first->right = temp;
            temp->left = first;
            break;
        }
        else
        {
            left_temp = right_temp;
            right_temp = right_temp->right;
            if (index < right_temp->data)
            {
                temp->right = right_temp;
                temp->left = left_temp;
                left_temp->right = temp;
                right_temp->left = temp;
                break;
            }
            else if (index == right_temp->data)
            {
                break;
            }
            if (right_temp->right == NULL)
            {
                right_temp->right = temp;
                temp->left = right_temp;
                break;
            }
        }
    }
}

void SingleList::add(SingleList *a)
{
    for (int i = 1; i <= a->length(); i++)
    {
        insert(a->locate(i));
    }
}
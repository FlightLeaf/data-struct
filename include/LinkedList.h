#include <iostream>
template <class T>
class LinkNode
{
public:
    LinkNode *link;
    T data;

public:
    LinkNode(LinkNode *ptr = NULL) { link = ptr; };
    LinkNode(const T &item, LinkNode *ptr = NULL)
    {
        data = item;
        link = ptr;
    };
    ~LinkNode(){};
};
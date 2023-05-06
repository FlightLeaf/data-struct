# 数据结构

```C++
class LinkNode
{
    friend List;
    private:
        LinkNode *link;
        int data;
    public:
    LinkNode(LinkNode *ptr = NULL){link = ptr;};
    LinkNode(const int &item,LinkNode *ptr = NULL)
    {
        data = item;
        link = ptr;
    };
    ~LinkNode(){};
};

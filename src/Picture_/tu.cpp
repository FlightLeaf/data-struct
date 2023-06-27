/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */


#include "iostream"
#include "stdlib.h"
using namespace std;
typedef int E;              //边的权值 的数据类型
typedef char T;          //顶点值 的数据类型 
#define maxWeight 100 
class Graphmtx  { 
private:
	T *VerticesList; 		          //顶点表
	E **Edge;				          //邻接矩阵
	int numVertices;
	int maxVertices;
	int numEdges; 
public: 
	Graphmtx (int sz = 20);    //构造函数
	~Graphmtx () { delete [ ]VerticesList;  delete [ ]Edge; } 
	bool insertVertex (const T vertex);	//插入顶点vertex
	bool insertEdge (int v1, int v2, E cost);//插入边(v1, v2),权值为cost
	int getDegree (int VerticeIndex);// 查找下标为VerticeIndex的节点的度
};
Graphmtx::Graphmtx (int sz) { //构造函数
	maxVertices = sz;  
	numVertices = 0;  numEdges = 0; 
	int i, j;
	VerticesList = new T[maxVertices];  //创建顶点表
	Edge =  new E * [maxVertices];
	for (i = 0; i < maxVertices; i++)
		Edge[i] = new E [maxVertices];   //邻接矩阵 
	for (i = 0; i < maxVertices; i++)        //矩阵初始化
		for (j = 0; j < maxVertices; j++)
			Edge[i][j] = (i == j) ? 0 : maxWeight;  //maxWeight

};
bool Graphmtx::insertVertex (const T vertex ) {//插入顶点 vertex 
	if (numVertices==maxVertices) return false;
	VerticesList[numVertices++] =vertex;
	return true;
};
bool Graphmtx::insertEdge (int v1,int v2,E cost ) {
	//插入一条起始顶点为v1、终止顶点为 v2的边 
	if(v1 < 0 || v1 >=numVertices   || v2 < 0 || v2 >= numVertices)
	{cout << "参数v1或v2越界出错!" << endl;return false;}		  
	Edge[v1][v2] = cost; Edge[v2][v1] = cost;//插入边
	numEdges++;	                             //边的个数加1
	return true;
}
int Graphmtx::getDegree (int VerticeIndex)
{
    int res = -1;
    for(int i = 0;i<numVertices;i++)
    {
        if(Edge[VerticeIndex][i] != maxWeight)
        {
            res++;
        }
    }
    return res;
}
int main()
{
	Graphmtx a;
	int Vertices;
	cin>>Vertices;  //读入顶点的个数
	for (int i=1 ;i<=Vertices;i++)
	{ T value;
	cin>>value;
	a.insertVertex(value);}       // 读入每个顶点的值
	int Edges;
	cin>>Edges;                  // 读入边的条数
	for (int i=1 ;i<=Edges;i++){   
		int row,col,weight;
		cin>>row>>col>>weight;    // 读入要插入的边（行号，列号，权值）
		a.insertEdge(row,col,weight);
	}  
	int whichVertice;         
	cin>>whichVertice;           //读入待求节点的下标
	cout<<a.getDegree(whichVertice)<<endl;  //求下标为whichVertice的顶点的度。
	return 0;
}
/* PRESET CODE END - NEVER TOUCH CODE ABOVE */


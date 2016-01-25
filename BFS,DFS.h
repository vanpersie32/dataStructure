#include<vector>
#include<iostream>
using namespace std;
class GPHFS
{
public:
	GPHFS();//自定义无向图
	GPHFS(char nodes[],int NumNodes,int NumEdges,char edges[][2]);//
	~GPHFS();
	void BFS();
	void NeiNodes(int j,vector<int>&neiNodes);
	void DFS();
private:
	int numNodes,numEdges;
	vector<char>nodesNames;
	int **udgMatrix;
	int nodeIndex(char node);
	void DFS(int node,int *visited);

};
GPHFS::GPHFS()
{
	cout<<"please enter the number of nodes and number of edges"<<endl;
	cin>>numNodes>>numEdges;
	if(numNodes<1||numEdges<1||(numEdges>numNodes*(numNodes-1)))
	{
		throw("please enter the right value");
	}
	udgMatrix=new int*[numNodes];
	for(int i=0;i<numNodes;i++)
	{
		char nodeName;
		cout<<"the nodes("<<i<<")："<<endl;
		cin>>nodeName;
		nodesNames.push_back(nodeName);
		udgMatrix[i]=new int[numNodes];
		memset(udgMatrix[i],0,sizeof(char)*numNodes);
	}
	for(int i=0;i<numEdges;i++)
	{
		int index1,index2;
		char node1,node2;
		cout<<"the edge("<<i<<"):"<<endl;
		cin>>node1>>node2;
		index1=nodeIndex(node1);
		index2=nodeIndex(node2);
		if(index1==-1||index2==-1)
		{
			cout<<"input error"<<endl;
			return;
		}
		//无向图邻接矩阵是对称阵
		udgMatrix[index1][index2]=1;
		udgMatrix[index2][index1]=1;
	}
}
GPHFS::GPHFS(char nodes[],int NumNodes,int NumEdges,char edges[][2])
{
	numNodes=NumNodes;
	numEdges=NumEdges;
	for(int i=0;i<NumNodes;i++)
		nodesNames.push_back(nodes[i]);
	udgMatrix=new int*[NumNodes];
	for(int i=0;i<NumNodes;i++)
	{
		udgMatrix[i]=new int[NumNodes];
	}
	for(int i=0;i<NumEdges;i++)
	{
		char node1,node2;
		int index1,index2;
		node1=edges[i][0];
		node2=edges[i][1];
		index1=nodeIndex(node1);
		index2=nodeIndex(node2);
		if(index1==-1||index2==-1)
		{
			cout<<"errors"<<endl;
		}
		udgMatrix[index1][index2]=1;
		udgMatrix[index2][index1]=1;
	}
}
GPHFS::~GPHFS()
{
	for(int i=0;i<numNodes;i++)
	{
		delete udgMatrix[i];
	}
	delete[]udgMatrix;
}
int GPHFS::nodeIndex(char node)
{
	for(int i=0;i<numNodes;i++)
	{
		if(nodesNames.at(i)==node)
			return i;
	}
	return -1;
}
void GPHFS::NeiNodes(int j,vector<int>&neiNodes)
{
	for(int i=0;i<numNodes;i++)
	{
		if(udgMatrix[j][i]==1)
			neiNodes.push_back(i);
	}
}
void GPHFS::DFS()
{
	int *visited=new int[numNodes];
	memset(visited,0,sizeof(int)*numNodes);
	cout<<"DFS:";
	for(int i=0;i<numNodes;i++)
	{
		if(!visited[i])
			DFS(i,visited);
	}
	cout<<endl;
	delete[] visited;
}
void GPHFS::DFS(int node,int*visited)
{
	vector<int>neiNodes;
	NeiNodes(node,neiNodes);
	cout<<nodesNames[node]<<" ";
	visited[node]=1;
	for(int i=0;i<neiNodes.size();i++)
	{
		if(!visited[neiNodes.at(i)])
			DFS(neiNodes.at(i),visited);
	}
}
void GPHFS::BFS()
{
	int *visited=new int[numNodes];
	int head=0,rear=0;
	memset(visited,0,sizeof(int)*numNodes);
	vector<int>nodeQuene;
	cout<<"BFS:";
	for(int i=0;i<numNodes;i++)
	{
		if(!visited[i])
		{
			cout<<nodesNames[i]<<" ";
			visited[i]=1;
			nodeQuene.push_back(i);
			rear++;
		}
		while(head!=rear)
		{
			vector<int>neigs;
			int node;
			node=nodeQuene[head];
			head++;
			NeiNodes(node,neigs);
			for(int j=0;j<neigs.size();j++)
			{
				if(!visited[neigs.at(j)])
				{
					cout<<nodesNames[neigs.at(j)]<<" ";
					visited[neigs.at(j)]=1;
					nodeQuene.push_back(neigs.at(j));
					rear++;
				}
			}
		}
	}
	cout<<endl;
	delete[] visited;
}

#include"BDFS.h"
int main()
{
	char vexs[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};
	char edges[][2] = {
		{'A', 'C'}, 
		{'A', 'D'}, 
		{'A', 'F'}, 
		{'B', 'C'}, 
		{'C', 'D'}, 
		{'E', 'G'}, 
		{'F', 'G'}};
	int vlen = sizeof(vexs)/sizeof(vexs[0]);
	int elen = sizeof(edges)/sizeof(edges[0]);
	GPHFS *search=new GPHFS(vexs,vlen,elen,edges);
	search->BFS();
	search->DFS();
	delete search;

}

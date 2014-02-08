#include "dsets.h"

void DisjointSets::addelements(int num)
{
//	dsets.clear();
   // dsets.resize(num,-1);
  for(int i=0;i<num;i++)
       dsets.push_back(-1);

}

int DisjointSets::find(int elem)
{
	if(dsets[elem]<0)
	return elem;
	else return  /*dsets[elem]=*/find(dsets[elem]);

}
	
void DisjointSets::setunion(int a, int b)
{
	int a_root=find(a);
	int b_root=find(b);
    int newSize=dsets[a_root]+dsets[b_root];
    if(a_root==b_root)return;
    if(dsets[a_root]<=dsets[b_root]){
        dsets[b_root]=a_root;
        dsets[a_root]=newSize;}
    else{
        dsets[a_root]=b_root;
        dsets[b_root]=newSize;}
}




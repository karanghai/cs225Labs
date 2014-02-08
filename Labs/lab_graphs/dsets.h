#ifndef EDSETS_H
#define EDSETS_H

#include <vector>

class DisjointSets{
public:
void addelements(int num);
int find(int elem);
void setunion(int a, int b);

private:
std::vector<int> dsets;

};

#endif

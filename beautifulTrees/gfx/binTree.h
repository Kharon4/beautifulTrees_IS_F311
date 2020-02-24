#pragma once
#include <vector>

template <typename T>
class binTree
{
private:

public:
	T data;
	binTree* left = nullptr;
	binTree* right = nullptr;
	long int xCoord, yCoord, offset;
	bool thread;
	inline void set(binTree* L, binTree* R) { left = L; right = R;}
	binTree();
	binTree(T val);
	void getList(std::vector<binTree*>& list);
};


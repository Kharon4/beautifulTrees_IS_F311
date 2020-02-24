#include "binTree.h"

template <typename T>
void binTree<T>::getList(std::vector<binTree<T>*>& list) {
	if (left != nullptr)left->getList(list);
	if (right != nullptr)right->getList(list);
	list.push_back(this);
}

template <typename T>
binTree<T>::binTree() {
	left = nullptr;
	right = nullptr;
}

template <typename T>
binTree<T>::binTree(T val) {
	data = val;
	left = nullptr;
	right = nullptr;
}
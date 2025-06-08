#pragma once
#include "sortedXORList.h"

class IteratorSortedXORList
{
	friend class sortedXORList;

private:
	const sortedXORList& list;
	int currentPosition;
	Node* prevNode;
	Node* currentNode;
	IteratorSortedXORList(const sortedXORList& list);
public:
	void first();
	void next();
	int getCurrent() const;
	bool valid() const;
};


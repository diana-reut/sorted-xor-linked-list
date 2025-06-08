#pragma once
class IteratorSortedXORList;

struct Node {
	int data;
	Node* link;
};

class sortedXORList
{
private:

	Node* head;
	Node* tail;

	friend class IteratorSortedXORList;

public:
	sortedXORList() : head(nullptr), tail(nullptr) {}
	void insert(int value);
	void remove(int value);
	bool search(int value) const;
	Node* getFromPosition(int position) const;

	IteratorSortedXORList iterator() const;

};


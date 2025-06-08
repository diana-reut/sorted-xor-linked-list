#include "IteratorSortedXORList.h"
#include <exception>

IteratorSortedXORList::IteratorSortedXORList(const sortedXORList& list): list(list) {
	this->currentNode = list.head;
	this->prevNode = nullptr;
	this->currentPosition = 0;
}

void IteratorSortedXORList::first()
{
	this->currentNode = list.head;
	this->prevNode = nullptr;
	this->currentPosition = 0;
}

void IteratorSortedXORList::next()
{
	if (this->valid())
	{
		Node* next = reinterpret_cast<Node*>(reinterpret_cast<uintptr_t>(this->currentNode->link) ^ reinterpret_cast<uintptr_t>(this->prevNode));
		this->prevNode = this->currentNode;
		this->currentNode = next;
		this->currentPosition++;
	}
	else
		throw std::exception("Iterator out of range\n");
}

int IteratorSortedXORList::getCurrent() const
{
	return this->currentNode->data;
}

bool IteratorSortedXORList::valid() const
{
	return currentNode != nullptr;
}

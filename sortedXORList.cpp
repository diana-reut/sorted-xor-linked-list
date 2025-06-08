#include "sortedXORList.h"
#include "IteratorSortedXORList.h"
#include <cstdint>
#include <exception>

void sortedXORList::insert(int value)
{
    Node* newNode = new Node{value, nullptr};
    if (this->head == nullptr)
    {
        //if the list is empty
        head = newNode;
        tail = newNode;
    }
    else if (value <= head->data)
    {
        //if we insert before the head
        newNode->link = this->head;
        this->head->link = reinterpret_cast<Node*>(reinterpret_cast<uintptr_t>(newNode) ^ reinterpret_cast<uintptr_t>(this->head->link));
        this->head = newNode;
    }
    else {
        Node* current = head;
        Node* previous = nullptr;

        while (current != nullptr and current->data < value)
        {
            //searching for the correct position to insert the node
            Node* next = reinterpret_cast<Node*>(reinterpret_cast<uintptr_t>(current->link) ^ reinterpret_cast<uintptr_t>(previous));
            previous = current;
            current = next;
        }
        if (current == nullptr) {
            //if we insert at the end
            newNode->link = this->tail;
			this->tail->link = reinterpret_cast<Node*>(reinterpret_cast<uintptr_t>(this->tail->link) ^ reinterpret_cast<uintptr_t>(newNode));
            this->tail = newNode;
        }
        else {
            //if we insert somewhere in the middle
            //we need to insert between previous and current
            newNode->link = reinterpret_cast<Node*>(reinterpret_cast<uintptr_t>(current) ^ reinterpret_cast<uintptr_t>(previous));
            previous->link = reinterpret_cast<Node*>((reinterpret_cast<uintptr_t>(previous->link) ^ reinterpret_cast<uintptr_t>(current)) ^ reinterpret_cast<uintptr_t>(newNode));
            current->link = reinterpret_cast<Node*>((reinterpret_cast<uintptr_t>(current->link) ^ reinterpret_cast<uintptr_t>(previous)) ^ reinterpret_cast<uintptr_t>(newNode));
        }
    }
}

void sortedXORList::remove(int value)
{
    //TODO: will be implemented later
}

bool sortedXORList::search(int value) const
{
    if (head == nullptr) return false;
    Node* current = this->head;
    Node* previous = nullptr;
    while (current != nullptr and current->data < value)
    {
        Node* next = reinterpret_cast<Node*>(reinterpret_cast<uintptr_t>(current->link) ^ reinterpret_cast<uintptr_t>(previous));
        previous = current;
        current = next;
    }
    if (current != nullptr and current->data == value)
        return true;
    return false;
}

Node* sortedXORList::getFromPosition(int position) const
{
    if (position < 0) throw std::exception("invalid position\n");
    Node* current = this->head;
    Node* previous = nullptr;
    int pos = 0;
    while (current != nullptr and pos < position)
    {
        Node* next = reinterpret_cast<Node*>(reinterpret_cast<uintptr_t>(current->link) ^ reinterpret_cast<uintptr_t>(previous));
        previous = current;
        current = next;
    }
    if (pos == position)
        return current;
    else
        throw std::exception("invalid position\n");
}

IteratorSortedXORList sortedXORList::iterator() const
{
    return IteratorSortedXORList(*this);
}

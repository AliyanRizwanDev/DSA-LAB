#include<iostream>
//#pragma once

using namespace std;

template <class T>
class Node
{
public:
	T data;
	Node *next;
};

template <class T>
class LinkedList
{
protected:
	Node<T> *tail;
	Node<T> *head;

public:
	virtual void insertAtFront(T) = 0;

	virtual void insertAtEnd(T) = 0;

	virtual T removeFromFront() = 0;

	virtual T removeFromEnd() = 0;
};

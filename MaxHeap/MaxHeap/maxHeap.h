#pragma once
#include <iostream>

class MaxHeap {
	int* arr;
	int capacity;
	int heap_size;
public:
	MaxHeap(int capacity);
	int parent(int i);
	int left(int i);
	int right(int i);
	int extractMax();
	void MaxHeapify(int );
	int getMax();
	void increaseKey(int i, int new_key);
	void deletekey(int i);
	void insertKey(int i);
	void print();
	~MaxHeap();
};
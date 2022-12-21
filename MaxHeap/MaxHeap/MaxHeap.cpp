#include "maxHeap.h"


MaxHeap::MaxHeap(int capacity):capacity(capacity),heap_size(0),arr(new int[capacity]) {}

int MaxHeap::parent(int i) { return i >> 1; }

int MaxHeap::left(int i) { return i << 1; }

int MaxHeap::right(int i){ return (i << 1) + 1; }

int MaxHeap::extractMax() {
	if (heap_size < 1) {
		std::cout << "Cannot extract element; Heap is empty...\n";
		return -1;
	}
	int max = arr[0];
	arr[0] = arr[heap_size];
	heap_size--;
	MaxHeapify(0);
	return max;
}

void MaxHeap::MaxHeapify(int i) {
	int l = left(i);
	int r = right(i);
	int largest;
	if (l <= heap_size && arr[l] > arr[i]) {
		largest = l;
	}
	else {
		largest = i;
	}

	if (r <= heap_size && arr[r] > arr[i]) {
		largest = r;
	}
	
	if (largest != i) {
		std::swap(arr[i], arr[largest]);
		MaxHeapify(largest);
	}
}

int MaxHeap::getMax() {
	return arr[0];
}
void MaxHeap::increaseKey(int i, int new_key) {
	if (new_key < arr[i]) {
		std::cout << "New key cannot be smaller than existing key...\n";
		return;
	}
	arr[i] = new_key;
	while (i > 0 && arr[parent(i)] < arr[i]) {
		std::swap(arr[parent(i)], arr[i]);
		i = parent(i);
	}

}
void MaxHeap::deletekey(int i) {
	if (heap_size == 0) {
		std::cout << "\nCannot delete key\n";
		return;
	}

	increaseKey(i, INT_MAX);
	extractMax();
}

void MaxHeap::insertKey(int new_key) {
	if (heap_size == capacity) {
		std::cout << "\nCannot insert new key\n";
		return;
	}
	heap_size++;
	int x = heap_size - 1;
	arr[x] = new_key;

	while (x > 0 && arr[parent(x)] < arr[x]) {
		std::swap(arr[parent(x)], arr[x]);
		x = parent(x);
	}
}
MaxHeap::~MaxHeap() {
	delete arr;
}

void MaxHeap::print() {
	auto begin = arr;
	auto end = arr + heap_size;
	while (begin != end) {
		std::cout << *begin << " ";
		begin++;
	}
	std::cout << std::endl;
}
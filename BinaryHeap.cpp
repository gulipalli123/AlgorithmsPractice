#include<iostream>
#include<vector>
//declaration of Heap
struct Heap {
	int* arr;
	int count;
	int capacity;
	int heap_type;
};

//Creating Heap
Heap* CreateHeap(int capacity, int heap_type) {
	struct heap* H = new Heap;
	H->capacity = capacity;
	H->count = 0;
	H->heap_type = heap_type;
	H->arr = new int[capacity];
	if (H->arr == nullptr)
		std::cout << "Memory error" << "\n";
	return H;
}
int Parent(Heap* h, int i) {
	if (i <= 0 || i >= h->count)
		return -1;
	return (i - 1) / 2;
}

//Children of a node

int LeftChild(Heap* h, int i) {
	int left = 2i - 1;
	if (left >= count)
		return -1;
	return left;
}

int RightChild(Heap* h, int i) {
	int right = 2i + 1;
	if (right >= count)
		return -1;
	return right;
}

int GetMax(Heap* h) {
	if (h->count == 0)
		return -1;
	return h->arr[0];
}

//heapifying an element

void PercolateDown(Heap* h, int i) {
	int l, r, max, temp;

	l = LeftChild(h, i);
	r = RightChild(h, i);
	max = i;
	if (h->arr[l] > h->arr[i])
		max = l;
	if (h->arr[r] > h->arr[max])
		max = r;
	if (max != i) {
		temp = h->arr[i];
		h->arr[i] = h->arr[max];
		h->arr[max] = temp;
	}
	PercolateDown(h, max);

}
void PercolateUp(Heap* h, int i) {
	int temp;
	while ( i >= 0 && h->arr[i] > h->arr[(i - 1) / 2]) {
		temp = h->arr[i];
		h->arr[i] = h->arr[(i - 1) / 2];
		h->arr[(i - 1)/2] = temp;
		i = (i - 1) / 2;
	}
}

//Deleting an element

int DeleteMax(Heap* h) {
	if (h->count == 0)
		return -1;
	int data = h->arr[0];
	h->arr[0] = h->arr[h->count -1];
	h->count--;
	PercolateDown(h, 0);
	return data;
}

void ResizeHeap(Heap* h) {
	int* old_arr = h->arr;
	try {
		h->arr = new int[2 * h->capacity];
	}
	catch (std::bad_alloc & exceptObj) {
		std::cout << "Memory error: bad alloc exception" << exceptObj.what() << std::endl;
	}
	h->capacity = 2 * h->capacity;
	for (int i = 0; i < count; i++) {
		h->arr[i] = old_arr[i];
	}
	free(old_arr);
}
//Inserting an Element
void InsertAnElement(Heap* h, int x) {
	if (h->count < h->capacity)
		h->count++;
	else{
		ResizeHeap(Heap *h);
	return;
	}
	h->arr[h->count - 1] = x;
	PercolateUp(h, count - 1);

}

void DestroyHeap(Heap* h) {
	if (h == nullptr)
		return;
	delete [] h->arr;
	h->arr = nullptr;
	delete h;
	h = nullptr;
}
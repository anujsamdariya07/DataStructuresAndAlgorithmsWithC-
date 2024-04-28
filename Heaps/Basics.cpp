#include <iostream>

using namespace std;

class Heap
{
public:
	int *arr;
	int size;
	int capacity;

	Heap(int capacity)
	{
		this->arr = new int[capacity];
		this->capacity = capacity;
		// size = no. of elements in heap
		this->size = 0;
	}

	void insert(int val)
	{
		if (size == capacity)
		{
			cout << "Heap Overflow" << endl;
			return;
		}

		size++;

		int index = size;
		arr[index] = val;

		while (index > 1)
		{
			int parentIndex = index / 2;
			if (arr[parentIndex] < arr[index])
			{
				swap(arr[parentIndex], arr[index]);
				index = parentIndex;
			}
			else
			{
				break;
			}
		}
	}

	void printHeap()
	{
		cout << "Printing the content of heap:" << endl;
		for (int i = 1; i <= size; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}

	int deleteNode()
	{
		int answer = arr[1];
		// Replacement
		arr[1] = arr[size];
		// Delete last element
		size--;

		int index = 1;
		while (index < size)
		{
			int leftIndex = 2*index;
			int rightIndex = 2*index+1;

			// Find out largest
			int largestIndex = index;

			if (leftIndex <= size && arr[largestIndex] < arr[leftIndex])
			{
				largestIndex = leftIndex;
			}
			if (rightIndex <= size && arr[largestIndex] < arr[rightIndex])
			{
				largestIndex = rightIndex;
			}

			if (index == largestIndex)
			{
				break;
			} else {
				swap(arr[index], arr[largestIndex]);
				index = largestIndex;
			}

		}
		return answer;
	}
};

void heapify(int *arr, int n, int index)
{
    int leftIndex = 2*index;
    int rightIndex = 2*index + 1;
    int largestIndex = index;

    // Maximum of the three
    if (leftIndex <= n && arr[leftIndex] > arr[largestIndex])
    {
        largestIndex = leftIndex;
    }
    if (rightIndex <= n && arr[rightIndex] > arr[largestIndex])
    {
        largestIndex = rightIndex;
    }

    if (index != largestIndex)
    {
        swap(arr[largestIndex], arr[index]);
        index = largestIndex;
        heapify(arr, n, index);
    } else {
        return;
    }
        
}

void buildHeap(int *arr, int n, int index)
{
    for (int i = n/2; i > 0; i--)
    {
        heapify(arr, n, index);
    }
    
}

void heapSort(int arr[], int n)
{
    while (n != 1)
    {
        swap(arr[1], arr[n]);
        n--;
        heapify(arr, n, 1);
    }
    
}

int main()
{
	Heap h(20);
	h.insert(10);
	h.insert(20);
	h.insert(5);
	h.insert(11);
	h.insert(6);

	h.printHeap();

	cout << "Deleted: " << h.deleteNode() << endl;

	h.printHeap();
}
using namespace std;

const int capacity = 100;

class D_aryPyr {
public:
	D_aryPyr(int* arr, int size, int d) {
		this->size = size;
		this->d = d;
		this->arr = arr;
	}
	void Heapify(int index) {

		int *child = new int[this->d + 1];

		while (1)
		{
			for (int i = 1; i <= this->d; i++)
				child[i] = ((this->d*index + i) < this->size) ?
				(this->d*index + i) : -1;

			int max_child = -1, max_child_index;

			for (int i = 1; i <= this->d; i++)
			{
				if (child[i] != -1 &&
					this->arr[child[i]] > max_child)
				{
					max_child_index = child[i];
					max_child = this->arr[child[i]];
				}
			}

			if (max_child == -1)
				break;

			if (this->arr[index] < this->arr[max_child_index])
				swap(this->arr[index], this->arr[max_child_index]);

			index = max_child_index;
		}
	}

	void restoreUp(int index)	{
		int parent = (index - 1) / this->d;

		while (parent >= 0)
		{
			if (this->arr[index] > this->arr[parent])
			{
				swap(this->arr[index], this->arr[parent]);
				index = parent;
				parent = (index - 1) / this->d;
			}
			else
				break;
		}
	}

	void buildHeap()
	{
		for (int i = (this->size - 1) / this->d; i >= 0; i--)
			Heapify(i);
	}

	void insert(int elem)
	{
		this->arr[this->size] = elem;

		this->size++;

		restoreUp(this->size - 1);
	}

	int extractMax()
	{
		int max = this->arr[0];

		this->arr[0] = this->arr[this->size - 1];

		this->size--;

		Heapify(0);

		return max;
	}
	int GetSize() { return this->size; }
private:
	int* arr = new int [capacity];
	int size = 0;
	int d = 0;
};

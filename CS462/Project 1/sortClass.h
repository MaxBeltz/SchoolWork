// I promise that the work submitted here is solely my own.
//
// mbeltz
class Sorts {
	public:
		virtual void arrange(int arr[], int low, int high){};
};

class shellSort: public Sorts{ 
	public:
		void arrange (int arr[], int first, int size);
};

class quickSort: public Sorts{
	public:
		void arrange(int arr[], int low, int high);
		int partition(int arr[], int low, int high);
};

class mergeSort: public Sorts{
	public:
		void arrange(int *arr, int left, int right);
		void merge(int *arr, int left, int middle, int right); 
};

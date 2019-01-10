class TargetSorting {

private:
	TargetSorting();
	~TargetSorting();

public:
	static void TargetQuickSort(int *arr, int low, int high);
	static int Partition(int *arr, int low, int high);
	static void Swapping(int *xp, int *yp);

};

	
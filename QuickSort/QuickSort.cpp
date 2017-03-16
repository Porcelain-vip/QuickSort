#include<iostream>

template<typename Type>
void QuickSortHelp(Type* a, int left, int right)
{
	if (left < right)
	{
		int pivot = left, high = right;                                  //此行拷贝操作很重要`.`
		while (pivot != high)
		{
			while (pivot != high && a[pivot] <= a[high]) --high;
			std::swap(a[pivot], a[high]);
			while (pivot != high && a[pivot] <= a[high]) ++pivot;
			std::swap(a[pivot], a[high]);
		}
		QuickSortHelp<Type>(a, left, pivot - 1);
		QuickSortHelp<Type>(a, pivot + 1, right);
	}
}

template<typename Type>
void QuickSort(Type* a, int n)
{
	QuickSortHelp<Type>(a, 0, n - 1);
}

int main()
{
	using namespace std;
	int a[10];
	cout << "Please enter 10 numbers: ";
	for (int& value : a) cin >> value;
	QuickSort<int>(a, 10);
	cout << "Low-to-High: ";
	for (int& value : a) cout << value << "   "; cout << endl;
	return 0;
}
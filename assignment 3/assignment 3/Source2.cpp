#include <iostream>
#include <vector>
#include <list>
#include <cstdlib>

using namespace std;
int numcomps = 0;
int numexch = 0;
int numcomps_merge = 0;
int numcopies = 0;
int numcompsquick = 0;
int numexchquick = 0;

void ShellSort(vector <int> &num) {
	
	int ncomps = 0; //
	int nexch = 0;
	int i = 1;
	int temp = 1;
	int flag = 1;
	int numLength = num.size();
	int gap = numLength;
	bool insertionNeeded = false;
	int swapPos = 0;
	int key;

	while (true) {    // boolean flag (true when not equal to 0) 
		gap = (gap - 1) / 2;
		if (gap == 0)
			break;

		for (int k = 0; k < gap; k++) {
			for (int j = gap + k; j < numLength; j += gap) {
				key = num[j];

				insertionNeeded = false;
				for (i = j - gap; i >= 0; i -= gap) {   // Smaller values move right
					ncomps++;
					if (key < num[i]) {
						
						
						swapPos = i;
						num[i + gap] = num[i];
						nexch++;
						
					
						insertionNeeded = true;
					}
					else
						break;
				}
				if (insertionNeeded) {
					num[swapPos] = key;    //Put key into its proper location
				}
			}
		}
	}
	cout << "Shell Sort: Number of comparisons " << ncomps << endl;
	cout << "Shell Sort: Number of shifts " << nexch << endl;
	return;
}


void selection_sort(vector<int>& vec) {
	int ncomps = 0;
	int nexch = 0;
	for (int fill = 0; fill != vec.size(); ++fill) {
		int pos_min = fill;
		for (int next = fill + 1; next != vec.size(); ++next) {
			ncomps++; /////////////////////////////////////////////
			if (vec[next] < vec[pos_min])
				
				pos_min = next;

		}
		if (fill != pos_min)
		{
			nexch++;
			swap(vec[pos_min], vec[fill]);
		}

	}
	cout << "Selections sort: Number of comparisons " << ncomps << endl;
	cout << "Selection sort: Number of exchanges " << nexch << endl;
}


void BubbleSort(vector <int> &num) {
	int ncomps = 0;
	int nexch = 0;
	int nsize = num.size();
	for (int i = 1; i <= nsize; i++) {
		for (int j = 0; j < nsize - i; j++) {
			if (num[j + 1] < num[j])
			{
				ncomps++;
				swap(num[j], num[j + 1]);// swap elements
			}
		}
	}
}

void bubble_sort_improved(vector <int> &vec) {
	int ncomps = 0;
	int nexch = 0;
	bool exchanges = false;
	int vsize = vec.size();
	for (int i = 1; i <= vsize; i++) {
		exchanges = false;
		for (int j = 0; j < vsize - i; j++) {
			ncomps++; //////////////////////////////////////////////////////
			if (vec[j + 1] < vec[j]) {
				
				swap(vec[j], vec[j + 1]);// swap elements
				nexch++; ///////////////////////////////
				exchanges = true;
			}
		}
		if (!exchanges)
			break;
	}
	cout << "Bubble Sort Improved: Number of comparisons " << ncomps << endl;
	cout << "Bubble sort Improved: Number of exchanges " << nexch << endl;
}

void bubble_sort_list(list<int> &li) {
	bool exchanges = false;
	list<int>::iterator itr = li.begin();
	int lsize = li.size();
	for (int i = 1; i <= lsize; i++) {
		exchanges = false;
		itr = li.begin();
		for (int j = 0; j <lsize - i; j++) {
			list<int>::iterator current = itr;
			if (*(++itr)< *current) {
				swap(*current, *itr);// swap elements
				exchanges = true;
			}
		}
		if (!exchanges)
			break;
	}
}

void insertion_sort(std::vector <int> &num) {
	int ncomps = 0;
	int nexch = 0;
	int i, j, key;
	bool insertionNeeded = false;
	int nsize = num.size();
	for (j = 1; j < nsize; j++) {
		key = num[j];
		insertionNeeded = false;
		for (i = j - 1; i >= 0; i--) { // larger values move right
			ncomps++;///////////////////////////////////////////////////////////////
			if (key < num[i]) {
				
				num[i + 1] = num[i];
				nexch++; /////////////////////////////////////////////////////////
				insertionNeeded = true;
			}
			else
				break;
		}
		if (insertionNeeded)
			num[i + 1] = key;    //Put key into its proper location
	}
	cout << "Insertion sort: Number of comparisons " << ncomps << endl;
	cout << "Insertion sort: Number of shifts " << nexch << endl;
}


void merge(std::vector<int>& array, std::vector<int>& result, int lowPointer, int highPointer, int upperBound) {
	numcopies++;
	int j = 0;
	int lowerBound = lowPointer;
	int mid = highPointer - 1;
	int n = upperBound - lowerBound + 1; //number of items

	while (lowPointer <= mid && highPointer <= upperBound) {
		numcomps_merge++;
		if (array[lowPointer] < array[highPointer])
		{
			
			result[j++] = array[lowPointer++];
		}
		else
			result[j++] = array[highPointer++];
	}

	while (lowPointer <= mid) {
		//numcomps_merge++;
		result[j++] = array[lowPointer++];
	}


	while (highPointer <= upperBound)
	{
		//numcomps_merge++;
		result[j++] = array[highPointer++];
	}


	for (j = 0; j < n; j++) //copy the items from the temporary array to the original array
	{
		array[lowerBound + j] = result[j];
		
	}
	
}

void mergesort(std::vector<int>& array, std::vector<int>& result, int lowerBand, int upperBand) {
	numcopies++;
	int midpoint;
	if (lowerBand < upperBand) {
		
		midpoint = (lowerBand + upperBand) / 2;
		mergesort(array, result, lowerBand, midpoint); //merge sort the left half
		mergesort(array, result, midpoint + 1, upperBand); //merge sort the right half
		merge(array, result, lowerBand, midpoint + 1, upperBand);
	}
	
}

void mergeSort(std::vector<int>& array) {
	numcopies = 0;
	std::vector<int> result = array;
	mergesort(array, result, 0, array.size() - 1);
	cout << "Merge sort: Number of comparisons " << numcomps_merge << endl;
	cout << "Merge sort: Number of copies " << numcopies << endl;
}



int partition(int first, int last, std::vector<int>& arr) {
	// Start up and down at either end of the sequence.
	// The first table element is the pivot value.
	int up = first + 1;
	int down = last - 1;
	do {

		while ((up != last) && !(arr[first] < arr[up])) {
			++up;
		}
		while (arr[first] < arr[down]) {
			--down;
		}
		if (up < down) {
			numcompsquick++;
			// if up is to the left of down,
			swap(arr[up], arr[down]);
		}
	} while (up < down); // Repeat while up is left of down.

	swap(arr[down], arr[first]);
	numexchquick++;
	return down;
	
}

void sort_median(std::vector<int>& arr, int first, int last) {

	bool exchanges = true;
	int middle = (first + last) / 2;
	if (arr[first]>arr[middle])
		swap(arr[first], arr[middle]);
	if (arr[middle] > arr[last])
		swap(arr[middle], arr[last]);
	if (arr[first] > arr[middle])
		swap(arr[first], arr[middle]);


	//swap the middle with the left 
	swap(arr[middle], arr[first]);
}

int partitionB(int first, int last, std::vector<int>& arr) {
	// Start up and down at either end of the sequence.
	// The first table element is the pivot value.


	int up = first + 1;
	int down = last - 1;
	sort_median(arr, first, last - 1);
	int mid = first;
	do {
		while ((up != last - 1) && !(arr[mid] < arr[up])) {
			++up;
		}
		while (arr[mid] < arr[down]) {
			--down;
		}
		if (up < down) {
			numcomps++;
			// if up is to the left of down,
			swap(arr[up], arr[down]);
		}
	} while (up < down); // Repeat while up is left of down.

	swap(arr[mid], arr[down]);
	numexch++;
	
	return down;
	
}

void middle_quick_sort(int first, int last, std::vector<int>& arr) {
	
	if (last - first > 1) {
		// There is data to be sorted.
		// Partition the table.
		int pivot = partitionB(first, last, arr);

		// Sort the left half.
		middle_quick_sort(first, pivot, arr);

		// Sort the right half.
		middle_quick_sort(pivot + 1, last, arr);
	}
}

void middle_quick_sort_wrapper(vector<int>& arr) {
	middle_quick_sort(0, arr.size(), arr);
	cout << "Quick sort improved: Number of comparisons " << numcomps << endl;
	cout << "Quick sort improved: Number of exchanges " << numexch << endl;
	
}

void quick_sort(int first, int last, std::vector<int>& arr) {

	if (last - first > 1) {
		// There is data to be sorted.
		// Partition the table.
		int pivot = partition(first, last, arr);

		// Sort the left subarray.
		quick_sort(first, pivot, arr);

		// Sort the right subarray.
		quick_sort(pivot + 1, last, arr);
	}
}
	

void quick_sort_wrapper(vector<int>& arr) {
	quick_sort(0, arr.size(), arr);
	cout << "Quick sort: Number of comparisons " << numcompsquick << endl;
	cout << "Quick sort: Number of exchanges " << numexchquick << endl;

}


vector<int> random_vector(size_t size) {
	vector<int> v1;
	int rsize = size;
	for (int i = 0; i < rsize; i++)
		v1.push_back(rand() % rsize); //put a random number between 0 and size
	return v1;
}

vector<int> sorted_vector(size_t size) {
	vector<int> v1;
	int rsize = size;
	for (int i = 0; i < rsize; i++)
		v1.push_back(i);
	return v1;
}

vector<int> reversed_vector(size_t size) {
	vector<int> v1;
	for (int i = size - 1; i >= 0; i--)
		v1.push_back(i);
	return v1;
}

int main() {

	cout << "-------------------Random vector-------------------" << endl;
	vector<int> v1 = random_vector(10000);
	bubble_sort_improved(v1);

	v1 = random_vector(10000);
	selection_sort(v1);

	v1 = random_vector(10000);
	insertion_sort(v1);

	v1 = random_vector(10000);
	ShellSort(v1);

	v1 = random_vector(10000);
	mergeSort(v1);

	v1 = random_vector(10000);
	quick_sort_wrapper(v1);

	v1 = random_vector(10000);
	middle_quick_sort_wrapper(v1);

	cout << "-------------------Sorted vector-------------------" << endl;

	vector<int> v2 = sorted_vector(10000);
	bubble_sort_improved(v2);

	v2 = sorted_vector(10000);
	selection_sort(v2);

	v2 = sorted_vector(10000);
	insertion_sort(v2);

	v2 = sorted_vector(10000);
	ShellSort(v2);

	v2 = sorted_vector(10000);
	mergeSort(v2);

	/*v2 = sorted_vector(10000);
	quick_sort_wrapper(v2);*/

	v2 = sorted_vector(10000);
	middle_quick_sort_wrapper(v2);

	cout << "-------------------Reversed vector-------------------" << endl;

	vector<int> v3 = reversed_vector(10000);
	bubble_sort_improved(v3);

	v3 = reversed_vector(10000);
	selection_sort(v3);
		
	v3 = reversed_vector(10000);
	insertion_sort(v3);
		
	v3 = reversed_vector(10000);
    ShellSort(v3);
		
	v3 = reversed_vector(10000);
	mergeSort(v3);

	/*v3 = reversed_vector(10000);
	quick_sort_wrapper(v3);*/

	v3 = reversed_vector(10000);
	middle_quick_sort_wrapper(v3);

	system("pause");

	return 0;
}
#pragma once
#include <iostream>
#include <ctime>
#include <vector>
#include <deque>
#include <set>
#include <stdexcept>
#include <sstream>
#include <cstdlib>

template <typename T>
void printContainer(const T &c);
template <typename T>
// void insertionSort(typename T::iterator iter1, typename T::iterator iter2);
void    insertionSort(T begin, T end);

class PMergeMe
{
    public:
        PMergeMe();
        PMergeMe(const PMergeMe &copy);
        PMergeMe& operator=(const PMergeMe &other);
        ~PMergeMe();
    
        template <typename Merge>
        void mergeSort(Merge arr[], int len);
        void time();

        void fillArgs(int ac, char **av);
        bool isDigit(int ac, char **av);
    private:
        std::vector<int> _vector;
        std::deque<int> _deque;
        int _size;
        int _isSorted;
        bool isDuplicate();

        template <typename Container>
        bool isSorted(const Container &container);
};

template<typename T>
void insertionSort(T begin, T end)
{
	T iter1;
    T iter2;
    int temp;

	for (iter1 = begin + 1; iter1 <= end; ++iter1)
	{
		temp = *iter1;
		iter2 = iter1;
		while (iter2 > begin && temp < *(iter2 - 1))
		{
			*iter2 = *(iter2 - 1);
			--iter2;
		}
		*iter2 = temp;
    }
}

template <typename Container>
bool PMergeMe::isSorted(const Container &container) {
    if (container.empty()) {
        return true;  
    }

    typename Container::const_iterator prev = container.begin();
    typename Container::const_iterator cur = prev;
    ++cur;

    while (cur != container.end()) {
        if (*prev > *cur) {
            return false;
        }
        ++prev;
        ++cur;
    }
    return true;
}

template <typename Merge>
void mergeSort(Merge& arr, int left, int mid, int right)
{
	int n1 = mid - left + 1;
	int n2 = right - mid;
	Merge	L(n1);
	Merge	R(n2);
	
	for (int i = 0; i < n1; ++i)
		L[i] = arr[left + i];
	
	for (int j = 0; j < n2; ++j)
		R[j] = arr[mid + j + 1];
	
	int i = 0;
    int j = 0;
    int k = left;
	
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
			arr[k++] = L[i++];
		else
			arr[k++] = R[j++];
	}
	
	while (i < n1)
		arr[k++] = L[i++];
	
	while (j < n2)
		arr[k++] = R[j++];
}

template <typename T>
void	mergeInsertionSort(T& arr, int left, int right)
{
	if (right - left <= 4)
		insertionSort(arr.begin() + left, arr.begin() + right);
	else
	{
		int mid = left + (right - left) / 2;
		mergeInsertionSort(arr, left, mid);
		mergeInsertionSort(arr, mid + 1, right);
		mergeSort(arr, left, mid, right);
	}
}

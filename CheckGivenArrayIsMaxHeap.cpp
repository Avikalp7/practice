/*
* Source : http://www.geeksforgeeks.org/how-to-check-if-a-given-array-represents-a-binary-heap/
* PS : Given an array, how to check if the given array represents a Binary Max-Heap.
*/

#include <iostream>
#include <cstdio>

using namespace std;

template <typename T>
bool is_maxHeap(T A[], int n)
{
    int l, r;
    for(int i = 0; i < n/2 - 1; i++)
    {
        l = 2*i + 1;
        r = l + 1;
        if(A[l] > A[i] || A[r] > A[i])
            return false;
    }
        return true;
}

int main()
{
    int arr[] = {90, 15, 10, 7, 12, 2, 7, 3};
    int n = sizeof(arr) / sizeof(int);

    is_maxHeap(arr, n)? printf("Yes"): printf("No");

    return 0;
}

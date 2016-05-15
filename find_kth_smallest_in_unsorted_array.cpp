/*
* Source : http://www.geeksforgeeks.org/kth-smallestlargest-element-unsorted-array/
* PS : Given an array and a number k where k is smaller than size of array, we need to find the k’th smallest element in the given array.
* It is given that all array elements are distinct.
*/

#include <iostream>
#include <cstdlib>

using namespace std;

template <typename T>
void swap_(T &x, T &y)
{
    T tmp = x;
    x = y;
    y = tmp;
}

template <typename T>
int random_partition(T arr[], int l, int r)
{
    int q = l + rand()%(r - l + 1);
    swap_(arr[q], arr[r]);
    T key = arr[r];
    int i = l - 1;
    for(int j = l; j < r; j++)
    {
        if(arr[j] < key)
        {
            i++;
            swap_(arr[i],arr[j]);
        }
    }
    swap_(arr[i + 1], arr[r]);
    return i + 1;
}

template <typename T>
T find_kth_smallest_element(T arr[], int k, int n)
{
    int q = -1, l = 0, r = n-1;

    while(1)
    {
        q = random_partition(arr, l, r);
        if(q == k-1)
            return arr[k-1];
        if(q > k-1)
            r = q - 1;
        else
            l = q + 1;
    }
}

int main()
{
    int arr[] = {12, 3, 5, 7, 19};
    int n = sizeof(arr)/sizeof(arr[0]), k = 2;
    for(int i = 0; i<n; i++) cout << arr[i] << " ";
    cout << endl;
    while(1){
            cin >> k;
    cout << "\nK'th smallest element is " << find_kth_smallest_element(arr, k, n) << endl;}
    return 0;
}

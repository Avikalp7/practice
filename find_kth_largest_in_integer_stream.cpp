#include <iostream>
#include <cstdio>

using namespace std;

template <typename T>
void swap_(T &x, T &y)
{
    T tmp = x;
    x = y;
    y = tmp;
}


template <typename T>
void min_heapify(T arr[], int n, int i)
{
    int l = (i << 1) + 1;
    int r = l + 1;
    int smallest = i;
    if(l < n && arr[l] < arr[smallest])
        smallest = l;
    if(r < n && arr[r] < arr[smallest])
        smallest = r;
    if(smallest != i)
    {
        swap_(arr[i], arr[smallest]);
        min_heapify(arr, n, smallest);
    }
}

template <typename T>
void build_heap(T arr[], int n)
{
    for(int i = n/2 -1; i >= 0; i--)
    {
        min_heapify(arr, n, i);
    }
}

template <typename T>
void kth_largest(int k)
{
    int counter = 0;
    T x;
    T* arr = new T[k];

    while(1)
    {
        cout << "Enter x : ";
        cin >> x;
        if(counter < k - 1)
        {
            arr[counter] = x;
            counter++;
        }
        else
        {
            if(counter == k - 1)
            {
                arr[counter] = x;
                build_heap(arr, k);
            }
            else if(x > arr[0])
            {
                arr[0] = x;
                min_heapify(arr, k, 0);
            }
            cout << "   Kth largest : " << arr[0] << endl;
            counter++;
        }

//        if(counter >= k)
//            cout << "   Kth largest : " << arr[0] << endl;

    }

    delete[] arr;
}


int main()
{
//    int arr[] = {2,6,12,3,4,66,43,21};
//    int n = sizeof(arr)/sizeof(int);
    kth_largest<int>(3);
    return 0;
}

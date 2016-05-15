#include <iostream>

using namespace std;

template <typename T>
void printArray(T arr[], int size);

template <typename T>
void swap_(T& x, T& y)
{
    T tmp = x;
    x = y;
    y = tmp;
}

template <typename T>
class Minheap
{
    T* harr;
    int hsize;

public:

    Minheap(T arr[], int n);

    void min_heapify(int i);

    T extract_min();

    T replace_min(T key);

    int left(int i){ return 2*i + 1;}
    int right(int i){ return 2*i + 2;}
};


template <typename T>
Minheap<T>::Minheap(T arr[], int n)
{
    harr = arr;
    hsize = n;
    for(int i = n/2 - 1; i >= 0; i--)
    {
        min_heapify(i);
    }
}

template <typename T>
void Minheap<T> :: min_heapify(int i)
{
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if(l < hsize && harr[l] < harr[smallest])
    {
        smallest = l;
    }
    if(r < hsize && harr[r] < harr[smallest])
    {
        smallest = r;
    }
    if(smallest != i)
    {
        swap_(harr[i], harr[smallest]);
        min_heapify(smallest);
    }
}

template <typename T>
T Minheap<T> :: extract_min()
{
    T min = harr[0];
    harr[0] = harr[hsize - 1];
    hsize--;
    min_heapify(0);
    return min;
}

template <typename T>
T Minheap<T> :: replace_min(T key)
{
    T min = harr[0];
    harr[0] = key;
    min_heapify(0);
    return min;
}

template <typename T>
void sort_k (T arr[], int n, int k)
{
    T* harr = new int[k+1];
    for(int i = 0; i < k + 1; i++)
        harr[i] = arr[i];
    Minheap<T> my_heap = Minheap<T>(harr, k+1);
    int cidx = k + 1;
    for(int i = 0; i < n; i++)
    {
        if(cidx < n)
        {
            arr[i] = my_heap.replace_min(arr[cidx]);
            cidx++;
        }
        else
        {
            arr[i] = my_heap.extract_min();
        }
    }
}

template <typename T>
void printArray(T arr[], int size)
{
   for (int i=0; i < size; i++)
       cout << arr[i] << " ";
   cout << endl;
}

// Driver program to test above functions
int main()
{
    int k = 3;
    int arr[] = {2, 6, 3, 12, 56, 8};
    int n = sizeof(arr)/sizeof(arr[0]);
    sort_k(arr, n, k);

    cout << "Following is sorted array\n";
    printArray (arr, n);

    return 0;
}

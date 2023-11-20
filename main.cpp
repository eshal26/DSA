#include <iostream>
#include <chrono>
#include <random>
using namespace std;
using namespace std::chrono;

void bubbleSort(int array[], int size)
{
    for(int i = 0; i<size-1; i++)
    {
        for(int j = 0; j< size-1-i; j++)
        {
            if (array[j+1] < array[j])
            {
                int tmp;
                tmp = array[j];
                array[j] = array[j+1];
                array[j+1] = tmp;
            }
        }

    }

}

void insertionSort(int array[],int size)
{
    for(int p = 1; p<size; p++)
    {
        int tmp = array[p];
        int j;
        for(j = p; j>0 && tmp<array[j-1]; j--)
        {
            array[j] = array[j-1];
        }
        array[j] = tmp;
    }

}

void merge(int A[], int p, int q, int r)
{
    int k = p;
    int i = 0;
    int l = q-1;
    int T[r+1];
    while(p<=l && q<=r)
    {
        if(A[p] <= A[q])
        {
            T[i] = A[p];
            i++;
            p++;
        }
        else
        {
            T[i] = A[q];
            i++;
            q++;
        }
    }
    while(p<=l)
    {
        T[i] = A[p];
        i++;
        p++;
    }
    while(q<=r)
    {
        T[i] = A[q];
        i++;
        q++;
    }
    for(int i=k; i<=r; i++)
    {
        A[i] = T[i-k];
    }
}

void mergeSort(int arr[],int left, int right)
{
    if(left<right)
    {
        int center = (left + right) /2;
        mergeSort(arr,left,center);
        mergeSort(arr,center+1,right);
        merge(arr,left,center+1,right);
    }
}

void swap(int A[], int i, int j)
{
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

int partition(int A[],int left, int right)
{
    int pivot = A[right];
    int i = left - 1;
    int temp;
    for(int j = left; j<right; j++)
    {
        if(A[j]<pivot)
        {
            i++;
            swap(A,i,j);
        }
    }
    swap(A,i+1,right);
    return i+1;
}

void quickSort(int A[], int left, int right)
{
    if(left < right)
    {
        int pivot = partition(A, left, right);
        quickSort(A, left, pivot-1);
        quickSort(A, pivot+1, right);
    }
}

void print(auto t1, auto t2)
{
    auto ms_int = duration_cast<milliseconds>(t2-t1);
    duration<double, std::milli> ms_double = t2-t1;
    cout << ms_int.count() << "ms\n";
    cout << ms_double.count() << "ms" << endl;
}

int main()
{
    using chrono::duration;
    using chrono::duration_cast;
    using chrono::high_resolution_clock;
    using chrono::milliseconds;
    int size = 20000;
    cout << "\nInput size : " << size;
    //Generate random values
    int arr[size], arr1[size], arr2[size], arr3[size];
    for(int i = 0; i<size; i++)
    {
        arr[i] = (rand() % 100)+1;
    }
    //Copying array
    for (int i=0; i<size; i++)
    {
        arr1[i] = arr[i];
        arr2[i] = arr[i];
        arr3[i] = arr[i];

    }
    cout << endl;
    //Bubble Sort
    auto t1 = high_resolution_clock::now();
    bubbleSort(arr,size);
    auto t2 = high_resolution_clock::now();
    cout << "\nBubble Sort : " << endl;
    print(t1,t2);
    //Insertion Sort
    auto t3 = high_resolution_clock::now();
    insertionSort(arr1,size);
    auto t4 = high_resolution_clock::now();
    cout << "\nInsertion Sort : " << endl;
    print(t3,t4);
    //Merge Sort
    auto t5 = high_resolution_clock::now();
    mergeSort(arr2,0,size-1);
    auto t6 = high_resolution_clock::now();
    cout << "\nMerge Sort : " << endl;
    print(t5,t6);
    //Quick Sort
    auto t7 = high_resolution_clock::now();
    quickSort(arr3,0,size-1);
    auto t8 = high_resolution_clock::now();
    cout << "\nQuick Sort : "<<endl;
    print(t7,t8);
    return 0;
}

#include<iostream>
#include<cstdlib>
#include<climits>
using namespace std;
void swap(int *a,int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
int partition(int arr[],int low,int high)
{
    int min = INT_MAX;
    int pivot = arr[high];
    int i = low -1;
    for(int j = low; j < high; j++) {
        if(arr[j] <= pivot) {
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i+1],&arr[high]);
    return (i+1);
}
void quicksort(int arr[],int low,int high)
{
    if( low < high) {
        int pivot = partition(arr,low,high);
        quicksort(arr,low,pivot-1);
        quicksort(arr,pivot+1,high);
    }
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin >> arr[i];

    quicksort(arr,0,n-1);
    int rs = INT_MAX;
    for(int i=0;i<n-1;i++) {
        if( (arr[i+1] - arr[i]) < rs )
            rs = arr[i+1] - arr[i];
    }
    cout<<rs<<" ";
//    for(int i=0; i<n;i++)
//        cout<<arr[i] <<" ";
}

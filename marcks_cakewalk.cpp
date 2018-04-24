#include<iostream>
#include<climits>
#include<cmath>
using namespace std;
void swap(int *a,int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
int partition(int arr[],int low,int high)
{
    int min =INT_MAX;
    int piv = arr[high];
    int i = low-1;
    for(int j = low; j< high; j++) {
        if( arr[j] >= piv) {
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i+1],&arr[high]);
    return (i+1);
}
void quicksort(int arr[],int low,int high)
{
    if(low < high) {
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
        cin>> arr[i];
    quicksort(arr,0,n-1);

    int rs=0;
    for(int i=0;i<n;i++) {
 //       cout<<rs<<" ";
        rs = rs + pow(2,i)*arr[i];

    }
    cout<<rs;
    return 0;

}

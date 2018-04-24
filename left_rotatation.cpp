#include<iostream>
using namespace std;

int gcd(int a,int b)
{
    if( b==0 )
        return a;
    return gcd(b,a%b);
}
void rotate(int arr[],int n,int d)
{
    int tmp;
    int j,k;

    for(int i=0;i<gcd(n,d);i++) {
        tmp = arr[i];
        j = i;
        while(1) {
             k = j+d;
            if(k>=n)
                k = k-n;
            if(k==i)
                break;
            arr[j] =arr[k];
            j=k;
        }

        arr[j]=tmp;
    }


}
int main()
{
    int n,d;
    cin>>n>>d;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    rotate(arr,n,d);
    for(int i=0;i<n;i++)
        cout<<arr[i] <<" ";

    return 0;
}

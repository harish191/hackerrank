#include<iostream>
using namespace std;
void func(int n,int sp)
{
    if(n == 0)
        return;
    func(n-1,sp+1);
    for(int i=0;i<sp;i++)
        cout<<" ";
    for(int i=0;i<n;i++)
        cout<<"#";
    cout<<endl;
}
int main()
{
    int n;
    cin >> n;

    func(n,0);
    return 0;
}

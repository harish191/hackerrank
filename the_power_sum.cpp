#include<iostream>
using namespace std;

int power(int x,unsigned n)
{
    if( n == 0)
        return 1;
    else if( n%2 == 0)
        return (power(x,n/2) * power(x,n/2) );
    else
        return x*power(x,n/2)*power(x,n/2);
}

int powersum(int x,int n,int curr_num,int curr_sum)
{
    int res =0;
    int p = power(curr_num,n);

    while( (p + curr_sum) < x ) {

        res += powersum(x,n,curr_num +1, curr_sum +p);

        curr_num++;
        p = power(curr_num,n);
    }

    if( p+curr_sum == x)
        res++;

    return res;
}
int main()
{
    int x,n;
    cin >> x >> n;

    int ot =powersum(x,n,1,0);
    cout<<ot;
    return 0;

}

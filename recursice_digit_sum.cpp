#include<iostream>
using namespace std;

int cal(string st,int k)
{
    k = k%9;
    if(k == 0 )
        return 9;
    int sum =0;
    for(int i=0; i < st.size(); i++) {

        sum = (sum + st[i] - '0')%9;
    }

    if(  ((sum%9)*k)%9 == 0  )
        return 9;

    else
        return ((sum%9)*k)%9;

}
int main()
{
    string n;
    int k,tmp;
    long long int rs=0;
    cin >> n >> k;

    tmp = cal(n,k);


//    rs = cal(tmp*k);
    cout<<tmp;
 //   cout<<getsum(n);
    return 0;

}

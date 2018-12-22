#include<iostream>
using namespace std;

bool isPowerOfTwo(int n)
    {
        if(n==1)
            return true;
        while(n!=1)
        {
            if(n%2!=0)
                return false;
            n=n/2;
        }
        return true;
    }

int main()
{
	int n;
	cin>>n;
	bool res=isPowerOfTwo(n);
	if(res==true)
		cout<<"yes";
	else
		cout<<"no";

}

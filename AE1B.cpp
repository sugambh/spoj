#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
void printboxes(int *x, int size)
{
	for(int i=0;i<size;i++)
	{
		cout<<x[i];
	}
	cout<<endl;
}

int main()
{
int n=0,k=0,s=0;
cin>>n;
cin>>k;
cin>>s;
vector<int> vbox;
int i=0;
while(i<n)
{
	int temp;
	cin>>temp;
	vbox.push_back(temp);
	i++;
}

sort(vbox.begin(),vbox.begin()+n);
int num=0;
int sum=0;
for(i=n-1;i>=0;i--)
{
	if(sum<k*s)
	{
		sum=sum+vbox[i];
		num++;
	}
	else
	break;
}
cout<<num;
return 0;
}

/* Big Int Library*/
// Author: sugamanandymc1@gmail.com



#include <iostream>
#include <cstdio>
#include <cstring>
#define MAX 102
using namespace std;
void printnum(char* result)
{
	int i=strlen(result)-1;
	while(i>=0)
	{
		cout<<result[i];
		i--;
	}	
	cout<<endl;
}
void divide_print(char* result)
{
	cout<<result<<endl;// divide operation with two results in string same format
}
/* function for adding two positive numbers*/
void add_bignum(char* t,char* d,char* result)
{	
	
	int tlen=strlen(t);
	int dlen=strlen(d);
	int i=tlen-1,j=dlen-1;	
	int val=0;
	int carry_over=0;
	int k=0;
	while(i>=0 || j>=0)
	{
		int a=0;
		int b=0;
		if(i>=0)
			a=t[i]-'0';
		else
			a=0;
		if(j>=0)
			b=d[j]-'0';
		else
			b=0;
		val=(a+b+carry_over)%10;
		carry_over=(a+b+carry_over)/10;
		result[k]=val+'0';
		k++;
		i--;
		j--;
	}
	
	if(carry_over)
	{
		result[k]=carry_over+'0';
		k++;
		result[k]='\0';
	}
	else
		result[k]='\0';
}

/*function for subtracting big numbers*/
/* todo: support for negative answers currently expects large number first*/
void sub_bignum(char*l , char* s, char* result)
{
	
	int llen=strlen(l);
	int slen=strlen(s);
	int i=llen-1,j=slen-1;	
	int val=0;
	int carry_over=0;
	int k=0;
	while(i>=0 || j>=0)
	{
		int a=0;
		int b=0;
		if(i>=0)
			a=l[i]-'0';
		else
			a=0;
		if(j>=0)
			b=s[j]-'0';
		else
			b=0;

		if(a+carry_over<b)
		{
			val=10+a+carry_over-b;
			carry_over=-1;
		}
		else
		{
			val=a+carry_over-b;
			carry_over=0;
		}



		result[k]=val+'0';
		k++;
		i--;
		j--;	
	}
	
	
	result[k]='\0';

}

/* function for performing division*/
void divide_bignum(char* denominator, char* numerator, char* result)
{
	int dlen=strlen(denominator);
	int i=0;
	int val=0;
	int carry_over=0;
	while(i<dlen)
	{
		val=(carry_over*10+(denominator[i]-'0'))/2;
		carry_over=(carry_over*10+(denominator[i]-'0'))%2;
		result[i]=val+'0';
		i++;
	}
	result[i]='\0';
}
void reverse(char* number,char* reverse)
{
	int len=strlen(number);
	int i=len-1;
	while(i>=0)
	{
	reverse[len-i-1]=number[i];
	i--;
	}
	reverse[len]='\0';
}

int main()
{
for(int i=1;i<=10;i++)
{
	char total[MAX];	
	char diff[MAX];
	char numerator[]={'2','\0'};
	scanf("%s",total);
	scanf("%s",diff);
	/* code for julka */
	char r1[MAX];
	char m1[MAX];
	char l1[MAX];
	add_bignum(total,diff,r1);
	reverse(r1,m1);
	divide_bignum(m1,numerator,l1);
		
	char r2[MAX];
	char m2[MAX];
	char l2[MAX];
	sub_bignum(total,diff,r2);
	reverse(r2,m2);
	divide_bignum(m2,numerator,l2);
	bool flag=0;
	for(int i=0;i<strlen(l1);i++)
	{
		if(l1[i]!='0')
		{
		flag=1;
		}
		if(flag)
		cout<<l1[i];
	}
	cout<<endl;
	flag=0;
	for(int i=0;i<strlen(l2);i++)
	{
		if(l2[i]!='0')
		{
		flag=1;
		}
		if(flag)
		cout<<l2[i];
	}
	
	cout<<endl;

	//cout<<l1<<endl<<l2<<endl;	
}
return 0;
}

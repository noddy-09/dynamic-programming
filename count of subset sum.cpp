//problem statement:we are given an array and an integer sum we need to find out how many subset exist which has sum equal to the given sum.

#include<bits/stdc++.h>
using namespace std;

int count_of_subset_sum(int arr[],int n,int sum)
{
	int t[n+1][sum+1];
	for(int i=1;i<=sum;i++)
		t[0][i]=0;
	for(int i=0;i<=n;i++)
		t[i][0]=1;
	for(int i=1;i<n+1;i++)
	{
		for(int j=1;j<sum+1;j++)
		{
			if(arr[i-1]<=j)
				t[i][j]=t[i-1][j-arr[i-1]]+t[i-1][j];
			if(arr[i-1]>j)
				t[i][j]=t[i-1][j];
				
		}
	}
	return t[n][sum];
}
int main()
{
	int n;
	cout<<"enter no. of elements you want to create array"<<"\n";
	cin>>n;
	int a[n];
	cout<<"enter elements of array"<<"\n";
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int sum;
	cout<<"enter sum required"<<"\n";
	cin>>sum;
	int ans=count_of_subset_sum(a,n,sum);
	cout<<"no. of subset with given sum"<<" "<<ans<<"\n";
	return 0;
}

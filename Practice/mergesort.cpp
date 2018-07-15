#include<iostream>
#include<vector>
#include<limits>
using namespace std;
void merge(vector<int> arr, int start, int mid, int end)
{
	vector<int> left(mid+2,0);
	vector<int> right(end-mid+1,0);
	left[mid+1] = numeric_limits<int>::max();
	right[end-mid] = numeric_limits<int>::max();
	for(int i=0;i<left.size();i++,start++)
	{
		left[i] = arr[start];
	}
	for(int i=0;i<right.size();i++,mid++)
	{
		right[i] = arr[mid+1];		
	}
	int i=0, j=0;
	for(int k=start;k<=end;k++)
	{
		if(left[i] <= right[j])
		{
			arr[k] = left[i];
			i++;
		}
		else
		{
			arr[k] = right[j];
			j++;
		}

	}

}

void mergesort(vector<int> arr, int start, int end)
{
	int mid = (end - start)/2;
	if(end != start)
	{
		mergesort(arr, start, mid);
		mergesort(arr, mid+1, end);
		merge(arr, start, mid, end);
	}
	
}	



int main()
{

	cout<<"Enter the length of the array : ";
	int len;
	cin>>len;
	vector<int> arr(len);
	cout<<"Enter the elements of array \n";
	for(int i=0;i<len;i++)
	{
		cin>>arr[i];
	}
	mergesort(arr,0,len-1);
	cout<<"The sorted array is \n";
	for(int i=0;i<len;i++)
	{
		cout<<arr[i]<<" ";
	}

}


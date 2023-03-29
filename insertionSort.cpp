//insertion sort using recursion
// sabse pehle index 1 vale ko index 0 se compare karege. fir index 2 vale ko index 1 se aur fir index 0 se fir index 3 vale ko indexes 2,1,0 vale se and so on till array end is reached

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1e9+7
void display(int *arr,int n)
{
for(int i=0;i<n;i++)
   cout<<arr[i]<<" " ;
   cout<<endl;
}
void insertionSort(int *arr,int n)
{
	if(n<=1)
	return;
	//pehle step mai ham index 1 ko index 0 se compare karte isliye yaha head recursion ka use karege
	insertionSort(arr,n-1);
	//pure array ko sort krne se pehle maine bola ki n-1 tak array ko sort krke do tabhi to mai last vale element ko baki ke sorted elements se compare kr paunga
	int last=arr[n-1];
	int j=n-2;
	while(j>=0&&arr[j]>last)
		{
			arr[j+1]=arr[j];
			j--;
		}//jab tak left elements base hai sab ko right shift krte jao

	arr[j+1]=last; //finally us point pr last vale element ko fit kr do jab uske left ke elements usse bade na ho


}
int main()
{
	int arr[]={4,3,6,2,9};
	int n=5;
	insertionSort(arr,n);
	display(arr,n);

}
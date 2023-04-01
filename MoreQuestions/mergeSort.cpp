//merge sort mai O(n*log(n)) time complexity hoti hai better than O(n^2) as in bubble sort, insertion sort and  selection sort , isliye prefer kiya jata hai 
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
void jodo(int *arr,int s,int mid,int e)
{
   int l1=mid-s+1; // jodo ko hamesha ek array recieve hoga jo mid se tuta hua hai , to jodo ab un dono array ko jod dega in sorted form
   int l2=e-mid;
   int *arr1=new int[l1];
   int *arr2=new int[l2];
   //starting se mid tak ki length ke size ka arr1 banaya aur mid+1 se end tak ki size ka arr2 banaya hia maine 
   for(int i=s;i<=mid;i++)// i hamesha s se start hoga na ki 0 se , iska dhyaan rkhna
   {
      arr1[i-s]=arr[i];
      // arr1 mai maine values copy ki hai abhi arr vali array ke s se mid tak
   }
   for(int i=mid+1;i<=e;i++)
   {
      //arr2 mai mid+1 se lekar e tak ki values copy hogi from array arr 
      arr2[i-mid-1]=arr[i];
   }
   //ab double pointer ke concept se ham dono array ki values ko compare akrege aur arr vale array mai dalte rahege overwriting the previous values of array arr
   int indexforarr=s;
   int indexATarr1=0,indexATarr2=0;
   while(indexATarr1<l1&&indexATarr2<l2)
   {
      if(arr1[indexATarr1]>arr2[indexATarr2])
      {
         arr[indexforarr++]=arr2[indexATarr2++];
      }
      else
      {
         arr[indexforarr++]=arr1[indexATarr1++];
      }
   }
   while(indexATarr1<l1)
   {
      arr[indexforarr++]=arr1[indexATarr1++];
   }
   while(indexATarr2<l2)
   {
      arr[indexforarr++]=arr2[indexATarr2++];
   }
}
void divide(int *arr,int s,int e)
{
   
   if(s>=e)
   return;
   int mid=s+(e-s)/2;
   divide(arr,s,mid);// pehle left block ko divide karunga
   divide(arr,mid+1,e);// fir mere right vale block divide hoge
   jodo(arr,s,mid,e);// jab ek ek block baccha hoga tab judna start hoge mere blocks in sorted version
}
void mergeSort(int *arr,int s,int e)
{// ye function kuch khass kaam ka nhi hai bas divide and jodo ki naming acchi rahe to isse banaya hun nhi to direct main function se hi ham divide function ko call kr skte the

   //mergesort ya fir divide and conquer mai ham pehle divide karege apne array elements ko jabtak ki vo single single block na ho jaye fir unko merge karege sorted way mai
   divide(arr,s,e);
}
int main()
{
   int arr[]={6,3,7,5,1};
   int s=0,e=4;
   mergeSort(arr,s,e);
   display(arr,5);
}

// step wise explanation:
/*
   step 0: main function mergesort ko call karega aur mergesort divide function ko. presently s=0, e=4
   step 1: array{6,3,7,5,1} ka left part tutega->  {6,3,7}  for the new array s=0 , e=2  
   step 2: fir {6,3,7} se {6,3} tutega and for the new array s=0, e=1
   step 3: fir {6,3} se {6} banega and for new array s=0 , e=0 thus base condition lagegi aur return hoga fir 3 tutega aur fir return karega aur fir jodo ko call lagegi fir step 2 vale ko return milega.
   step4: jodo mai  single aray {6} aur single array {3} ko sorted form mai joda jayega fir ham return kr dege jisse step 2 vali condition reach hogi.
   step 5:  as discussed above step 2 vala condition reach hua aur step mai sirf 1st past tuta tha to ab second part tutega aur  {6,3,7} se {7} banege aur yaha s aur e dono 1 yani equal ho gyi isliye return kar dega aur vapas step 2 vali condition pr ham aayege aur jodo array {3,6} and {7} ko sorted form mai jod dega
   step 6: fir step 1 vali condition reach hogi aur {5,1} tutega fir {5} tutega fir {1} tutega fir {1,5} judega fir (3,6,7) and {1,5} ko jodkar {1,3,5,6,7} vali sorted array milegi hame
*/

class Solution{
    public:
    // Function to search x in arr
    // arr: input array
    // X: element to be searched for
    int searchb(int *arr,int N,int X,int i)
    {
        if(N<=0)
        return -1;
        if(arr[0]==X)
            return i  ;
            i++;
        return searchb(arr+1,N-1,X,i);
    }
    int search(int arr[], int N, int X)
    {
        
        int i=0;
         return searchb(arr,N,X,i);
        
        
    }

};
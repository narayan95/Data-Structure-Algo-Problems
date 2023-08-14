/*
Design and Implement an algorithm for computing Greatest Common divisor (GCD) of 2 numbers, 
say m and n, using the following approaches. 
i. Middle school procedure
ii. Euclid’s Algorithm by Division
iii. Euclid’s Algorithm by Subtraction
Compute the Time Complexity for each and Display the GCD (m, n) where m>n.
*/
 /*
    Algorithm:

    -> Middle School Algorithm:
    1) Find the prime factorisation of m
    2) Find the prime factorisation of n
    3) Find all the common prime factors
    4) Compute the product of all the common prime factors and return its gcd(m,n)

    -> Euclid's algorithm by division
    1) Divide larger number by smaller until remainder comes 0. If remainder is zero the divisor will be the gcd
    2) After each division modify dividend as the divisor and remainder as the divisor.

    -> Euclid's algorithm by Subtraction
        Until both numbers are equal, keep dividing the smaller number from the larger number.
    */


#include<bits/stdc++.h>
using namespace std;
void Middle_School(int m,int n)
{
   
   /* Method 1 : O(N) Space Complexity

      vector<int>factors_m, factors_n;
   for(int i=2;i<=m/2;i++)
   {
    while(m%i==0)
    {
        factors_m.push_back(i);
        i++;
    }
   }
   for(int i=2;i<=n/2;i++)
   {
    while(n%i==0)
    {
        factors_n.push_back(i);
        i++;
    }
   }
    int prod=1;
    int i=0,j=0;
    while(i<factors_m.size()&& j<factors_n.size())
    {
        if(factors_m[i]== factors_n[j])
        {
            prod*= factors_m[i];
            i++;
            j++;
        }
        else if(factors_m[i]>factors_n[j])
        {
            j++;
        }
        else
        i++;
    }
    cout<<"Gcd of "<<m <<" and "<<n<<" = "<<prod<<endl;
    */
   /*Method 2 : O(1) Space Complexity   */
   int ans=1;
   for(int i=2;i<=m&&i<=n;i++)
   {
    if(m%i==0&&n%i==0)
    {
        ans=i;
    }
   }
   cout<<"Gcd of "<<m <<" and "<<n<<" = "<< ans <<endl;

}
int Euclid_division(int m,int n)
{
    if(n==0)
    {
        return m;
    }
    return Euclid_division(n,m%n);

}
int Euclid_subtraction(int m,int n)
{
    while(m!=n)
    {
        if(m>n)
        m=m-n;
        else
        n=n-m;
    }
    return m;
}
int main()
{
    int m,n;
    cin>>m>>n;
    if(m<n)
    swap(m,n);
    clock_t start,end;
    start=clock();
    Middle_School(m,n);
    end=clock();
    cout<< "Time Taken for Middle School Procedure= " <<(end - (float)start) /CLOCKS_PER_SEC <<" sec\n\n";
    start=clock();
    int ans= Euclid_division(m,n);
    cout<<"Gcd of "<<m <<" and "<<n<<" = "<< ans <<endl;
    end=clock();
    cout<< "Time Taken for Euclid's algorithm by division= " <<(end - (float)start) /CLOCKS_PER_SEC <<" sec\n\n";
    start=clock();
    ans=Euclid_subtraction(m,n);
    cout<<"Gcd of "<<m <<" and "<<n<<" = "<< ans <<endl;
    end=clock();
    cout<< "Time Taken for Middle School Procedure= " <<(end - (float)start) /CLOCKS_PER_SEC <<" sec\n\n";
}
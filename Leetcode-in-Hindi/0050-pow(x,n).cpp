class Solution {
public:
    double fastPow(double x, long long n)
    {
         if(n==0)
            return 1;
        if(n==1)
            return x; // x ki power 1 = x hota hai.
        double half=fastPow(x,n/2);
        if(n%2==0)
        return half*half;
        else
        return half*half*x;
    }
    double myPow(double x, int n) {
        long long N=n;
       if(n<0)
       {
           N=-N;// overflow vala case sambhal rha hun becoz int ki range -2147483648 to 2147483647 hoti hai aur agr n ki value INT_MIN hai yani  -2147483648 to direct usko positive krege -1 se multiply krke to 2147483648 ho jayega jo ki range se bahar hai
           x=1/x;
       }
       return fastPow(x,N);

        // example 1: bhul jao recursion kya hota hai.simply aise socho ki agar muzhe 2 ki power 4 ki value ko nikalna tha  to maine 2 square ki value nikali hai aur fir  2 square multiply 2 square kr diya to mera ans aa jayega. Aur agar odd value hai n to like 2 ki power 5 hai to 2 * 2 ka square * 2 ka square yani ek baar x se aur multiply krna pada

    // example 2: let 2 ki power 8 ko nikalna hai matlab x =2 and n=8 hai. To pehle hamne socha ki 8 ko half krke 2 ki power 4 ki value nikalte hai aur fir usko 2 ki power 4 se multiply ke dege. To jab 2 ki power 4 nikalne gaye to pata chala ki iski bhi value to hame pata nhi hai thus usse bhi addha krke 2 ki power 2 ki value nikalne ki koshish ki, but 2 ki power 2 ki value bhi nhi pata thi hame isliye use adha krke 2 ki power 1 ki value nikali jo ki hame pata thi. ab 2 ki power 2 ki value nikal li hamne by 2 ki power 1 * 2 ki power 1. Now ab jab 2 ki power 2 ki value aa gyi to 2 ki power 4 ki nikali and finally hamne 2 ki power 8 ki nikal kr return kr diya main code ko.
    }
};
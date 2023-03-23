/*Approach
Simply yaha ham har ek array element ko le rhe hai aur check kr rhe ki agr uski value 0 hai to agal bagal fir check kr rhe aur agar agal bagal vale elements ki bhi value zero hai to present element yani (i) jis pr abhi point kr rha usse ham 1 bana de rhe hai aur fir next element pr move krke same process kr rhe hai.
Dhyan rakhna hai sirf corner elements ka yani i=0 vale ka aur i= maxsize-1 vale ka kyunki unke bagal mai sirf ek element se hi check krna hai isliye isleftempty and is rightempty ki value nikalte vakt ek OR mai inki conditions dalni paadi.

Code
*/
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        
        for(int i=0;i<flowerbed.size();i++)
        {
            if(flowerbed[i]==0)
            {
                bool isleftempty=((i==0)||(flowerbed[i-1]==0));
                bool isrightempty=((i==flowerbed.size()-1)||(flowerbed[i+1]==0));
                if(isleftempty&&isrightempty)
                {
                    n--;
                    flowerbed[i]=1;
                }
                if(n==0)
                return true;

            }
        }
        return n<=0;
        
    }
};
/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    
    int guessNumber(int n) {
        int strt=1,end=n,mid;
        while(end-strt>1){
            mid=strt+(end-strt)/2;
            int val=guess(mid);
            if(val==-1)end=mid-1;
            else strt=mid;
        }
        if(guess(strt)==0)return strt;
        else return end;
    }
};
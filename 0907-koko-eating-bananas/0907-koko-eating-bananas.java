class Solution {
    public int minEatingSpeed(int[] piles, int h) {
        long minPile = piles[0];
        long maxPile = piles[0];
        long sum = 0;
        if(piles.length == 1){
            if(piles[0] % h != 0){
                return piles[0] / h + 1;
            }
            return piles[0] / h;
        }
        for(int pile : piles){
            sum += pile;
            maxPile = Math.max(maxPile,pile);
        }
        minPile = sum / h;
        return (int)getMinEatingSpeed(piles,minPile,maxPile,h);
    }

    private long getMinEatingSpeed(int[] piles , long left , long right , int h ){
        long mid = 0;
        while(left < right){
            mid = (left + right) / 2;
            if(canEatBananas(piles,mid,h)){
                right = mid;
            }else{
                left = mid + 1;
            }
        }
        return left;
    }

    private boolean canEatBananas(int[] piles , long k , int h){
        int hSpend = 0;
        for(int pile : piles){
            hSpend += pile / k;
            if(pile % k != 0){
                hSpend += 1;
            }
        }
        return hSpend <= h;
    }

}
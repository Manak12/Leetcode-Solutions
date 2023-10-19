class Solution {
public:
    int numberOfSubstrings(string s) {
        int left=0, right=0, count=0, n= s.size()-1 ,work=1;
        unordered_map<char, int> mpp ;
        
        for(right=0;right<n+1;right++){
            mpp[s[right]]++ ;
            
            while(mpp['a']  &&  mpp['b']  &&  mpp['c']){
                count += 1+ (n - right) ;
                
                mpp[s[left]]-- ;
                left++ ;
                cout<<right<<" ";
            }
            
            
        }
        
        return count ;
    }
};
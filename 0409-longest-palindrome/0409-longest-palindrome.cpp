class Solution {
public:
    int longestPalindrome(string s) {
        if(s.size()==1){
            return 1;
        }   
        int cnt=0;
        int arr[256]={0};
        for(int i=0;i<s.length();i++){
            arr[s[i]]++;
        }
        for(int i=0;i<256;i++){
            if(arr[i]%2==1)cnt++;
        }
        if(cnt>1){
            return s.size()-cnt+1;
        }
        return s.size();
        
    }
};
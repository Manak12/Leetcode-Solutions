class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1 == s2)
        return true;
        int s1FrequencyMap[26] = {0};
        int s2FrequencyMap[26] = {0};
        int numDiffs = 0;

        for(int i=0; i< s1.size(); i++){
            char s1_char = s1[i];
            char s2_char = s2[i];
            if(s1_char != s2_char){
                numDiffs++;
                if( numDiffs > 2) return false;
            }
    
         s1FrequencyMap[s1_char - 'a']++;
         s2FrequencyMap[s2_char - 'a']++;
        }

        for (int i =0 ; i< 26; i++){
            if(s1FrequencyMap[i] != s2FrequencyMap[i])
            return false;
        }

        return true;

    }
};
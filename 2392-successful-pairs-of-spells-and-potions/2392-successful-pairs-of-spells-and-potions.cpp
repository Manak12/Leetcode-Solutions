class Solution {
public:
int valid_pos(vector<int>& potions, long long success, int spell){
long potion_needed = (success + spell - 1) / spell;
   int left=0, right=potions.size();
   while(left< right) {
    int mid = left + ( right-left)/2;
      if(potions[mid] >= potion_needed)
       right = mid;
      else
       left = mid + 1;
    }
   return left;
}
vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
  sort(potions.begin(), potions.end());
  vector<int> result;
   for (int spell: spells) {
     result.push_back(potions.size()- valid_pos(potions, success, spell));
      }
   return result;
}
};
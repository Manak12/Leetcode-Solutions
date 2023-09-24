class Solution {
public:
    bool closeStrings(string a, string b) {
        if (a.size() != b.size()) 
        return false;
        array<int, 26> ca = {}, cb = {}, sa = {}, sb = {};
        for (char c : a) ca[c - 'a']++, sa[c - 'a'] = 1;
        for (char c : b) cb[c - 'a']++, sb[c - 'a'] = 1;
        sort(begin(ca), end(ca));
        sort(begin(cb), end(cb));
        return ca == cb && sa == sb;
    }
};
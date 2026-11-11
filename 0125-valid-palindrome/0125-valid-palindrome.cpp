class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.length() - 1;

        while (left < right) {
            // Move left pointer forward if not alphanumeric
            if (!isalnum(s[left])) {
                left++;
            } 
            // Move right pointer backward if not alphanumeric
            else if (!isalnum(s[right])) {
                right--;
            } 
            // Compare lowercase versions of both characters
            else {
                if (tolower(s[left]) != tolower(s[right])) {
                    return false;
                }
                left++;
                right--;
            }
        }

        return true;
    }
};

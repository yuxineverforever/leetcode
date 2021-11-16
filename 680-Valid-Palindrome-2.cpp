/**
 * Q:
 *
 * Given a string s,
 * return true if the s can be palindrome after deleting at most one character from it.
 *
 * A:
 *
 * A left pointer and a right pointer.
 *
 */
class Solution
{
public:
    bool validPalindrome(string s) {
        int r=0;
        int l=s.size()-1;
        while (r<=l)
        {
            if(s[r]!=s[l])
            {
              return isPalindrome(s,++r,l)||isPalindrome(s,--r,--l);
            }
            else
            {
                r++;
                l--;
            }
        }
        return true;
    }

    bool isPalindrome(string& s,int a,int b)
    {
        while(a<=b)
        {
            if(s[a++]!=s[b--])
                return false;
        }
        return true;
    }
};
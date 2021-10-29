/** Q:
 *  In an array, every number appear twice. Only one number appears once.
 *
 *  Return the number that appears only once.
 *  A:
 *
 *  use XOR
 **/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ret = 0;
        for (auto e: nums) ret ^= e;
        return ret;
    }
};
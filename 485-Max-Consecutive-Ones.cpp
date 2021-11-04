/**
 *
 * Q: Give an array of 1 and 0, try to find the max number of consecutive 1s.
 *
 * A: just use a count to count how many 1s you have meet, one time traverse.
 *
 * @param nums
 * @param numsSize
 * @return
 */

int findMaxConsecutiveOnes(int* nums, int numsSize){
    int count=0, maxCount=0;                    //count记录连续1的个数，maxCount记录最大连续1的个数

    for(int i=0; i < numsSize; i++){            //遍历数组
        if(nums[i] == 1){                       //元素为1，count+1
            count++;
            maxCount = fmax(count, maxCount);   //更新maxCount
        }else{
            count = 0;                          //元素为0，count清零
        }
    }

    return maxCount;
}
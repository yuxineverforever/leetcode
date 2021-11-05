/**
 * The median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value and the median is the mean of the two middle values.

    For example, for arr = [2,3,4], the median is 3.
    For example, for arr = [2,3], the median is (2 + 3) / 2 = 2.5.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-median-from-data-stream
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 *
 *
 */
// https://leetcode-cn.com/problems/statistics-from-a-large-sample/

class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int,vector<int>,less<int>>a;//大顶堆
    priority_queue<int,vector<int>,greater<int>>b;//小顶堆
//加入一个数字有n个，大顶堆记录前(n+1)/2个，小顶堆记录剩下的
    int nums=0;
    MedianFinder() {

    }

    void addNum(int num) {
        if(nums==0) a.push(num);

            //如果现在是奇数，a里面比b里面多一个
        else if(nums&1){
            if(num>=a.top()) b.push(num);
            else{
                b.push(a.top());
                a.pop();
                a.push(num);
            }
        }
            //现在是偶数，a和b一样
        else {
            if(num<b.top()) a.push(num);
            else{
                a.push(b.top());
                b.pop();
                b.push(num);
            }
        }
        nums++;
    }

    double findMedian() {
        if(nums&1){return double (a.top());}
        return (double(a.top())+double(b.top()))/2;
    }
};
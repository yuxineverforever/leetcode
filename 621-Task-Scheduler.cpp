
/***
 *
 * Given a characters array tasks, representing the tasks a CPU needs to do, where each letter represents a different task. Tasks could be done in any order. Each task is done in one unit of time. For each unit of time, the CPU could complete either one task or just be idle.

However, there is a non-negative integer n that represents the cooldown period between two same tasks (the same letter in the array), that is that there must be at least n units of time between any two same tasks.

Return the least number of units of times that the CPU will take to finish all the given tasks.
 *
 *
 *
 *
 * A: use bucket. Allocate bucket in such a way.
 * 建立个数为任务数量最多的那个任务 的桶子，size = n+1，比如下图，等待时间 n=2，A 任务个数 6 个，我们建立 6 桶子，每个容量为 3：
我们可以把一个桶子看作一轮任务

    先从最简单的情况看起，现在就算没有其他任务，我们完成任务 A 所需的时间应该是 (6-1)*3+1=16，因为最后一个桶子，不存在等待时间。

    可以看到 C 其实并没有对总体时间产生影响，因为它被安排在了其他任务的冷却期间；而 B 和 A 数量相同，这会导致最后一个桶子中，我们需要多执行一次 B 任务，现在我们需要的时间是 (6-1)*3+2=17

    前面两种情况，总结起来：总排队时间 = (桶个数 - 1) * (n + 1) + 最后一桶的任务数
    此时我们可以临时扩充某些桶子的大小，插进任务 F，对比一下插入前后的任务执行情况：
    插入前：ABC | ABC | ABD | ABD | ABD | AB
    插入后：ABCF | ABCF | ABD | ABD | ABD | AB
    我们在第一个、第二个桶子里插入了任务F，不难发现无论再继续插入多少任务，我们都可以类似处理，而且新插入元素肯定满足冷却要求
    继续思考一下，这种情况下其实每个任务之间都不存在空余时间，冷却时间已经被完全填满了。
 *
 * @param tasks
 * @param n
 * @return
 */

int leastInterval(vector<char>& tasks, int n) {
    int len=tasks.size();
    vector<int> vec(26);
    for(char c:tasks) ++vec[c-'A'];
    sort(vec.begin(),vec.end(),[](int& x,int&y){return x>y;});
    int cnt=1;
    while(cnt<vec.size()&&vec[cnt]==vec[0]) cnt++;
    return max(len,cnt+(n+1)*(vec[0]-1) );
}
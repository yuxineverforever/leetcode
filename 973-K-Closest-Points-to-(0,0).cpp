/**
 *
 * Q: Find the k points most close to the (0,0).
 *
 *  Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane and an integer k, return the k closest points to the origin (0, 0).

 *  The distance between two points on the X-Y plane is the Euclidean distance (i.e., √(x1 - x2)2 + (y1 - y2)2).

 *  You may return the answer in any order. The answer is guaranteed to be unique (except for the order that it is in).
 *
 *
 *
 * 我们可以使用一个大根堆实时维护前 kkk 个最小的距离平方。

首先我们将前 kkk 个点的编号（为了方便最后直接得到答案）以及对应的距离平方放入大根堆中，随后从第 k+1k+1k+1 个点开始遍历：如果当前点的距离平方比堆顶的点的距离平方要小，就把堆顶的点弹出，再插入当前的点。当遍历完成后，所有在大根堆中的点就是前 kkk 个距离最小的点。

不同的语言提供的堆的默认情况不一定相同。在 C++ 语言中，堆（即优先队列）为大根堆，但在 Python 语言中，堆为小根堆，因此我们需要在小根堆中存储（以及比较）距离平方的相反数。

 *
 *
 * A: use max heap.
 *
 *
 */

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, int>> q;
        for (int i = 0; i < k; ++i) {
            q.emplace(points[i][0] * points[i][0] + points[i][1] * points[i][1], i);
        }
        int n = points.size();
        for (int i = k; i < n; ++i) {
            int dist = points[i][0] * points[i][0] + points[i][1] * points[i][1];
            if (dist < q.top().first) {
                q.pop();
                q.emplace(dist, i);
            }
        }
        vector<vector<int>> ans;
        while (!q.empty()) {
            ans.push_back(points[q.top().second]);
            q.pop();
        }
        return ans;
    }
};
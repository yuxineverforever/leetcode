/**
 * Q: Implement a stack supporting four operations: 1. push() 2. pop() 3. top() 4. getMin()
 *
 * A: store a pair <current element, min element> in stack.
 https://leetcode-cn.com/problems/min-stack/
 */
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
    }

    void push(int x) {
        if (st.size() == 0) {
            st.push({x, x});
        } else {
            st.push({x, min(x, st.top().second)});
        }
    }

    void pop() {
        st.pop();
    }

    int top() {
        return st.top().first;
    }

    int getMin() {
        return st.top().second;
    }
private:
    stack<pair<int, int>> st;
};
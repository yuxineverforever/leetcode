
/**
 * Q:
 * On a single-threaded CPU, we execute a program containing n functions. Each function has a unique ID between 0 and n-1.

 *  Function calls are stored in a call stack: when a function call starts, its ID is pushed onto the stack, and when a function call ends, its ID is popped off the stack. The function whose ID is at the top of the stack is the current function being executed. Each time a function starts or ends, we write a log with the ID, whether it started or ended, and the timestamp.

 *  You are given a list logs, where logs[i] represents the ith log message formatted as a string "{function_id}:{"start" | "end"}:{timestamp}". For example, "0:start:3" means a function call with function ID 0 started at the beginning of timestamp 3, and "1:end:2" means a function call with function ID 1 ended at the end of timestamp 2. Note that a function can be called multiple times, possibly recursively.

 *  A function's exclusive time is the sum of execution times for all function calls in the program. For example, if a function is called twice, one call executing for 2 time units and another call executing for 1 time unit, the exclusive time is 2 + 1 = 3.

Return the exclusive time of each function in an array, where the value at the ith index represents the exclusive time for the function with ID i.

 *  A: use stack to simulate
 * According to the problem description, we can have at most 1 function running at the same time.
That means in terms of exclusive time calculation, any "start" log would immediately stop any running function.

The rules can be summerized as follows:

  when the log is an end , it ends the function on top of the stack. The elapsed time is (log timestamp - previous timestamp + 1) (+1 because it is the end of the time)

  when the log is a start, it pauses the function on top of the stack, which in terms of time calculation also means to END the the function on top of the stakc. The elapsed time is (log timestamp - previous timestamp) (no need to +1 because it is the beginning of the time)

That's all.

 */
class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {

        vector<int> res(n, 0);
        stack<pair<int, int>> s;

        for (string log : logs) {

            int c1 = log.find(':');

            int c2 = log.find(':', c1 + 1);

            int pid = stoi(log.substr(0, c1));

            string state = log.substr(c1 + 1, c2 - c1 - 1);

            int t = stoi(log.substr(c2 + 1, log.size()));

            if (state == "start") {
                s.emplace(pid, t);
            } else {

                auto [pid, tp] = s.top(); s.pop();

                res[pid] += t - tp + 1;

                if (!s.empty()) {
                    //  remove non exclusive time of previous process
                    res[s.top().first] -= t - tp + 1;
                }

            }
        }
        return res;
    }
};
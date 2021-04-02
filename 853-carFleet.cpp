#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        if (position.empty() || speed.empty()) {
            return 0;
        }
        int N = position.size();
        std::map<int, double> pos2ReachTime;
        for (int i = 0; i < N; i++) {
            pos2ReachTime[-position[i]] = static_cast<double>(target - position[i]) / speed[i];
        }

        double curReachTime = 0.0;
        int count = 0;
        for (const auto& p : pos2ReachTime) {
            if (p.second <= curReachTime) {
                continue; // can be merge
            }
            curReachTime = p.second;
            count++;
        }

        return count;
    }
};

int main(){
    Solution s;
    int target = 12;
    std::vector<int> position({10,8,0,5,3});
    std::vector<int> speed ({2,4,1,1,3});
    std::cout << s.carFleet(target,position,speed) << std::endl;
    return 0;
}
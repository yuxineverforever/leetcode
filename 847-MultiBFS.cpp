//
// Created by yuxin on 3/23/21.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <vector>
#include <queue>
using namespace std;

class Solution {

public:

    struct State{
        int state;
        int node;
        explicit State(int s, int n):state(s),node(n){};
    };

    int shortestPathLength(vector<vector<int>>& graph) {
        int N = graph.size();
        int END = (1<<N) - 1;

        auto visited = std::vector<std::vector<int>>(1<<N, std::vector<int>(N,0));
        std::vector<State> curr;

        for (int i=0; i<N; i++){
            curr.push_back(State(1<<i, i));
            visited[1<<i][i] = 1;
        }
        for (int level = 0;!curr.empty();++level){
            std::vector<State> next;
            for (auto s:curr){
                for (auto ngb: graph[s.node]){
                    int newState = s.state | (1<<ngb);
                    if (newState == END) return level+1;
                    if (!visited[newState][ngb]){
                        visited[newState][ngb] = 1;
                        next.push_back(State(newState,ngb));
                    }
                }
            }
            curr = next;
        }
        return -1;
    }

};

int main(int argc, char **argv)
{
    Solution s;
    std::vector<std::vector<int>> m;
    m.push_back(std::vector<int>{1,2,3});
    m.push_back(std::vector<int>{0});
    m.push_back(std::vector<int>{0});
    m.push_back(std::vector<int>{0});

    std::cout << s.shortestPathLength(m) << std::endl;

    return 0;
}

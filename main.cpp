#include <algorithm>
#include <cstring>
#include <climits>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <sstream>
#include <numeric>

// https://leetcode.com/problems/average-of-levels-in-binary-tree/

#include "../utils/VectorUtils.hpp"
#include "../utils/TreeUtils.hpp"

#include "../utils/PrintUtils.hpp"

using namespace std;

#pragma GCC diagnostic ignored "-Wunknown-pragmas"

// Live coding problems, watch at
// https://www.twitch.tv/yipcubed
// https://www.youtube.com/channel/UCTV_UOPu7EWXvYWsBFxMsSA/videos
//

// makes code faster, but larger. Just for LeetCode fun!
#pragma GCC optimise ("Ofast")

// makes stdin not synced so it is faster. Just for LeetCode fun!
static auto _no_sync_ = []() {              // NOLINT
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> v;
        if (!root)
            return v;
        queue<const TreeNode *> q;
        q.push(root);
        unsigned long nodesAtLevel = 1;
        while (!q.empty()) {
            vector<int> ch;
            while (nodesAtLevel) {
                const TreeNode *tp = q.front();
                q.pop();
                ch.push_back(tp->val);
                if (tp->left) q.push(tp->left);
                if (tp->right) q.push(tp->right);
                --nodesAtLevel;
            }
            v.push_back(accumulate(ch.begin(), ch.end(), 0.0)/ch.size());
            nodesAtLevel = q.size();
        }
        // reverse(v.begin(), v.end());
        return v;
    }
};

void test1() {
    vector<int> v1{3, 9, 20, -1, -1, 15, 7};
    auto t1 = new TreeNode(v1, -1);

    cout << "[3, 14.5, 11] ? " << Solution().averageOfLevels(t1) << endl;

}

void test2() {

}

void test3() {

}
class Solution {
public:
    struct Node {
        long long score = 0;
        vector<int> ids;
    };

    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();

        // {left, right, weight, original index}
        vector<array<long long, 4>> a(n);
        for (int i = 0; i < n; ++i) {
            a[i] = {
                intervals[i][0],
                intervals[i][1],
                intervals[i][2],
                i
            };
        }

        sort(a.begin(), a.end(), [](const auto& x, const auto& y) {
            if (x[0] != y[0]) return x[0] < y[0];
            return x[3] < y[3];
        });

        // For every interval i, find the first interval whose
        // left endpoint is strictly greater than a[i].right.
        vector<long long> lefts(n);
        for (int i = 0; i < n; ++i)
            lefts[i] = a[i][0];

        vector<int> nxt(n);
        for (int i = 0; i < n; ++i) {
            nxt[i] = upper_bound(lefts.begin(), lefts.end(), a[i][1])
                     - lefts.begin();
        }

        // dp[i][k] = best answer using intervals i..n-1,
        // choosing at most k intervals.
        vector<array<Node, 5>> dp(n + 1);

        for (int i = n - 1; i >= 0; --i) {
            for (int k = 1; k <= 4; ++k) {
                // Option 1: skip interval i.
                Node skip = dp[i + 1][k];

                // Option 2: take interval i.
                Node take = dp[nxt[i]][k - 1];
                take.score += a[i][2];
                take.ids.push_back((int)a[i][3]);

                // Required output is lexicographically smallest
                // array of ORIGINAL indices.
                sort(take.ids.begin(), take.ids.end());

                dp[i][k] = better(skip, take);
            }
        }

        return dp[0][4].ids;
    }

private:
    Node better(const Node& a, const Node& b) {
        if (a.score != b.score)
            return a.score > b.score ? a : b;

        // std::vector comparison is lexicographical.
        return a.ids < b.ids ? a : b;
    }
};

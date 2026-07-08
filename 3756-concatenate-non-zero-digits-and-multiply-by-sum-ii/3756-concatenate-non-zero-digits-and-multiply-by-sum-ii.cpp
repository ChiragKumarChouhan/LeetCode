class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        const int MOD = 1e9 + 7;

        int n = s.size();

        // prefix sum of digits
        vector<long long> prefSum(n + 1, 0);
        for (int i = 0; i < n; i++)
            prefSum[i + 1] = prefSum[i] + (s[i] - '0');

        // store non-zero digits
        vector<int> pos;
        vector<int> digit;

        for (int i = 0; i < n; i++) {
            if (s[i] != '0') {
                pos.push_back(i);
                digit.push_back(s[i] - '0');
            }
        }

        int k = pos.size();

        // powers of 10
        vector<long long> pw(k + 1, 1);
        for (int i = 1; i <= k; i++)
            pw[i] = (pw[i - 1] * 10) % MOD;

        // prefix value of concatenated non-zero digits
        vector<long long> prefVal(k + 1, 0);
        for (int i = 0; i < k; i++)
            prefVal[i + 1] = (prefVal[i] * 10 + digit[i]) % MOD;

        vector<int> ans;

        for (auto &q : queries) {
            int l = q[0], r = q[1];

            // sum of digits in substring
            long long sum = prefSum[r + 1] - prefSum[l];

            auto it1 = lower_bound(pos.begin(), pos.end(), l);
            auto it2 = upper_bound(pos.begin(), pos.end(), r);

            int L = it1 - pos.begin();
            int R = it2 - pos.begin();

            if (L == R) {
                ans.push_back(0);
                continue;
            }

            int len = R - L;

            long long x =
                (prefVal[R] - prefVal[L] * pw[len] % MOD + MOD) % MOD;

            ans.push_back((x * (sum % MOD)) % MOD);
        }

        return ans;
    }
};
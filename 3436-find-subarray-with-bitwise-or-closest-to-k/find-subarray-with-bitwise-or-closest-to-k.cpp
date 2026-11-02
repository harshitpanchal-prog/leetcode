
class Solution {
public:
    void updatefreq(int operation, int val, vector<int>& freq) {
        int i = 0;

        while (val > 0) {
            if (val & 1) {
                freq[i] += operation;
            }

            val >>= 1;
            i++;
        }
    }

    int minimumDifference(vector<int>& nums, int k) {
        int result = INT_MAX;

        vector<int> prev, curr;

        for (int num : nums) {
            curr.clear();
            curr.push_back(num);

            for (int x : prev) {
                int newOR = x | num;

                if (curr.back() != newOR) {
                    curr.push_back(newOR);
                }
            }

            for (int x : curr) {
                result = min(result, abs(k - x));

                if (result == 0)
                    return 0;
            }

            prev = curr;
        }

        return result;
    }
};

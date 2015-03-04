class Solution {
public:
    int maximumGap(vector<int> &num) {
        if (num.size() < 2)
        {
            return 0;
        }

        std::sort(num.begin(), num.end());
        int gap = 0;

        for (int n = 0, m = 1; m < num.size(); ++n, ++m)
        {
            int tmp_gap = num[m] - num[n];
            if (tmp_gap > gap)
            {
                gap = tmp_gap;
            }
        }

        //std::cout << gap << "\n";

        return gap;
    }
};
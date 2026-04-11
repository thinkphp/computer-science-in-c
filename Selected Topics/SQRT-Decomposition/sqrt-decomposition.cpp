class SqrtDecomposition {
public:
    vector<int> arr;
    vector<int> blockSum;
    int n, B;

    SqrtDecomposition(vector<int>& nums) {
        arr = nums;
        n = arr.size();
        B = sqrt(n);

        int numBlocks = (n + B - 1) / B;
        blockSum.assign(numBlocks, 0);

        for (int i = 0; i < n; i++)
            blockSum[i / B] += arr[i];
    }

    int query(int L, int R) {
        int sum = 0;

        int startBlock = L / B;
        int endBlock   = R / B;

        if (startBlock == endBlock) {
            for (int i = L; i <= R; i++)
                sum += arr[i];
            return sum;
        }

        for (int i = L; i < (startBlock + 1) * B; i++)
            sum += arr[i];

        for (int b = startBlock + 1; b < endBlock; b++)
            sum += blockSum[b];

        for (int i = endBlock * B; i <= R; i++)
            sum += arr[i];

        return sum;
    }
};

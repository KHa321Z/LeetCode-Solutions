class Solution {
public:
    double findMedianSortedArrays(vector<int>& A, vector<int>& B) {
        
        int na = A.size(), nb = B.size();
        int n = na + nb;

        return (n % 2) ? solve(A, B, n / 2, 0, na - 1, 0, nb - 1) : (solve(A, B, n / 2 - 1, 0, na - 1, 0, nb - 1) + solve(A, B, n / 2, 0, na - 1, 0, nb - 1)) / 2.0;

    }

    int solve(vector<int>& A, vector<int>& B, int k, int as, int ae, int bs, int be) {

        if (ae < as)
            return B[k - as];
        
        if (be < bs)
            return A[k - bs];

        int ai = (ae + as) / 2, bi = (be + bs) / 2;
        int av = A[ai], bv = B[bi];

        if (ai + bi < k)
            return (av > bv) ? solve(A, B, k, as, ae, bi + 1, be) : solve(A, B, k, ai + 1, ae, bs, be);
        else
            return (av > bv) ? solve(A, B, k, as, ai - 1, bs, be) : solve(A, B, k, as, ae, bs, bi - 1);

        return -1;

    }
};
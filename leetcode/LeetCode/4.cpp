#include <iostream>

using namespace std;

double findMedianSortedArrays(int A[], int m, int B[], int n)
{
    int k = (m + n + 1) / 2;
    double v = (double)FindKth(A, 0, m - 1, B, 0, n - 1, k);

    if ((m + n) % 2 == 0) {
        int k2 = k + 1;
        double v2 = (double)FindKth(A, 0, m - 1, B, 0, n - 1, k2);
        v = (v + v2) / 2;
    }

    return v;

}

int FindKth(int A[], int aL, int aR, int B[], int bL, int bR, int k)
{
    if (aL > aR) return B[bL + k - 1];
    if (bL > bR) return A[aL + k - 1];

    int aMid = (aL + aR) / 2;
    int bMid = (bL + bR) / 2;

    if (A[aMid] <= B[bMid]) {
        if (k <= (aMid - aL) + (bMid - bL) + 1)
            return FindKth(A, aL, aR, B, bL, bMid - 1, k);
        else
            return FindKth(A, aMid + 1, aR, B, bL, bR, k - (aMid - aL) - 1);
    }
    else { // A[aMid] > B[bMid]
        if (k <= (aMid - aL) + (bMid - bL) + 1)
            return FindKth(A, aL, aMid - 1, B, bL, bR, k);
        else
            return FindKth(A, aL, aR, B, bMid + 1, bR, k - (bMid - bL) - 1);
    }
}

int main()
{
    return 0;
}
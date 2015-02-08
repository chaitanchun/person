#include <iostream>
using namespace std;
void sortColors(int A[], int n) {
    int pf = -1;
    int pb = n;

    for (int i = 0; i<pb; ++i){
        int t = A[i];
        //red:0 w:1 b:2
        while (1 != t){
            if (0 == t){
                ++pf;
                if (pf<i){
                    int tmp = A[pf];
                    A[pf] = t;
                    t = tmp;
                    A[i] = t;
                    continue;
                }
                else {
                    // forword
                    break;
                }
            }
            else if (2 == t){
                --pb;
                if (pb>i){
                    int tmp = A[pb];
                    A[pb] = t;
                    t = tmp;
                    A[i] = t;
                }
                else {
                    break;
                }
            }
        } // end of while
    } // end of for
}

int main()
{
    int A[] = { 0, 1, 2, 2, 2, 0, 0 };
    sortColors(A, 7);
    return 0;
}
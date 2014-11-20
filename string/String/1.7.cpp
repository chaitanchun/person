#include <iostream>
using namespace std;

#define N 6
#define M 6
void clean(int mix[][N])
{
    bool row[M];
    for (size_t i = 0; i < M; i++)
        row[i] = false;
    bool col[N];
    for (size_t i = 0; i < N; i++)
        col[i] = false;
    for (size_t i = 0; i < M; i++)
    {
        for (size_t j = 0; j < N; j++)
        {
            if (mix[i][j] == 0)
            {
                row[i] = true;
                col[j] = true;
            }
        }
    }
    for (size_t i = 0; i < M; i++)
        if (row[i])
            for (size_t k = 0; k < N; k++)
                mix[i][k] = 0;
    for (size_t i = 0; i < N; i++)
        if (col[i])
            for (size_t k = 0; k < N; k++)
                mix[k][i] = 0;
}

void printMix(int mix[][N])
{
    for (size_t i = 0; i < M; i++)
    {
        for (size_t j = 0; j < N; j++)
            cout << mix[i][j] << " ";
        cout << endl;
    }
}

int main()
{
    int mix[M][N];
    for (size_t i = 0; i < M; i++)
    {
        for (size_t j = 0; j < N; j++)
        {
            mix[i][j] = M * i + j;
        }
    }
    printMix(mix);

    clean(mix);
    printMix(mix);
    return 0;
}
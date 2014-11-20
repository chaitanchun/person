#include <iostream>

using namespace std;

#define N 3

void transform(int image[][N])
{
    for (size_t i = 0; i < N / 2; i++)
    {
        for (size_t j = 0; j <= N / 2; j++)
        {
            //swap
            image[i][j] = image[i][j] ^ image[j][N - 1 - i] ^ image[N - 1 - i][N - 1 - j] ^ image[N - 1 - j][i];
            image[j][N - 1 - i] = image[i][j] ^ image[j][N - 1 - i] ^ image[N - 1 - i][N - 1 - j] ^ image[N - 1 - j][i];
            image[N - 1 - i][N - 1 - j] = image[i][j] ^ image[j][N - 1 - i] ^ image[N - 1 - i][N - 1 - j] ^ image[N - 1 - j][i];
            image[N - 1 - j][i] = image[i][j] ^ image[j][N - 1 - i] ^ image[N - 1 - i][N - 1 - j] ^ image[N - 1 - j][i];
            image[i][j] = image[i][j] ^ image[j][N - 1 - i] ^ image[N - 1 - i][N - 1 - j] ^ image[N - 1 - j][i];
        }
    }
}

void printImage(int image[][N])
{
    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 0; j < N; j++)
        {
            cout << image[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int image[N][N];
    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 0; j < N; j++)
        {
            image[i][j] = -1 * i * N + j;
        }
    }
    printImage(image);
    transform(image);
    printImage(image);
    return 0;
}
#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

int main()
{
    int sizes[] = {1000, 5000, 10000, 20000, 50000, 100000};

    for(int k = 0; k < 6; k++)
    {
        int n = sizes[k];

        int *X = new int[n];
        float *A = new float[n];

        // Automatically generate elements
        for(int i = 0; i < n; i++)
        {
            X[i] = i + 1;
        }

        auto start = high_resolution_clock::now();

        // O(n^2)
        for(int i = 0; i < n; i++)
        {
            int sum = 0;

            for(int j = 0; j <= i; j++)
            {
                sum = sum + X[j];
            }

            A[i] = (float)sum / (i + 1);
        }

        auto end = high_resolution_clock::now();

        auto duration = duration_cast<nanoseconds>(end - start);

        cout << "n = " << n << endl;
        cout << "O(n^2) time = " << duration.count()
             << " nanoseconds" << endl;
        cout << "--------------------------" << endl;

        delete[] X;
        delete[] A;
    }

    return 0;
}
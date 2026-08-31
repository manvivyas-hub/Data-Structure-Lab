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

        // Automatically generate array elements
        for(int i = 0; i < n; i++)
        {
            X[i] = i + 1;
        }

        int repetitions = 1000;

        auto start = high_resolution_clock::now();

        // O(n)
        for(int r = 0; r < repetitions; r++)
        {
            int sum = 0;

            for(int i = 0; i < n; i++)
            {
                sum = sum + X[i];
                A[i] = (float)sum / (i + 1);
            }
        }

        auto end = high_resolution_clock::now();

        auto duration = duration_cast<nanoseconds>(end - start);

        long long averageTime = duration.count() / repetitions;

        cout << "n = " << n << endl;
        cout << "O(n) time = " << averageTime
             << " nanoseconds" << endl;
        cout << "--------------------------" << endl;

        delete[] X;
        delete[] A;
    }

    return 0;
}
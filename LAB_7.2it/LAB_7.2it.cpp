#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

void Create(int** a, const int n, const int Low, const int High);
void Print(int** a, const int n);
bool SearchMinMax(int** a, const int n, int& maxAbove, int& minBelow);
void SwapMinMax(int** a, const int n);

int main()
{
    srand((unsigned)time(NULL));
    int Low = 7;
    int High = 65;
    int n;
    cout << "n = "; cin >> n;
    int** a = new int* [n];
    for (int i = 0; i < n; i++)
        a[i] = new int[n];
    Create(a, n, Low, High);
    Print(a, n);
    int maxAbove, minBelow;
    if (SearchMinMax(a, n, maxAbove, minBelow)) {
        cout << "Max above diagonal: " << maxAbove << endl;
        cout << "Min below diagonal: " << minBelow << endl;

        SwapMinMax(a, n);

        cout << "Matrix after swapping:\n";
        Print(a, n);

        cout << "Sum of swapped elements: " << maxAbove + minBelow << endl;
    }
    else
        cout << "There are no elements above and below diagonal" << endl;
    for (int i = 0; i < n; i++)
        delete[] a[i];
    delete[] a;
    return 0;
}

void Create(int** a, const int n, const int Low, const int High)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            a[i][j] = Low + rand() % (High - Low + 1);
}

void Print(int** a, const int n)
{
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << setw(4) << a[i][j];
        cout << endl;
    }
    cout << endl;
}

bool SearchMinMax(int** a, const int n, int& maxAbove, int& minBelow)
{
    maxAbove = a[0][1];
    minBelow = a[1][0];
    bool foundAbove = false;
    bool foundBelow = false;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (!foundAbove && a[i][j] > maxAbove) {
                maxAbove = a[i][j];
                foundAbove = true;
            }
            if (!foundBelow && a[j][i] < minBelow) {
                minBelow = a[j][i];
                foundBelow = true;
            }
        }
    }
    return foundAbove && foundBelow;
}

void SwapMinMax(int** a, const int n)
{
    int temp = a[n - 1][0];
    a[n - 1][0] = a[0][n - 1];
    a[0][n - 1] = temp;
}

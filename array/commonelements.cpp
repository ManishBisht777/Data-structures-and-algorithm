#include <iostream>
#include <vector>
using namespace std;

int main()
{

    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;
    int A[n1];
    int B[n2];
    int C[n3];
    for (int i = 0; i < n1; i++)
        cin >> A[i];

    for (int i = 0; i < n2; i++)
        cin >> B[i];

    for (int i = 0; i < n3; i++)
        cin >> C[i];

    int i = 0, j = 0, k = 0;

    int prev1, prev2, prev3;
    prev1 = prev2 = prev3 = -9999;
    while (i < n1 && j < n2 && k < n3)
    {
        while (A[i] == prev1 && i < n1)
        {
            i++;
        }
        while (B[j] == prev2 && j < n2)
        {
            j++;
        }
        while (C[k] == prev3 && k < n3)
        {
            k++;
        }
        if (A[i] == B[j] && A[i] == C[k])
        {
            cout << A[i] << " ";
            prev1 = A[i];
            prev2 = B[j];
            prev3 = C[k];
            i++;
            j++;
            k++;
        }

        else if (A[i] < B[j])
        {
            prev1 = A[i];
            i++;
        }

        else if (B[j] < C[k])
        {
            prev2 = B[j];
            j++;
        }
        else
        {
            prev3 = C[k];
            k++;
        }
    }
}
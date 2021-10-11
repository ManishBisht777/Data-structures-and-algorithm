#include <iostream>
#include <vector>
using namespace std;

int main()
{

    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;
    int a[n1];
    int b[n2];
    int c[n3];
    for (int i = 0; i < n1; i++)
        cin >> a[i];

    for (int i = 0; i < n2; i++)
        cin >> b[i];

    for (int i = 0; i < n3; i++)
        cin >> c[i];

    int i = 0, j = 0, k = 0;

    while (i < n1 || j < n2 || k < n3)
    {
        if (a[i] == b[j] && a[i] == c[k])
        {
            cout << a[i] << " ";
            i++, j++, k++;

            if (i == n1 || j == n2 || k == n3)
            {
                break;
            }
        }

        else if (a[i] < b[j])
        {

            i++;
        }

        else if (b[j] < c[k])
        {
            j++;
        }
        else
            k++;
    }
}
/* Given non-negative integers K, M, and an array arr[] with
 N elements find the Mth element of the array after K left rotations.

Examples:
Input: arr[] = {3, 4, 5, 23}, K = 2, M = 1
Output: 5
*/
#include <iostream>

using namespace std;

int MthElementAfterKRotations(int arr[], int n, int k, int m)
{
    return arr[(m + k - 1)%n];
}

int main()
{
    int arr[] = {3, 4, 5, 23};
    int k = 2, m = 2, n = 4;
    cout << MthElementAfterKRotations(arr, n, k, m);
}

/* Given an array, only rotation operation is allowed on array. 
We can rotate the array as many times as we want. Return the
 maximum possible summation of i*arr[i]. 
 Input: arr[] = {1, 20, 2, 10}
Output: 72
We can get 72 by rotating array twice.
{2, 10, 1, 20}
20*3 + 1*2 + 10*1 + 2*0 = 72

Normal algorithm is O(n^2)
Below is O(n) algorithm: 
Let us calculate initial value of i*arr[i] with no rotation
R0 = 0*arr[0] + 1*arr[1] +...+ (n-1)*arr[n-1]
R1 = 0*arr[n-1] + 1*arr[0] +...+ (n-1)*arr[n-2]
R1 - R0 = arr[0] + arr[1] + ... + arr[n-2] - (n-1)*arr[n-1]
Rj - Rj-1 = arrSum - n * arr[n-j]
Rj  = arrSum - n * arr[n-j] + Rj-1
Where arrSum is sum of all array elements, i.e., 
arrSum = ∑ arr[i]
        0<=i<=n-1 
*/
#include <iostream>

using namespace std;

int findMaxSumOnRotation(int arr[], int n)
{
    int arrSum = 0, max = 0, rSum = 0;
    for(int i = 0; i < n; i++)
    {
        arrSum+= arr[i];
        rSum += arr[i] * i;
    }
    int tSum = max = rSum;
    for(int i = 1; i < n; i++)
    {
        tSum = arrSum - (n*arr[n - i]) + tSum;
        if(tSum > max)
            max = tSum;
    }
    return max;
}

int main()
{
    //int arr[] = {1, 20, 2, 10};
    int arr[] = {10, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    cout << findMaxSumOnRotation(arr, 10) << endl; 
}
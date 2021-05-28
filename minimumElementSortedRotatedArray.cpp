/* A sorted array is rotated at some unknown point, find the minimum element in it. 
The following solution assumes that all elements are distinct.

Examples: 

Input: {5, 6, 1, 2, 3, 4}
Output: 1
*/

#include <iostream>

using namespace std;

int minSortedRotatedArray(int arr[], int n)
{
    if(arr[0] < arr[n-1])
        return arr[0];
 
    int i = 0;
    while(i < n && arr[i] < arr[i+1])
    i++;
    
    if(i < n-1)
        return arr[i+1];
    else
        return -1;
}

int main()
{
    int arr[] = {5, 6, 10, 2, 3, 4};
    int ret = minSortedRotatedArray(arr, 6);
    cout << "Min element: " << ret;
}
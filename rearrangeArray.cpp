/* Given an array of elements of length N, ranging from 0 to N – 1. 
Rearrange the array such that A[i] = i and if i is not present, 
display -1 at that place.

Input : arr = {-1, -1, 6, 1, 9, 3, 2, -1, 4, -1}
Output : [-1, 1, 2, 3, 4, -1, 6, -1, -1, 9]
*/

#include <iostream>

using namespace std;

int* rearrange(int arr[], const int s)
{
    int *tmp = new int[s]; 
    for(int i = 0; i < s; i++)
        tmp[i] = -1;
    for(int i = 0; i < s; i++)
    {
        if(arr[i] != -1)
            tmp[arr[i]] = arr[i];
    }
    return tmp;
}

int* rearrange_inplace(int arr[], const int s)
{
    int tmp = -1, tmp2;
    int cnt = 0;
    for(int i = 0; i < s; i++)
    {
        if(arr[i] != i && arr[i] != -1)
        {
            tmp = arr[i];
            arr[i] = -1;
            while(cnt < s && tmp != -1 && arr[tmp] != tmp)
            {
                tmp2 = arr[tmp];
                arr[tmp] = tmp;
                tmp = tmp2;
                cnt ++;
            }
        }
    }
    return arr;
}

int main()
{
    int arr[] = {-1, 3, 5, 2, 4, 0};
    int* tmp = rearrange_inplace(arr, 6);
    cout << endl;
    for(int i = 0; i < 6; i++)
        cout << tmp[i] << " ";
}
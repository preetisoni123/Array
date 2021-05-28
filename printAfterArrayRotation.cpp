/* Given an array of size n and multiple values around which we need to left rotate the array. How to quickly print multiple left rotations?

Examples : 

Input : 
arr[] = {1, 3, 5, 7, 9}
k1 = 1
k2 = 3
k3 = 4
Output : 
3 5 7 9 1
7 9 1 3 5
9 1 3 5 7
*/

#include <iostream>
#include <cmath>
using namespace std;

// Array Rotation without auxilary space
/*rotate(arr[], d, n)
  reverse(arr[], 1, d) ; // 1..d is array A
  reverse(arr[], d + 1, n); // d+1 to n is array B
  reverse(arr[], 1, n);
  Let the array be arr[] = [1, 2, 3, 4, 5, 6, 7], d =2 and n = 7 
  A = [1, 2] and B = [3, 4, 5, 6, 7] 
*/
//template<typename T>
//void swap(T& a, T& b)
void swap(int& a, int& b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

void rotateArrayWithoutAuxSpace(int arr[], int n, int k)
{
    //for(int i = 0; i < trunc(k/2); i++)
    for(int i = 0, j = k - 1; i < j; i++, j--)
       swap(arr[i], arr[j]);
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl << "2: "; 

    
    //for(int i = 0; i < trunc((n-k)/2); i++)
    for(int i = k, j = n - 1; i < j; i++, j--)
        swap(arr[i], arr[j]);
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl << "3: "; 

    //for(int i = 0; i <= trunc(n/2); i++)
    for(int i = 0, j = n-1; i <j; i++, j--)
        swap(arr[i], arr[j]);
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl << "x: "; 
} 

// Array rotation with auxilary space
void printLeftArrayRotations(int arr[], int n, int k)
{
    if(k > n - 1)
	    k = k%n;
    int* tmp = new int[k]; 
    for(int i = 0; i < k; i++)
        tmp[i] = arr[i];
    for(int i = 0; i < n - k; i++)
        arr[i] = arr[k+i];
    for(int i = n-k; i < n; i++)
        arr[i] = tmp[i - (n - k)];
    return;
}

int main()
{
    int arr[] = {1, 3, 5, 7, 9};
    int n = 5;
    //printLeftArrayRotations(arr, 5, 4);
    rotateArrayWithoutAuxSpace(arr, 5, 1);
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;    
}
#include<iostream>
using namespace std;

//find the maximum value in the input array
int getMax(int arr[], int n){
    int max = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

//implement the counting sort (it is a stable sort)
void countSort(int arr[], int n, int exp){
    int output[n];//initialize the output array
    int i, count[10] = {0};

    for (int i = 0; i < n; i++)
    {
        count[(arr[i]/exp) % 10]++;
    }
    for (int i = 1; i < 10; i++)
    {
        count[i] += count[i-1];
    }
    for (int i = n-1; i >= 0; i--)
    {
        output[count[(arr[i]/exp) % 10] - 1] = arr[i];
        count[(arr[i]/exp) % 10]--;
    }
    for (int i = 0; i < n; i++)
    {
        arr[i] = output[i];
    }
}

void radixSort(int arr[], int n){
    int m = getMax(arr, n);//to know the maximum number in the array, make sure the most significant digit
    
    //start from the least significant digit, then go to left in each loop
    for (int exp = 1; m/exp > 0; exp *= 10)
    {
        countSort(arr, n, exp);
    }
}

//implement the print() function
void print(int arr[], int n){
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int main(){
    int arr[] = {170,45,75,90,802,24,2,66};//input array
    int n = sizeof(arr) / sizeof(arr[0]);//length of the array

    radixSort(arr, n);//implement the radix sort
    print(arr, n);
    
    return 0;
}
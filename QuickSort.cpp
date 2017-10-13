//C++ implementation Quicksort
#include <iostream>
using namespace std;

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

int partition (int arr[], int low, int high){
    int pointer = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high- 1; j++){
        if (arr[j] <= pointer){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high){
    if (low < high){
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void printArray(int arr[], int size){
    for (int i=0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main(){
    int arr[] = {90, 57, 68, 89, 11, 35};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Before:" << endl;
    printArray(arr, n);
    quickSort(arr, 0, n-1);
    cout << "After:" << endl;
    printArray(arr, n);
    return 0;
}

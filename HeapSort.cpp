#include<iostream>
using namespace std;

void swap(int arr[], int i, int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void HeapInsert(int arr[], int i){
    while(arr[i] > arr[(i - 1) / 2]){
        swap(arr, i , (i - 1) / 2);
        i = (i - 1) / 2;
    }
}

void Heapify(int arr[], int i, int size){
    int l = i * 2 + 1;
    while(l < size){
        int best = l + 1 < size && arr[l + 1] > arr[l] ? l + 1 : l;
        best = arr[i] > arr[best] ? i : best;
        if(best == i){
            break;
        }
        swap(arr, i, best);
        i = best;
        l = i * 2 + 1;
    }
}

void HeapSort(int arr[]){
    int size = sizeof(arr) / sizeof(arr[0]);
    for(int i = 0; i < size; i++){
        HeapInsert(arr, i);
    }
    while(size > 1){
        swap(arr, 0, --size);
        Heapify(arr, 0, size);
    }
}

int main(){

    return 0;
}

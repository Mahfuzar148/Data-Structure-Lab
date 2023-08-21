#include <bits/stdc++.h>
using namespace std;

void heapify(int arr[], int N, int i) {
    int smallest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < N && arr[l] < arr[smallest])
        smallest = l;

    if (r < N && arr[r] < arr[smallest])
        smallest = r;

    if (smallest != i) {
        swap(arr[i], arr[smallest]);
        heapify(arr, N, smallest);
    }
}

void buildHeap(int arr[], int N) {
    int startIdx = (N / 2) - 1;
    for (int i = startIdx; i >= 0; i--) {
        heapify(arr, N, i);
    }
}

void printHeap(int arr[], int N) {
    cout << "Array representation of Heap is:\n";
    for (int i = 0; i < N; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

int main() {
    int arr[100] = {100, 1, 3, 5, 500, 4, 6, 13, 10, 150, 9, 8, 15, 17};

    int n = sizeof(arr) / sizeof(arr[0]);
    int N = n - count(arr, arr + n, 0);

    cout << N << endl;

    buildHeap(arr, N);
    printHeap(arr, N);

    return 0;
}


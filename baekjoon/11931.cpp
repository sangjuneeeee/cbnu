//merge sort 연습

#include <iostream>
using namespace std;

int* temp;

void conquer( int start, int end, int mid, int arr[] ) {
    int l = start;
    int r = mid + 1;
    int x = start;

    while ( l <= mid && r <= end ) {
        if ( arr[l] > arr[r] ) {
            temp[x] = arr[l];
            l++;
        } else {
            temp[x] = arr[r];
            r++;
        }
        x++;
    }
    if ( l > mid ) {
        for ( int i = r; i <= end; i++ ) {
            temp[x] = arr[i];
            x++;
        }
    } else {
        for ( int i = l; i <= mid; i++ ) {
            temp[x] = arr[i];
            x++;
        }
    }
    for ( int i = start; i <= end; i++ ) {
        arr[i] = temp[i];
    }
}

void split ( int arr[], int start, int end) {
    int mid = (start + end) / 2;

    if ( start < end ) {
        split ( arr, start, mid );
        split ( arr, mid + 1, end );
        conquer( start, end, mid, arr );
    }
    
}

int main () {
    int n;
    int* arr;
    cin >> n;
    arr = new int[n];
    temp = new int[n];
    for ( int i = 0; i < n; i++ ) {
        cin >> arr[i];
    }
    split ( arr, 0, n-1 );
    for ( int j = 0; j < n; j++ ) {
        cout << arr[j] << '\n';
    }
}
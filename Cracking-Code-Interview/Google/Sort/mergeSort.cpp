#include <iostream>
#include <vector>

using namespace std;

#include <iostream>
#include <vector>

// Merge two sorted arrays into a single sorted array
void merge(vector<int>& arr, int left, int mid, int right) {
    // Calculate the sizes of the two subarrays
    int n1 = mid - left + 1; // Size of the left subarray
    int n2 = right - mid;    // Size of the right subarray
    
    // Create temporary arrays to store the subarray values
    vector<int> leftArr(n1);  // Temporary array for the left subarray
    vector<int> rightArr(n2); // Temporary array for the right subarray
    
    // Copy data to temporary arrays
    for (int i = 0; i < n1; i++) {
        leftArr[i] = arr[left + i]; // Copy elements from the left subarray to leftArr
    }
    for (int j = 0; j < n2; j++) {
        rightArr[j] = arr[mid + 1 + j]; // Copy elements from the right subarray to rightArr
    }
    
    int i = 0; // Index for the leftArr
    int j = 0; // Index for the rightArr
    int k = left; // Index for the merged array
    
    // Merge the two subarrays back into the original array
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i]; // Choose the smaller element from leftArr
            i++;
        } else {
            arr[k] = rightArr[j]; // Choose the smaller element from rightArr
            j++;
        }
        k++;
    }
    
    // Copy any remaining elements from leftArr (if any)
    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }
    
    // Copy any remaining elements from rightArr (if any)
    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

// Merge Sort function
void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2; // Calculate the middle index
        
        // Recursively sort the left and right halves
        mergeSort(arr, left, mid);       // Sort the left half
        mergeSort(arr, mid + 1, right);  // Sort the right half
        
        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}

int main() {
    vector<int> arr = {12, 11, 13, 5, 6, 7};
    
    cout << "Original array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
    
    mergeSort(arr, 0, arr.size() - 1); // Call Merge Sort
    
    cout << "Sorted array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}


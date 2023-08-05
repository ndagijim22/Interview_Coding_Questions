// O(n) solution for finding maximum sum of
// a subarray of size k
#include <iostream>
#include <vector>

using namespace std;

// Returns maximum sum in a subarray of size k.
int maxSum(int arr[], int n, int k)
{
	// n must be greater
	if (n < k) {
		cout << "Invalid";
		return -1;
	}

	// Compute sum of first window of size k
	int max_sum = 0;
	for (int i = 0; i < k; i++)
		max_sum += arr[i];

	// Compute sums of remaining windows by
	// removing first element of previous
	// window and adding last element of
	// current window.
	int window_sum = max_sum;
	for (int i = k; i < n; i++) {
        //substract the old number and add the new number
		window_sum += arr[i] - arr[i - k];
		max_sum = max(max_sum, window_sum);
	}

	return max_sum;
}
/*
    Find the shortest array with the sum that is greater than or equal to a number x
*/
int dynamicSlidingWindow(vector <int> arr, int x) {
    // Track our min value
    int min_length = INT_MAX;

    // The current range and sum of our sliding window
    int start = 0;
    int end = 0;
    int current_sum = 0;

    // Extend the sliding window until our criteria is met
    while (end < arr.size()) {
        current_sum = current_sum + arr[end];
        end = end + 1;

        // Then contract the sliding window until it no longer meets our condition
        while (start < end && current_sum >= x) {
            current_sum = current_sum - arr[start];
            start = start + 1;

            // Update the min_length if this is shorter than the current min
            min_length = min(min_length, end - start + 1);
        }
    }
    return min_length;
}
// Driver code
int main()
{
	int arr[] = { 1, 4, 2, 10, 2, 3, 1, 0, 20 };
    vector<int> myVector = {1,2,3,4,5,6};
    int x = 7;
	int k = 4;
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << maxSum(arr, n, k) << endl;

    cout << dynamicSlidingWindow(myVector, x) << endl;
	return 0;
}

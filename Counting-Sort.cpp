#include <iostream>
#include <vector>
#include <algorithm> // for max function

using namespace std;

void countingSort(vector<int>& arr) {
    // Step 1: Find the maximum element in the array
    int max_val = *max_element(arr.begin(), arr.end());

    // Step 2: Create a count array to store the frequency of each element
    vector<int> count(max_val + 1, 0);

    // Step 3: Count the occurrences of each element
    for (int num : arr) {
        count[num]++;
    }

    // Step 4: Modify the count array to store the cumulative counts
    for (int i = 1; i <= max_val; i++) {
        count[i] += count[i - 1];
    }

    // Step 5: Build the output array using the cumulative counts
    vector<int> output(arr.size());
    for (int i = arr.size() - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // Copy the sorted elements back into the original array
    arr = output;
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Original Array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    // Apply counting sort
    countingSort(arr);

    cout << "Sorted Array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

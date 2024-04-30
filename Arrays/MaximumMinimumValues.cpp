#include<iostream>
#include<climits>

using namespace std;

int minimumValue(int arr[], int size) {
	int minVal = INT_MAX;
	int ans = 0;
	for(int i = 0; i < size; i++) {
		if (arr[i] < minVal) {
			minVal = arr[i];
			ans = i;
		}
	}
	return ans;
}

int maximumValue(int arr[], int size) {
	int maxVal = INT_MIN;
	int ans = 0;
	for(int i = 0; i < size; i++) {
		if (arr[i] > maxVal) {
			maxVal = arr[i];
			ans = i;
		}
	}
	return ans;
}

int main() {
	int arr[] = {12, 78, 67, 43, 89, 8, 56, 90, 34, 78};
	int size = sizeof(arr)/sizeof(arr[0]);
	
	int ans = minimumValue(arr, size);
	cout << "Minimum Value found at index: " << ans << " and it's value is: " << arr[ans] << "." << endl;
	
	int ans2 = maximumValue(arr, size);
	cout << "Maximum Value found at index: " << ans2 << " and it's value is: " << arr[ans2] << "." << endl;
}

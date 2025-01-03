#include <iostream>
using namespace std;

int main() {
    int n, sum = 0;

    
    cout << "Enter the number of elements: ";
    cin >> n;

   
    int arr[n];


    cout << "Enter the elements of the array:" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    for (int i = 0; i < n; ++i) {
        sum += arr[i];
    }

    // Output the result
    cout << "The sum of the array elements is: " << sum << endl;

    return 0;
}

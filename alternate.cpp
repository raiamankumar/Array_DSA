#include <iostream>
#include <vector>
using namespace std;

vector<int> AlternateArray(vector<int>& arr) {
    vector<int> result;
    for (int i = 0; i < arr.size(); i += 2) {
        result.push_back(arr[i]);
    }
    return result;
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> res = AlternateArray(arr);

    cout << "Alternate elements are: ";
    for (int x : res) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}

<<<<<<< HEAD
#include <iostream>
#include <vector>
using namespace std;

vector<int> leadersNaive(vector<int>& arr) {
    int n = arr.size();
    vector<int> leaders;
    
    for (int i = 0; i < n; i++) {
        bool isLeader = true; // assume arr[i] is leader

        // check all elements to the right of arr[i]
        for (int j = i + 1; j < n; j++) {
            if (arr[j] > arr[i]) {
                isLeader = false; // arr[i] is smaller, so not a leader
                break;            // no need to check further
            }
        }

        if (isLeader) leaders.push_back(arr[i]);
    }
    
    return leaders;
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    vector<int> res = leadersNaive(arr);

    cout << "Leaders are: ";
    for (int x : res) cout << x << " ";
    cout << endl;
}
=======
#include <iostream>
#include <vector>
using namespace std;

vector<int> leadersNaive(vector<int>& arr) {
    int n = arr.size();
    vector<int> leaders;
    
    for (int i = 0; i < n; i++) {
        bool isLeader = true; // assume arr[i] is leader

        // check all elements to the right of arr[i]
        for (int j = i + 1; j < n; j++) {
            if (arr[j] > arr[i]) {
                isLeader = false; // arr[i] is smaller, so not a leader
                break;            // no need to check further
            }
        }

        if (isLeader) leaders.push_back(arr[i]);
    }
    
    return leaders;
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    vector<int> res = leadersNaive(arr);

    cout << "Leaders are: ";
    for (int x : res) cout << x << " ";
    cout << endl;
}
>>>>>>> 9777ce9275c4f8345e3c897d7d500b9f70545c62

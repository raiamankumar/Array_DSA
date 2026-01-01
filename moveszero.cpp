<<<<<<< HEAD
#include <iostream>
#include <vector>

using namespace std;

void pushZerosToEnd(vector<int> &arr) {
    
    vector<int> temp(arr.size());

    int j = 0;

    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] != 0)
            temp[j++] = arr[i];
    }

    while (j < arr.size()) {
        temp[j++] = 0;
    }

    for (int i = 0; i < arr.size(); i++)
       arr[i] = temp[i];
}

int main() {
    int n;
    cout<<"enter the no of element:";
    cin>>n;
    vector<int> arr(n);
    cout<<"enter the element:";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
     pushZerosToEnd(arr);

    for (int i=0;i<n;i++) {
        cout << arr[i]<< " ";
    }
    return 0;
=======
#include <iostream>
#include <vector>

using namespace std;

void pushZerosToEnd(vector<int> &arr) {
    
    vector<int> temp(arr.size());

    int j = 0;

    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] != 0)
            temp[j++] = arr[i];
    }

    while (j < arr.size()) {
        temp[j++] = 0;
    }

    for (int i = 0; i < arr.size(); i++)
       arr[i] = temp[i];
}

int main() {
    int n;
    cout<<"enter the no of element:";
    cin>>n;
    vector<int> arr(n);
    cout<<"enter the element:";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
     pushZerosToEnd(arr);

    for (int i=0;i<n;i++) {
        cout << arr[i]<< " ";
    }
    return 0;
>>>>>>> 9777ce9275c4f8345e3c897d7d500b9f70545c62
}
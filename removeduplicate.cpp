#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

int removeDuplicate(vector<int>&arr){
     int idx=0;
     unordered_set<int>s;
     for(int i=0;i<arr.size();i++){
        if (s.find(arr[i]) == s.end()) { 
            s.insert(arr[i]);  
            arr[idx++] = arr[i];  
        }
    }
 
    return s.size(); 
}

int main() {
    vector<int> arr = {1, 2, 2, 3, 4, 4, 4, 5, 5};
    int newSize = removeDuplicate(arr);
    for (int i = 0; i < newSize; i++) 
        cout << arr[i] << " ";
    return 0;
}
    


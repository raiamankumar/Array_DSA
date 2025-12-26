#include <iostream>
#include <vector>
#include <algorithm> 


void printArray(const std::vector<int>& arr) {
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

void rotateRight(std::vector<int>& arr, int k) {
    int n = arr.size();
    if (n == 0) return;
    k = k % n;

    std::reverse(arr.begin(), arr.end());
    std::reverse(arr.begin(), arr.begin() + k);
    std::reverse(arr.begin() + k, arr.end());
}

void rotateLeft(std::vector<int>& arr, int k) {
    int n = arr.size();
    if (n == 0) return;
    k = k % n;

    std::reverse(arr.begin(), arr.begin() + k);
    std::reverse(arr.begin() + k, arr.end());
    std::reverse(arr.begin(), arr.end());
}


int main() {
    std::vector<int> arr1 = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;

    std::cout << "Original Array: ";
    printArray(arr1);

    
    std::vector<int> arrRight = arr1;
    rotateRight(arrRight, k);
    std::cout << "After Right Rotation by " << k << ": ";
    printArray(arrRight);

    
    std::vector<int> arrLeft = arr1;
    rotateLeft(arrLeft, k);
    std::cout << "After Left Rotation by " << k << ":  ";
    printArray(arrLeft);

    return 0;
}
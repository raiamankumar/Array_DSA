<<<<<<< HEAD
#include<bits/stdc++.h>
using namespace std;
bool sortedArray(vector<int>&arr){
    for(int i=1;i<arr.size();i++){
        if(arr[i]<arr[i-1]){
            return false;
        }
        
    }
    return true;
}
int main(){
    cout<<"enter the element of array:";
    int n;
    cin>>n;
    vector<int>arr(n);
    cout<<"enter the element:";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    bool result= sortedArray(arr);
    cout<<result;

    return 0;

=======
#include<bits/stdc++.h>
using namespace std;
bool sortedArray(vector<int>&arr){
    for(int i=1;i<arr.size();i++){
        if(arr[i]<arr[i-1]){
            return false;
        }
        
    }
    return true;
}
int main(){
    cout<<"enter the element of array:";
    int n;
    cin>>n;
    vector<int>arr(n);
    cout<<"enter the element:";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    bool result= sortedArray(arr);
    cout<<result;

    return 0;

>>>>>>> 9777ce9275c4f8345e3c897d7d500b9f70545c62
}
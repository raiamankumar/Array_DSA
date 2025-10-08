#include<bits/stdc++.h>
using namespace std;

void reverse(vector<int>&arr){
      int left=0;
      int right=arr.size()-1;

      while(left<right){
        swap(arr[left],arr[right]);

        left++;

        right--;

      }
}
int main(){
    int n;
    cout<<"enter the number of element:";
    cin>>n;
    vector<int>arr(n);
cout<<"enter the element:";

   for(int i=0;i<arr.size();i++){
    cin>>arr[i];
   }

    reverse(arr);

    cout<<"reverse array are:";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    return 0;

}
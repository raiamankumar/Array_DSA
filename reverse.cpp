<<<<<<< HEAD
#include<bits/stdc++.h>
using namespace std;

/*void reverse(vector<int>&arr){
      int left=0;
      int right=arr.size()-1;

      while(left<right){
        swap(arr[left],arr[right]);

        left++;

        right--;

      }
}*/
void reverse(vector<int>&arr,int low,int high){
    low=0;
     high=arr.size()-1;
     int temp;
     while(low<high){
        temp=arr[low];
        arr[low]=arr[high];
        arr[high]=temp;
        low++;
        high--;
     } 
}
int main(){
    int n;
    cout<<"enter the number of element:";
    cin>>n;
    int low=0;
    int high =n-1;

    vector<int>arr(n);
cout<<"enter the element:";

   for(int i=0;i<arr.size();i++){
    cin>>arr[i];
   }

    reverse(arr,low,high);

    cout<<"reverse array are:";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    return 0;

=======
#include<bits/stdc++.h>
using namespace std;

/*void reverse(vector<int>&arr){
      int left=0;
      int right=arr.size()-1;

      while(left<right){
        swap(arr[left],arr[right]);

        left++;

        right--;

      }
}*/
void reverse(vector<int>&arr,int low,int high){
    low=0;
     high=arr.size()-1;
     int temp;
     while(low<high){
        temp=arr[low];
        arr[low]=arr[high];
        arr[high]=temp;
        low++;
        high--;
     } 
}
int main(){
    int n;
    cout<<"enter the number of element:";
    cin>>n;
    int low=0;
    int high =n-1;

    vector<int>arr(n);
cout<<"enter the element:";

   for(int i=0;i<arr.size();i++){
    cin>>arr[i];
   }

    reverse(arr,low,high);

    cout<<"reverse array are:";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    return 0;

>>>>>>> 9777ce9275c4f8345e3c897d7d500b9f70545c62
}
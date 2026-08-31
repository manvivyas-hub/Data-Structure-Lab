#include<iostream>
using namespace std;
// using binary search method
// creating a function named as binary search with parameters array , size and target
int binarySearch(int arr[],int size,int target){
    
    int start = 0;
    int end = size - 1;

    while(start<=end){
        int mid = (start + end)/2 ;
        if(arr[mid]==target){
            return mid;
        }
        else if(arr[mid]<target){
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }
    }
    return -1;
}
void del(int arr[] , int &size , int index){
    for(int i=index;i<size-1;i++){
        arr[i] = arr[i+1];
    }
    size--;
}
void display(int arr[],int &size){
    for(int i=0;i<size;i++){
        cout<<"arr["<<i<<"] is :"<<arr[i]<<endl;
    }
}
void insert(int arr[] , int &size , int &target){
    int pos = 0;
    while(pos<size && arr[pos]<target){
        pos++;
    }
    for(int i=size;i>pos;i--){
        arr[i] = arr[i-1];
    }
    arr[pos] = target;
    size++;
}
int main(){
    int size;
    cout<<"Enter the size of the array : ";
    cin>>size;
    int *arr = new int[size];
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    display(arr,size);
    int target;
    cout<<"Enter the target element: ";
    cin>>target;
    if(cin.fail()){
        cout<<"Kindly enter a integer target element.";
        return 0;
    }
    int index = binarySearch(arr,size,target);
    if(index!=-1){
        del(arr,size,index);
        display(arr,size);
    }
    else{
        insert(arr,size,target);
        display(arr,size);
    }
    delete[] arr;
    return 0;
}
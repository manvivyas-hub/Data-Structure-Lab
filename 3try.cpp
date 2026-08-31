#include <iostream>
using namespace std;
// binary search function
int binarySearch(int arr[], int size, int target){
    int begin=0;
    int end=size-1;
    while(begin<=end){
        int mid=(begin+end)/2;
        if (target<arr[mid]){
            end=mid-1;
        }
        else if( target>arr[mid]){
            begin=mid+1;
        }
        else {
            return mid;
        }

    }
    return -1;
}

// delete function
void del(int arr[], int &size ,int index){
    cout<<"Element found at index:"<<index<<endl;
      for (int i=index; i<size ; i++){
        arr[i]=arr[i+1];
      }
      size--;
}

// insert function
void insert(int arr[], int &size , int&target){
    int position=0;
    while(position<size && arr[position]<target){
        position ++;
    }
    for(int i=size; i>=position;i--){
        arr[i]=arr[i-1];
    }
    arr[position]=target;
    size++;
}


//display function
void display(int arr[], int size){
    cout<<"The array after modification is:";
    for(int i=0; i<size; i++){
    cout<<arr[i]<<" ";
    }
}

int main(){
    int size;
    cout<<"Enter the size of array:";
    cin>>size;
    if(cin.fail()){
        cout<<"Enter integer value";
        return 0;
    }
    int *arr= new int [size];
    cout<<"Enter the elements of array:"<<endl;
    for(int i=0 ; i<size ; i++){
        cin>>arr[i];
        // using bubble sort to sort the array
        for(int i=0; i<size-1; i++){
        int Flag=0;
        for ( int j=0;j<size-i-1;j++){
            if (arr[j]>arr[j+1]){
                int temp;
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                Flag=1;
            }
        }
        if (Flag==0){
            break;
        }
    }
}
cout<<"Array after sorting is:";
for(int i=0; i<size; i++){
    cout<< arr[i]<<" ";
}
    if(cin.fail()){
        cout<<"Enter integer value";
        return 0;
    }
    int target;
    cout<<"\nEnter a target value:";
    cin>> target;
    if(cin.fail()){
        cout<<"Enter integer value";
        return 0;
    }
    
    int index=binarySearch(arr,size,target);
    if (index!=-1){
        del(arr,size,index);
        display(arr,size);
    }
    else {
        insert(arr,size,target);
        display(arr,size);
    }
    delete []arr;
    return 0;
}
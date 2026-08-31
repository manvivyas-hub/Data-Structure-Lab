#include <iostream>
using namespace std;
int main (){
    int n;
    cout<<"Enter the number of elements in the array:";
    cin>>n;
    int *a=new int[n];
    cout<<"Enter the elements of the array:"<<endl;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0; i<n-1; i++){
        int Flag=0;
        for ( int j=0;j<n-i-1;j++){
            if (a[j]>a[j+1]){
                int temp;
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
                Flag=1;
            }
        }
        if (Flag==0){
            break;
        }
    }
    cout<<"Sorted Array:";
    for(int i=0; i<n; i++){
        cout<<a[i]<<" ";
    }
    delete []a;
    return 0;
}
#include <iostream>
#include <chrono>
using namespace std::chrono;
using namespace std;
int main(){
 int n;
 cout<<"Enter the number of elements in your array:"<<endl;
 cin>>n;
 int X[n];
 float A[n];
 cout<<"Enter the elements of your array:"<<endl;
 for(int i=0;i<n;i++){
   cin>>X[i];
  }
 auto start = high_resolution_clock::now();
 for (int i=0; i<n; i++){
   int sum=0;
    for (int j=0;j<=i;j++){
      sum=sum+X[j];
    }
  A[i]= (float)sum/(i+1);
  }
  auto end = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(end - start);
 cout<<"Average array is:"<<endl;
 for(int i=0; i<n;i++){
  cout<<A[i]<<endl;
 }
  cout << "Execution time: " << duration.count() << " microseconds" << endl;
  return 0;
 }
#include <iostream>
#include <cmath>

int f( int x0, int x1){
return x0+x1;}
using namespace std;
 int main(){
 
 int A[31];
 A[0]=1;
 A[1]=3;
 cout<<A[0]<<endl;
 cout<<A[1]<<endl;
 for(int i=2;i<=30;i++){
 A[i]=f(A[i-1],A[i-2]);
 cout<<A[i]<<endl;
 }
 return 0;}

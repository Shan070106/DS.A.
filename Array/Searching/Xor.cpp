/* In searching, how XOR Operation used */

#include<iostream>
using namespace std;

/* given an array of n integers range from 1 to n+1, but missing one number, find that number*/
int find_missing_number(int arr[],int n){
    int x=0,y=0;
    for(int i=0;i<n;i++)
        x ^= arr[i];
    for(int j=1;j<=n+1;j++)
        y ^= j;
    
    return x^y;
}

/* given an array of n integers, all numbers occurring even number of times except one number which occurs odd number of times */
int odd_time_occurring(int arr[],int n){
    int x=0;
    for(int i=0;i<n;i++)
        x ^= arr[i];
    return x;                                
}

int main(){
    int n;
    cout<<"Enter length of array : "; cin>>n; 
    cout<<"Enter 1 to n+1 randomly and skip the one integer\n";
    int array1[n];
    for(int i=0;i<n;i++) cin>>array1[i];
    cout<<find_missing_number(array1,n)<<endl;

    // cout<<"Enter length of array : "; cin>>n;
    // cout<<"Enter integers in even number of times except one\n";
    // int array2[n];
    // for(int i=0;i<n;i++) cin>>array2[i];
    // cout<<odd_time_occurring(array2,n)<<endl;



    return 0;
}
// Question:

/* Given an array of n numbers, give an algorithm for checking whether there are any 
duplicate elements in the array or not */

#include<iostream>
#include<algorithm>
#include<unordered_map>
#include <cmath>
using namespace std;

// Brute Force Solution
void BruteForce(int arr[], int n){
    int cost = 0;
    for(int i=0;i<n;i++){
        cost++;
        for(int j=i+1;j<n;j++){
            cost++;
            if(arr[i] == arr[j])
                cout<<"Duplicate exist for "<<arr[i]<<endl;
                cout<<"Cost : "<<cost<<endl;
                return ;
        }
    }
    cout<<"No duplicates found"<<endl;
    cout<<"Cost : "<<cost<<endl;
}
// Time complexity : O(n^2)
// Space complexity : O(1)

// Better Solution(s) : 

void Better1(int arr[],int n){
    int cost=n*log(n);
    sort(arr,arr+n);
    for(int i=0;i<n-1;i++){
        cost++;
        if(arr[i] == arr[i-1]){
            cout<<"Duplicate exist for "<<arr[i]<<endl;
            cout<<"Cost : "<<cost<<endl;
            return ;
        }
    }
    cout<<"No duplicates found"<<endl;
    cout<<"Cost : "<<cost<<endl;
}
// Time complexity : O(n*logn)
// Space complexity : O(1)

void Better2(int arr[],int n){
    int cost = 0;
    unordered_map<int,int> mp;
    for(int i=0;i<n;i++){
        mp[arr[i]]++;
        cost++;
    }

    for(auto k: mp){
        if(k.second > 1){
            cout<<"Duplicate exist for "<<k.first<<endl;
            cout<<"Cost : "<<cost<<endl;
            return ;
        }
        cost++;
    }
    cout<<"No duplicates found"<<endl;
    cout<<"Cost : "<<cost<<endl;
}
// Time complexity : O(n)
// Space complexity : O(n)

// Optimized solution:
/* Assumption : Elements are positive, all are in range 0 to n-1 */
void Optimal(int arr[],int n){
    int cost=0;
    for(int i=0;i<n;i++){
        cost++;
        if(arr[abs(arr[i])] < 0){
            cout<<"Duplicate exist for "<<arr[i]<<endl;
            cout<<"Cost : "<<cost<<endl;
            return ;
        }
        else
            arr[arr[i]] = -arr[arr[i]];
    }
    cout<<"No duplicates found\n"<<endl;
    cout<<"Cost : "<<cost<<endl;
}

int main(){
    int n;
    cin>>n;

    int array[n];
    for(int i=0;i<n;i++)
        cin>>array[i];

    cout<<"Brute Force Solution\n";
    BruteForce(array,n);

    cout<<"Sorting Solution\n";
    Better1(array,n);

    cout<<"Hash Table Solution\n";
    Better2(array,n);

    cout<<"Optimal Solution with contraints\n";
    Optimal(array,n);
    
    return 0;
}
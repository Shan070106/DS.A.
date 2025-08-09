// Question:

/* Given an array of n numbers, find the element which appears maximum number of times*/

#include<iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

int BruteForce(int arr[],int n){
    int max_cnt = 0,ans;
    for(int i=0;i<n;i++){
        int cnt = 0;
        for(int j=i+1;j<n;j++){
            if(arr[i]==arr[j]){
                cnt++;
            }
        }
        if(max_cnt < cnt){
            ans = arr[i];
            cnt = 0;
        }
    }
    return ans;
}
// Time complexity : O(n^2)
// Space complexity : O(1)

int Better1(int arr[],int n){
    sort(arr,arr+n);
    int max_cnt = 0,cnt = 0, ans;
    for(int i=0;i<n-1;i++){
        if(arr[i] == arr[i+1])
            cnt++;
        else{
            ++cnt;
            if(max_cnt < cnt){
                max_cnt = cnt;
                ans = arr[i];
            }
            cnt = 0;
        }
    }
    return ans;
}
// Time complexity : O(n*logn)
// Space complexity : O(1)

int Better2(int arr[],int n){
    unordered_map<int,int> mp;
    for(int i=0;i<n;i++)
        mp[arr[i]]++;
    int max = 0, ans;
    for(auto k: mp){
        if(k.second > max){
            max = k.second;
            ans = k.first;
        }
    }
    return ans;
}
// Time complexity : O(n)
// Space complexity : O(n);

// Assumption : elements are only positive, range in between 0 to n-1
int Optimal(int arr[], int n){
    for(int i=0;i<n;i++)
        arr[arr[i]%n] += n;
    int max = 0,ans;
    for(int i=0;i<n;i++){
        if(arr[i]/n > max){
            max = arr[i]/n; 
            ans = i;
        }
    }
    return ans;
}
// Time complexity : O(n)
// Space complexity : O(1)

int main(){
    int n;
    cin>>n;

    int array[n];
    for(int i=0;i<n;i++)
        cin>>array[i];
    
    cout<<"Maximum Occurring element : "<<BruteForce(array,n)<<endl;

    cout<<"Maximum Occurring element : "<<Better1(array,n)<<endl;

    cout<<"Maximum Occurring element : "<<Better2(array,n)<<endl;

    cout<<"Maximum Occurring element index : "<<Optimal(array,n)<<endl;

    return 0;
}
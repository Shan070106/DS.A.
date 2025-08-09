#include<iostream>
using namespace std;
int main(){
    //static array
    int arr1[10] = {1,2,3,4,5};
    cout<<arr1[9]<<"\n"; // 0

    int arr2[3][4] = {1,2,3,4,5,6,7,8,9,10};
    cout<<arr2[0][2]<<' '; // 3
    cout<<arr2[1][0]<<'\n'; // 5

    // dynamic array
    int* arr3 = new int[5];
    *(arr3+1) = 100;
    cout<<arr3[0]<<' '<<arr3[1]<<' '; // 0 100

    arr3[2] = 102;
    //arr3[3] not initialized
    arr3[4] = 104;
    cout<<arr3[2]<<' '<<arr3[3]<<' '<<arr3[4]<<' '; // 102 0 104

    // accessing indices beyond the mentioned size
    arr3[5] = 105;
    //arr3[6] not initialized
    arr3[7] = 107;
    cout<<arr3[5]<<' '<<arr3[6]<<' '<<arr3[7]<<endl; // 105 59697(garbage/random value) 107

    // after using it, has to be deleted and assigned to be null pointer
    delete[] arr3;
    cout<<arr3[0]<<'\n'; // garbage/random value 
    arr3 = nullptr;

    int* arr4 = new int[3]; //leaving empty is not allowed initially
    // arr4 = {201,202,203}; is not allowed
    
    *(arr4+0) = 200;
    cout<<arr4[0]<<'\n';
    delete[] arr4;

    return 0;
}
#include <iostream>

using namespace std;
int main(int argc, char
    const * argv[]) {
    int row, col, sum;
    cout << "\n Enter Row : ";
    cin >> row;
    cout << "\n Enter Column : ";
    cin >> col;
    //creating matrix of specific size
    int arr1[row][col], arr2[row][col], multi[row][col];
    //taking input 
    cout<<"\n Enter Element in Matrix 1 : ";
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cin >> arr1[i][j];
        }
    }
    cout<<"\n Enter Element in Matrix 2 : ";
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cin >> arr2[i][j];
        }
    }
    //multiplying matrix
    for (int i = 0; i < row; i++) {
        sum = 0;
        for (int j = 0; j < col; j++) {
            for(int k = 0; k < col; k++) {
                sum += arr1[i][k] * arr2[k][j];
            }
            multi[i][j] = sum;
        }
    }
    cout<<"\n Resultant Matrix : \n";
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << multi[i][j]<<"  ";
        }
        cout << endl;
    }
    return 0;
}
#include <iostream>

using namespace std;
int main(int argc, char
    const * argv[]) {
    int size, count;
    cout << "Enter Size : ";
    cin >> size;
    //creating array of specific size
    int arr[size], frequency[size];
    //taking input
    cout << "\n Enter Array Element : ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
        frequency[i] = -1;
    }
    //traversing and counting frequency
    for (int i = 0; i < size; i++) {
        count = 1;
        for (int j = i + 1; j < size; j++) {
            if (arr[i] == arr[j]) {
                count++;
                //Preventing Counting Frequency of Same Element Multiple Time
                frequency[j] = 0;
            }
        }
        //If Frequency of Current Element is Not Counted
        if (frequency[i] != 0) {
            frequency[i] = count;
        }
    }
    for (int i = 0; i < size; i++) {
        if (frequency[i] != 0) {
            cout << "Element : " << arr[i] << " => " << frequency[i] << "\n";
        }
    }
    return 0;
}
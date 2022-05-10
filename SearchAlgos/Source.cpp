//Linear(Sequential) & Binary Search Algorithms.
#include<iostream>
using namespace std;

int LinearSequentialSearch(int num[], int n, int search) {
    for (int i = 0; i < n; i++) {
        if (num[i] == search)
            return i;
    }
    return -1;
}
int BinarySearch(int num[], int n, int search) {
    int lo = 0, hi = n - 1, mid;
    while (lo <= hi) {
        mid = (lo + hi) / 2;
        if (num[mid] > search)
            hi = mid - 1;
        else if (num[mid] < search)
            lo = mid + 1;
        else
            return mid;
    }
    return -1;
}
int main()
{
    // prints hello world 
    cout << "Hello World" << endl;
    int num [10];
        int search = 0;
        cout << "Please enter 10 sorted numbers(ascending): \n";
        for (int i = 0; i < 10; i++) {
            cin >> num[i];
        }
    cout<< "\n Enter the value you want to look for in the array: ";
        cin >> search;
        int index = BinarySearch(num, 10, search);
        if (index != -1)
            cout << endl << "The value found at index " << index << ".";

        else
            cout << "The value is not found!";
    return 0;
}

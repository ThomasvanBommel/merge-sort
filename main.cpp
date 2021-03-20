#include <iostream>
#include <vector>
#include "mergeSort.h"

using namespace std;

/** Print a vector */
template<class T>
void print(vector<T> list){
    for(auto it = list.begin(); it != list.end(); ++it) {
        cout << *it << ", ";
    } cout << endl;
}

/** Entrypoint */
int main() {
    vector<int> n {
        43, 40,  8,  5,  1, 94,  0, 15, 64, 11, 51, 79, 22, 16, 29, 86,
        27, 86, 31,  5, 21, 26, 17, 80, 53, 24, 50, 79, 32, 41, 70, 29,
        41, 72, 65, 52, 36, 27, 22, 80, 46,  1, 92, 45, 43, 57,  2, 67,
        78, 16, 27, 21, 30, 96, 18, 25, 97, 22, 91,  8, 54, 77, 26, 63
    }, *ptr = &n;

    cout << "Merge operations: " << mergeSort<int>(ptr) << endl;
    print(n);

    return 0;
}

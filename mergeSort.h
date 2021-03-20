//
// Created by thomas on 2021-03-20.
//

#ifndef MERGESORT_MERGESORT_H
#define MERGESORT_MERGESORT_H

#include <vector>

using namespace std;

/**
 * Mergesort, sorting part
 * @tparam T    - Comparable type (includes '>' & '<' operators)
 * @param list  - Unsorted vector of type T
 * @param left  - Left (starting) index of the section
 * @param middle- In-between left and right
 * @param right - Right (ending) index of the section
 * @return Operation count
 */
template<class T>
int merge(vector<T> * list, int left, int middle, int right){
    // Keep track of the number of operations
    int operations = 0;

    // Get the size of the left and right sections
    int sizeLeft  = middle - left + 1;
    int sizeRight = right - middle;

    // Temporary vectors to hold each side
    vector<T> L { };
    vector<T> R { };

    // Add the items from the left section to the left temporary vector
    for(int i = 0; i < sizeLeft; i++)
        L.push_back((*list)[left + i]), operations++;

    // Add the items from the right section to the right temporary vector
    for(int i = 0; i < sizeRight; i++)
        R.push_back((*list)[middle + 1 + i]), operations++;

    // Indices to keep track of where we are in each list (idx = main list)
    int ldx = 0, rdx = 0, idx = left;

    // Merge left and right temporary vectors back into the main list (in order)
    while(ldx < sizeLeft && rdx < sizeRight){
        // Check if left is less than right
        if(L[ldx] <= R[rdx])
            // Add left back to the main list
            (*list)[idx++] = L[ldx++];
        else
            // Add right back to the main list
            (*list)[idx++] = R[rdx++];

        // Count operations
        operations++;
    }

    // Add the remaining items from the left list
    while(ldx < sizeLeft)
        (*list)[idx++] = L[ldx++], operations++;

    // Add the remaining items from the right list
    while(rdx < sizeRight)
        (*list)[idx++] = R[rdx++], operations++;

    // Return operation count
    return operations;
}

/**
 * Mergesort, breaking into left and right sections recursively
 * @tparam T    - Comparable type (includes '>' & '<' operators)
 * @param list  - Unsorted vector of type T
 * @param left  - Where in the vector to start
 * @param right - Where in the vector to stop
 * @return Operation count
 */
template<class T>
int merge(vector<T> * list, int left, int right){
    // Ensure left is smaller then right
    if(left >= right) return 0;

    // Find the middle index
    int m = left + (right - left) /2;

    // Return operation count for the left + right sections, combine and sort both
    return merge(list, left,  m) +
           merge(list, m + 1, right) +
           merge(list, left,  m, right);
}

/**
 * Mergesort
 * @tparam T    - Comparable type (includes '>' & '<' operators)
 * @param list  - Unsorted vector of type T
 * @param left  - Where in the vector to start (-1 = from beginning)
 * @param right - Where in the vector to stop  (-1 = to the end)
 * @return Operation count
 */
template<class T>
int mergeSort(vector<T> * list, int left=-1, int right=-1){
    // Check if we should merge the entire list
    if(left == -1 && right == -1)
        return merge(list, 0, list->size() - 1);

    // Check if there is nothing to merge
    if(left == right)
        return 0;

    // Merge what we've been told to merge
    return merge(list, left, right);
}

#endif //MERGESORT_MERGESORT_H

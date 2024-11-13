#include <iostream>
#include <vector>
using namespace std;

int recursiveLastOccurrence(const vector<int>& vec, int target, int index) {
    if (index < 0) {
        return -1;  // Target not found
    }
    if (vec[index] == target) {
        return index;  // Found the last occurrence
    }
    return recursiveLastOccurrence(vec, target, index - 1);
}

int main() {
    vector<int> vec = { 1, 2, 3, 4, 2, 5, 2 };
    int target = 2;

    int lastIndex = recursiveLastOccurrence(vec, target, vec.size() - 1);
    cout << "Last occurrence of " << target << " is at index: " << lastIndex << endl;

    return 0;
}

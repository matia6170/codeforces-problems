#include <iostream>
#include <vector>



int main() {
    std::vector<int> myVector = {1, 2, 2, 3, 4, 2, 5, 4};

    int numberToRemove = 4; // Replace with the number you want to remove

    // Use std::remove to move the elements to be removed to the end of the vector
    myVector.erase(std::remove(myVector.begin(), myVector.end(), numberToRemove), myVector.end());

    // Print the updated vector
    for (int value : myVector) {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    return 0;
}

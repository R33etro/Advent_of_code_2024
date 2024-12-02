#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

bool isReportSafe(const std::pmr::vector<int>& vec1) {

    int difference = vec1.at(1) - vec1.at(0);
    bool isAscending = (difference > 0);

    // Validate the sequence
    for (size_t i = 1; i < vec1.size(); ++i) {
        int diff = vec1.at(i) - vec1.at(i - 1);
        if (std::abs(diff) > 3) return false; // Difference exceeds 3
        if (isAscending && diff <= 0) return false; // Breaks ascending order
        if (!isAscending && diff >= 0) return false; // Breaks descending order
    }
    return true;
}

bool canBeMadeSafe(const std::pmr::vector<int>& vec) {
    for (int i = 0; i < vec.size(); ++i) {
         std::pmr::vector<int> tempVec = vec; // Copy the vector
        tempVec.erase(tempVec.begin() + i); // Remove the i-th element
        if (isReportSafe(tempVec)) {
            return true; // Sequence is safe after removal
        }
    }
    return false; // Not safe even after removing one element
}

int main() {

    std::fstream input_file;
    input_file.open("C:/Users/DELL/Desktop/advent_of_code/day2/day2.txt");

    int safe_counter = 0;
    int safe_counter2 = 0;

    // checking line by line
    std::string line;
    while (std::getline(input_file, line)) {
        std::pmr::vector<int> vec1;
        std::stringstream stringstream(line);

        // parsing string line to vector of int
        do{int level; stringstream >> level; // read a single number
            vec1.push_back(level);} while (stringstream.good()); // add number to vector

        // PART 1
        // counting safe reports(lines)
        if (isReportSafe(vec1)) safe_counter++;

        //PART 2
        if (!isReportSafe(vec1)) {
            if (canBeMadeSafe(vec1)) safe_counter2++;
        } else {
            safe_counter2++;
        }
    }
    input_file.close();

    std::cout << safe_counter << std::endl; //220 - correct
    std::cout << safe_counter2 << std::endl; //296 - correct

    return 0;
}

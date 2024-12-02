#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>

int main() {

    std::fstream input_file;
    input_file.open("C:/Users/DELL/Desktop/advent_of_code/day1/day1.txt");
    int a, b, sum = 0;
    std::pmr::vector<int> tab1;
    std::pmr::vector<int> tab2;
    std::string line;
    while (std::getline(input_file, line)) {
        std::stringstream ss(line);
        ss >> a >> b;
        tab1.push_back(a);
        tab2.push_back(b);
    }
    std::sort(tab1.begin(), tab1.end());
    std::sort(tab2.begin(), tab2.end());

    for (int i = 0; i < tab1.size(); i++) {
        sum += abs(tab1[i] - tab2[i]);
    }
    input_file.close();
    return sum; //1651298 - correct
}

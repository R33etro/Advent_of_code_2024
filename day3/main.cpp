#include <iostream>
#include <fstream>
#include <string>
#include <iterator>
#include <regex>
#include <iomanip>

int part1 (std::string input) {
    // PART 1
    std::regex r1{R"(mul\(([0-9]{1,3}),([0-9]{1,3})\))"};

    auto it = std::sregex_iterator(input.begin(), input.end(), r1);
    auto end = std::sregex_iterator();
    long result = 0;
    for( ; it != end; ++it) {
        auto match = *it;
        auto element = std::stoi(match[1].str()) * std::stoi( match[2].str());
        result += element;
    }
    return result;
}

int part2 (std::string input) {
    //PART 2
    const std::regex r1{R"((mul\(([0-9]{1,3}),([0-9]{1,3})\))|do\(\)|don't\(\))"};

    auto it = std::sregex_iterator(input.begin(), input.end(), r1);
    auto end = std::sregex_iterator();

    long result = 0;
    int writable = 1;
    for( ; it != end ; ++it) {
        auto match = *it;
        if (match.str() == "don't()") {writable = 0;}
        if (match.str() == "do()") {writable = 1;}
        auto num1 = match[2].str();
        auto num2 = match[3].str();
        if (!num1.empty() && !num2.empty()) {
            auto element = std::stoi(num1) * std::stoi(num2);
            result += element*writable;
        }
    }
    return result;
}

int main() {
    std::fstream input_file;
    input_file.open("C:/Users/DELL/Desktop/advent_of_code/day3/day3.txt");

    std::string line, main_string;
    while (std::getline(input_file, line)) {
        main_string += line;
    }
    input_file.close();

    std::cout << part1(main_string) << std::endl; //166630675 - correct
    std::cout << part2(main_string) << std::endl; //93465710 - correct

    return 0;
}

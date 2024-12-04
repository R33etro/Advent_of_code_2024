#include <iostream>
#include <fstream>
int word_counter1(std::string* input, int square_length) {
    int counter = 0;

    const std::string search1 = "XMAS";
    const std::string search2 = "SAMX";

    int chunk_size = 4, i, j;
    int border = square_length - chunk_size;
    for (i = 0; i < square_length; i++) {
        for (j = 0; j < square_length; j++) {
            if (j <= border) {
                std::string chunk_horizontal = input[i].substr(j,chunk_size);
                if (chunk_horizontal == search1) {counter++; }
                if (chunk_horizontal == search2) {counter++; }
            }

            if (j <= border) {
                std::string chunk_vertical = input[j].substr(i,1) + input [j+1].at(i) + input[j+2].at(i) + input[j+3].at(i);
                if (chunk_vertical == search1) {counter++; }
                if (chunk_vertical == search2) {counter++; }
            }

            if (i <= border && j <= border) {
                std::string chunk_diagonal1 = input[i].substr(j,1) + input [i+1].at(j+1) + input[i+2].at(j+2) + input [i+3].at(j+3);
                std::string chunk_diagonal2 = input[i].substr(j+3,1) + input [i+1].at(j+2) + input[i+2].at(j+1) + input [i+3].at(j);
                if (chunk_diagonal1 == search1) {counter++; }
                if (chunk_diagonal1 == search2) {counter++; }
                if (chunk_diagonal2 == search1) {counter++; }
                if (chunk_diagonal2 == search2) {counter++; }
            }

        }
    }
    return counter;
}

int word_counter2(std::string* input, int square_length) {
    int counter = 0;

    const std::string search1 = "MASSAM";
    const std::string search2 = "MASMAS";
    const std::string search3 = "SAMSAM";
    const std::string search4 = "SAMMAS";

    int chunk_size = 3;
    int border = square_length - chunk_size;
    for (int i = 0; i <= border; i++) {
        for (int j = 0; j <= border; j++) {

            std::string chunk_diagonal1 = input[i].substr(j,1) + input [i+1].at(j+1) + input[i+2].at(j+2);
            std::string chunk_diagonal2 = input[i].substr(j+2,1) + input [i+1].at(j+1) + input[i+2].at(j);

            std::string temp = chunk_diagonal1 + chunk_diagonal2;
            if (temp == search1 || temp == search2 || temp == search3 || temp == search4) {counter++; }
        }
    }
    return counter;
}

int main() {
    std::fstream input_file;
    input_file.open("C:/Users/DELL/Desktop/advent_of_code/day4/day4.txt");

    int i = 0, square = 140;
    std::string line, input[square];
    while (std::getline(input_file, line)) {
        input[i++] = line;

    }
    input_file.close();

    std::cout << word_counter1(input, square) << std::endl; // 2591 - correct
    std::cout << word_counter2(input, square) << std::endl; // 1880 - correct
    return 0;
}

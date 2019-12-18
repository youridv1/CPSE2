#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <cctype>
#include <map>
#include <sstream>
#include <SFML/Graphics.hpp>

int main() {
    std::ifstream input("pg10.txt");
    input >> std::noskipws;
    std::vector<char> bible {
        std::istream_iterator<char>{input},
        std::istream_iterator<char>{}
    };

    std::cout << "size = " << bible.size() << std::endl;
}
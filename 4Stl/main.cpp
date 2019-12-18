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
    //1.
    std::ifstream input("pg10.txt");
    input >> std::noskipws;
    std::vector<char> bible {
        std::istream_iterator<char>{input},
        std::istream_iterator<char>{}
    };
    //2.
    std::cout << "size: " << bible.size() << std::endl;
    //3.
    std::cout << "newlines: " << std::count(bible.begin(), bible.end(), '\n') << std::endl; 
    //4.
    auto count = 0;
    std::string alpha = "abcdefghijklmnopqrstuvwxyz";
    std::for_each(alpha.begin(), alpha.end(), [&](char& c){ count += std::count(bible.begin(), bible.end(), c);} );
    std::cout << "alphabetical characters: " << count << std::endl;
    //5.
    std::for_each(bible.begin(), bible.end(), [&](char& c){c = std::tolower(c);});
    //6.
    std::map<char, int_fast32_t> index;
    std::for_each(alpha.begin(), alpha.end(), [&](const char& c) {index[c] = std::count(bible.begin(), bible.end(), c); });
    //7.1.
    std::cout << "All alphabetical characters sorted alphabetically: " << std::endl;
    std::for_each(index.begin(), index.end(), [](const auto & character){ std::cout << character.first << ": " << character.second << std::endl; });
    //7.2.
    std::map<int_fast32_t, char> valueSortedIndex;
    std::for_each(index.begin(), index.end(), [&](const auto & entry){ valueSortedIndex.insert(std::pair<int_fast32_t, char>(entry.second, entry.first)); });
    std::cout << "All alphabetical characters sorted by number of occurences: " << std::endl;
    std::for_each(valueSortedIndex.begin(), valueSortedIndex.end(), [](const auto & character){ std::cout << character.second << ": " << character.first << std::endl; });
    //8.
    std::cout << "Top 10 most frequent words: " << std::endl;
    std::map<std::string, int_fast32_t> words;
    bool word = false;
    std::string current = "";
    std::for_each(bible.begin(), bible.end(), [&](const char & c){if( c>='a' && c<='z'){word=true; current+=c;}else if(word){if(words.count(current)){words[current]++;}else{words[current] = 1;} word = false; current = "";}});
    if(word){
        if(words.count(current)){
            words[current]++;
        } else {
            words[current] = 1;
        }
        word = false;
        current = "";
    }
    std::map<int_fast32_t, std::string> occurenceWords;
    std::for_each(words.begin(), words.end(), [&](const auto & entry){ occurenceWords.insert(std::pair<int_fast32_t, std::string>(entry.second, entry.first)); });
    std::map<int_fast32_t, std::string>::reverse_iterator it;
    it = occurenceWords.rbegin();
    int_fast8_t amount = 10;
    while(amount){
        std::cout << it->second << ": " << it->first << std::endl;
        it++;
        amount--;
    }
}
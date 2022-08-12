#include <iostream>
#include <vector>
#include <string>
#include <numeric>

int main() {
    std::vector<std::string> words{ "one", "two", "three" };
    std::string allwords = accumulate(begin(words), end(words), std::string{"Words:"},
    [](std::string const& total, std::string const& s) { return total + " " + s; });
    std::cout << allwords << "\n";
}
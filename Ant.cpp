#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

int main() {
    std::ifstream f("parents.txt");
    std::vector<std::string> x;
    std::string line;
    while (std::getline(f, line)) {
        x.push_back(line);
    }
    f.close();

    std::vector<std::string> z;
    std::istringstream iss(x[0]);
    std::string word;
    while (iss >> word) {
        z.push_back(word);
    }

    int queen_numbers = std::stoi(z[0]);
    int worker_number = std::stoi(z[1]);

    std::vector<std::string> queens;
    std::vector<std::string> workers;
    for (int i = 1; i < x.size(); i++) {
        if (i < 1 + queen_numbers) {
            queens.push_back(x[i]);
        } else {
            workers.push_back(x[i]);
        }
    }

    std::vector<std::string> queens_preOrder;
    for (const auto& queen : queens) {
        for (int i = 0; i < queen.length(); i++) {
            queens_preOrder.push_back(queen.substr(0, i + 1));
        }
    }

    std::vector<std::vector<std::string>> worker_subString;
    for (const auto& worker : workers) {
        std::vector<std::string> res;
        for (int i = 0; i < worker.length(); i++) {
            for (int j = i + 1; j <= worker.length(); j++) {
                res.push_back(worker.substr(i, j - i));
            }
        }
        worker_subString.push_back(res);
    }

    std::cout << "Queens:" << std::endl;
    for (const auto& queen : queens) {
        std::cout << queen << std::endl;
    }

    std::cout << "Workers:" << std::endl;
    for (const auto& worker : workers) {
        std::cout << worker << std::endl;
    }

    std::cout << "----------------------" << std::endl;

    std::cout << "Queens PreOrder:" << std::endl;
    for (const auto& preOrder : queens_preOrder) {
        std::cout << preOrder << std::endl;
    }

    std::cout << "Worker Substrings:" << std::endl;
    for (const auto& subStrings : worker_subString) {
        for (const auto& sub : subStrings) {
            std::cout << sub << " ";
        }
        std::cout << std::endl;
    }

    std::vector<std::string> valid_children;
    for (int i = 0; i < worker_subString.size(); i++) {
        for (const auto& sub : worker_subString[i]) {
            if (std::find(queens_preOrder.begin(), queens_preOrder.end(), sub) != queens_preOrder.end()) {
                valid_children.push_back(sub);
            }
        }
    }

    std::cout << "Valid Children:" << std::endl;
    for (const auto& child : valid_children) {
        std::cout << child << std::endl;
    }

    return 0;
}

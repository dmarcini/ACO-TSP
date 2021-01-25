#include <vector>
#include <string>
#include <fstream>
#include <iostream>

#include "menu.hpp"


std::vector<std::vector<int>> load_data(const std::string &path)
{
    std::ifstream ifs(path);
    std::vector<std::vector<int>> matrix;
    int size;

    ifs >> size;

    matrix.resize(size);

    for (int i {0}; i < size; ++i) {
        matrix[i].resize(size);

        for (int j {0}; j < size; ++j) {
            std::string element {};

            ifs >> element;

            matrix[i][j] = std::stoi(element);         
        }
    }

    return matrix;
}

int main() {
    utility::Menu menu("\nTraveling Salesman Problem - Ant Colony Optimization");

    bool was_data_loaded {false};

    menu.append({"Load data", [&was_data_loaded]() {
        
    }});
    menu.append({"Enter stop criterium", []() {
        
    }});
    menu.append({"Enter algorithm parameters", []() {
        
    }});
    menu.append({"Start", [&was_data_loaded]() {
        if (!was_data_loaded) {
            std::cout << "\nFirst load data!\n";
            return;
        }
    }});

    menu.show();
}
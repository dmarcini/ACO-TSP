#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <utility>

#include "menu.hpp"

#include "ant_colony_optimization.hpp"


std::vector<std::vector<int>> load_data(const std::string &path)
{
    std::ifstream ifs(path);
    std::vector<std::vector<int>> matrix;
    int size;

    ifs >> size;

    for (int i {0}; i < size; ++i) {
        matrix.push_back({});

        for (int j {0}; j < size; ++j) {
            int value;

            ifs >> value;

            matrix[i].push_back(value);         
        }
    }

    return matrix;
}

int main() {
    AntColonyOptimization aco;

    utility::Menu menu("\nTraveling Salesman Problem - "
                       "Ant Colony Optimization");

    bool was_data_loaded {false};

    menu.append({"Load data", [&aco, &was_data_loaded]() { 
        aco.load_data("graphs/ftv47.atsp", load_data);
        
        was_data_loaded = true;
    }});
    menu.append({"Enter stop criterium", [&aco]() {
        aco.enter_stop_criterium();
    }});
    menu.append({"Enter algorithm parameters", [&aco]() {
        aco.enter_algorithm_parameters();
    }});
    menu.append({"Start", [&aco, &was_data_loaded]() {
        if (!was_data_loaded) {
            std::cout << "\nFirst load data!\n";
            return;
        }

        aco.start();
    }});

    menu.show();
}

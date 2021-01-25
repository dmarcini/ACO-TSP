#include "graph.hpp"

#include <utility>
#include <iostream>

#include "params.hpp"


void Graph::load(const std::vector<std::vector<int>> &matrix)
{
    for (size_t i {0}; i < matrix.size(); ++i) {
        edges_.push_back({});

        for (size_t j {0}; j < matrix.size(); ++j) {
            edges_[i].push_back(Edge(matrix[i][j], Params::tau0));
        }

        path_.route().push_back(i);
    }
}


void Graph::print_path()
{
    std::cout << "Visited cities:\n";
    std::cout << path_.route()[0];

    for (size_t i {1}; i < path_.route().size(); ++i) {
        std::cout << " -> " << path_.route()[i];
    }

    std::cout << "\nPath length: " << path_.length() << "\n\n";
}

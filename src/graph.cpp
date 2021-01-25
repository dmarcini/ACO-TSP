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

        path_.push_back(i);
    }
}


void Graph::print_path()
{
    std::cout << "Visited cities:\n";
    std::cout << path_[0];

    for (size_t i {1}; i < path_.size(); ++i) {
        std::cout << " -> " << path_[i];
    }

    std::cout << "\nPath length: " << path_length_ << "\n\n";
}

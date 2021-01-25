#ifndef GRAPH_HPP_
#define GRAPH_HPP_

#include <vector>
#include <iostream>
#include <limits>


class Graph
{
public:
    class Edge;

    void load(const std::vector<std::vector<int>> &matrix);

    size_t size() { return edges_.size(); }

    std::vector<int>& path() { return path_; }
    int& path_length() { return path_length_; }

    Edge& edge(size_t x, size_t y) { return edges_[x][y]; }

    void print_path();
private:
    std::vector<std::vector<Edge>> edges_;
    std::vector<int> path_;

    int path_length_ {std::numeric_limits<int>::max()};
};


class Graph::Edge
{
public:
    Edge(int distance, double pheromones_concentration)
        : distance_(distance),
          pheromones_concentration_(pheromones_concentration) {}

    int& distance() { return distance_; }
    double& pheromones_concentration() { return pheromones_concentration_; }

    void update_pheromones_concentration(double rho)
    {
        // amount of pheromone deposited per unit edge length
        double tau {pheromones_concentration_ / distance_};

        pheromones_concentration_ = rho * pheromones_concentration_ + tau;
    }
private:
    int distance_;
    double pheromones_concentration_;
};


#endif // GRAPH_HPP_

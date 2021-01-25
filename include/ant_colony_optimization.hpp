#ifndef ANT_COLONY_OPTIMIZATION_HPP_
#define ANT_COLONY_OPTIMIZATION_HPP_

#include <string>
#include <vector>
#include <functional>

#include "graph.hpp"
#include "ant.hpp"


using ACO = class AntColonyOptimization;

class AntColonyOptimization
{
public:
    using LoadDataFcntPtr = 
        std::function<std::vector<std::vector<int>>(const std::string&)>;

    void load_data(const std::string &path, LoadDataFcntPtr load_data);

    void enter_stop_criterium();
    void enter_algorithm_parameters();

    void start();
private:
    void do_iteration();

    void update_initial_pheromones_concentration();
    void update_pheromones_concentration();

    double get_double_parameter(std::string_view param);
    int get_int_parameter(std::string_view param);

    Graph graph_;
    std::vector<Ant> ants_;
};

#endif // ANT_COLONY_OPTIMIZATION_HPP_

#include "ant_colony_optimization.hpp"

#include <string>
#include <utility>
#include <iostream>

#include "scanner.hpp"

#include "ant.hpp"
#include "params.hpp"


void AntColonyOptimization::load_data(const std::string &path,
                                      LoadDataFcntPtr load_data)
{
    graph_.load(load_data(path));

    for (size_t i {0}; i < graph_.size(); ++i) {
        ants_.push_back(Ant(graph_));
    }
}


void AntColonyOptimization::enter_stop_criterium()
{
    Params::iterations_number = get_int_parameter("iterations number");
}


void AntColonyOptimization::enter_algorithm_parameters()
{
    Params::tau0 = get_double_parameter("initial concentration of pheromones");
    Params::rho = get_double_parameter("pheromones evaporation factor");
    Params::q = get_double_parameter("number of pheromones"
                                     " spread over 1 edge");
    Params::alpha = get_int_parameter("parameter regulating the influence"
                                      " of pheromone concentration on"
                                      " the selection of the next city");
    Params::beta = get_int_parameter("parameter regulating the influence"
                                     " of the local value of the criterion"
                                     " function on the selection"
                                     " of the next city");

    update_initial_pheromones_concentration();
}


void AntColonyOptimization::start()
{
    for (int i {0}; i < Params::iterations_number; ++i) {
        do_iteration();
        update_pheromones_concentration();
    }

    graph_.print_path();
}


void AntColonyOptimization::do_iteration()
{
    for (auto &ant : ants_) {
        ant.do_cycle();
    }
}


void AntColonyOptimization::update_initial_pheromones_concentration()
{
    for (size_t i {0}; i < graph_.size(); ++i) {
        for (size_t j {0}; j < graph_.size(); ++j) {
            graph_.edge(i, j).pheromones_concentration() = Params::tau0;
        } 
    }
}


void AntColonyOptimization::update_pheromones_concentration()
{
    for (size_t i {0}; i < graph_.size() - 1; ++i) {
        graph_.edge(i, i + 1).update_pheromones_concentration(Params::rho);
    }
}


double AntColonyOptimization::get_double_parameter(std::string_view parameter)
{
    utility::Scanner scanner(std::cin);

    std::cout << "Enter " << parameter << ": ";

    while (!scanner.has_next_double()) {
        std::cout << parameter << " have to be double!\n";
        std::cout << "Enter " << parameter << ": ";
    }

    return scanner.next_double();
}


int AntColonyOptimization::get_int_parameter(std::string_view parameter)
{
    utility::Scanner scanner(std::cin);

    std::cout << "Enter " << parameter << ": ";

    while (!scanner.has_next_int()) {
        std::cout << parameter << " have to be integer!\n";
        std::cout << "Enter " << parameter << ": ";
    }

    return scanner.next_int();
}

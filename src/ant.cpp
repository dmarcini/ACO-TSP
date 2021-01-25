#include <cmath>

#include "ant.hpp"
#include "graph.hpp"

#include "rand.hpp"

#include "params.hpp"


Ant::Ant(Graph &graph)
    : graph_(graph)
{
    clear_cycle();
}


void Ant::do_cycle()
{
    for (size_t i {0}; i < graph_.size() - 1; ++i) {
        next_city();
    }
}


void Ant::next_city()
{
    int city = get_next_city();
    int distance = graph_.edge(last_city_, city).distance();

    visited_cities_.push_back(city);

    graph_.edge(last_city_, city).pheromones_concentration() += 
        Params::q / distance;

    current_path_ += distance;
    last_city_ = city;

    if (visited_cities_.size() != graph_.size()) {
        return;
    }

    current_path_ += graph_.edge(last_city_, start_city_).distance();

    visited_cities_.push_back(start_city_);

    if (graph_.path_length() > current_path_) {
        graph_.path_length() = current_path_;
        graph_.path() = visited_cities_;
    }

    clear_cycle();
}

int Ant::get_next_city()
{
    int city {-1};
    // probibility of choosing of the city;
    double p {0.};

    for (auto cur_city : graph_.path()) {
        if (was_city_visited(cur_city)) {
            continue;
        }

        auto numerator {count_probability_numerator(cur_city)};
        auto denumerator {count_probability_denumerator()};

        auto cur_p = numerator / denumerator;

        if (cur_p >= p) {
            city = cur_city;
            p = cur_p;
        }
    }

    return city;
}


double Ant::count_probability_numerator(int city)
{
    double pheromones_concentration {
        graph_.edge(last_city_, city).pheromones_concentration()
    };
    // value of the local criterion function
    double eta {1. / graph_.edge(last_city_, city).distance()};

    auto numerator {
        std::pow(pheromones_concentration, Params::alpha) *
        std::pow(eta, Params::beta)
    };

    return numerator;
}


double Ant::count_probability_denumerator()
{
    double denumerator {0.};

    for (auto city : graph_.path()) {
        if (was_city_visited(city)) {
            continue;
        }

        auto distance {graph_.edge(last_city_, city).distance()};

        denumerator += 
            std::pow(distance, Params::alpha) *
            std::pow(distance, Params::beta);
    }

    return denumerator;
}


void Ant::clear_cycle()
{
    current_path_ = 0;
    start_city_ = utility::rand(0, graph_.size() - 1);
    last_city_ = start_city_;
    visited_cities_.clear();

    visited_cities_.push_back(last_city_);
}


bool Ant::was_city_visited(int city)
{
    for (auto visited_city : visited_cities_) {
        if (city == visited_city) {
            return true;
        }
    }

    return false;
}

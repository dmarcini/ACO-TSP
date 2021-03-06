#ifndef ANT_HPP_
#define ANT_HPP_

#include <vector>

#include "graph.hpp"


class Ant
{
public:
    Ant(Graph &graph);

    std::vector<int> route() { return route_; }

    void do_cycle();
private:
    void next_city();
    void clear_cycle();

    int get_next_city();

    bool was_city_visited(int city);

    double count_probability_numerator(int city);
    double count_probability_denumerator();

    Graph &graph_;
    std::vector<int> route_;

    int start_city_;
    int last_city_;
    int current_path_length_;
};

#endif // ANT_HPP_

#ifndef PATH_HPP_
#define PATH_HPP_

#include <vector>
#include <limits>


class Path
{
public:
    std::vector<int>& route() { return route_; }
    int& length() { return length_; }
private:
    std::vector<int> route_;
    int length_ {std::numeric_limits<int>::max()};
};


#endif // PATH_HPP

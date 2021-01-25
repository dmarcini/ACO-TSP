#ifndef PARAMS_HPP_
#define PARAMS_HPP_


class Params
{
public:
    // pheromones evaporation factor
    static double rho;
    // parameter regulating the influence of pheromone
    // concentration on the selection of the next city
    static int alpha;
    // parameter regulating the influence of the local value of the criterion
    // function on the selection of the next city
    static int beta;
    // initial concentration of pheromones
    static double tau0;
    // number of pheromones spread over 1 edge
    static double q;
};

double Params::rho = 0.5;
int Params::alpha = 1;
int Params::beta = 3;
double Params:: tau0 = 0.2;
double Params::q = 0.5;


#endif // PARAMS_HPP_

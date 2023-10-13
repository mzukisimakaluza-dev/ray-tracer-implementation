#include "tuple_helpers.hpp"

namespace tracer
{
namespace factory
{
bool is_point(const std::tuple<double, double, double, double> &my_tuple)
{
    return std::get<3>(my_tuple) == 1.0;
}
bool is_vector(const std::tuple<double, double, double, double> &my_tuple)
{
    return std::get<3>(my_tuple) == 0.0;
}

std::tuple<double, double, double, double> point(double x, double y, double z)
{
    return std::make_tuple(x, y, z, 1);
}

std::tuple<double, double, double, double> vector(double x, double y, double z)
{
    return std::make_tuple(x, y, z, 0);
}

// TODO: Find way to templetize this so it works with variable different types ()
// TODO: Extend this to work with variable tuple sizes not just 4 elements
std::tuple<double, double, double, double> add_tuples(const std::tuple<double, double, double, double> &tuple_1, const std::tuple<double, double, double, double> &tuple_2)
{
    return std::make_tuple(std::get<0>(tuple_1) + std::get<0>(tuple_2),
                            std::get<1>(tuple_1) + std::get<1>(tuple_2),
                            std::get<2>(tuple_1) + std::get<2>(tuple_2),
                            std::get<3>(tuple_1) + std::get<3>(tuple_2)
    );
}
} // namespace factory
} // namespace tracer
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
} // namespace factory
} // namespace tracer
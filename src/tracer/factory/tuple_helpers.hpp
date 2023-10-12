#ifndef TUPLE_HELPERS_HPP
#define TUPLE_HELPERS_HPP

#include <tuple>

namespace tracer
{
namespace factory
{
bool is_point(const std::tuple<double, double, double, double> &my_tuple);
bool is_vector(const std::tuple<double, double, double, double> &my_tuple);
} // namespace factory
} // namespace tracer

#endif
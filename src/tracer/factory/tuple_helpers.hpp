#ifndef TUPLE_HELPERS_HPP
#define TUPLE_HELPERS_HPP

#include <tuple>
#include <functional>

namespace tracer
{
namespace factory
{
bool is_point(const std::tuple<double, double, double, double> &my_tuple);
bool is_vector(const std::tuple<double, double, double, double> &my_tuple);

std::tuple<double, double, double, double> point(double x, double y, double z);
std::tuple<double, double, double, double> vector(double x, double y, double z);

std::tuple<double, double, double, double> add_tuples(const std::tuple<double, double, double, double> &tuple_1, const std::tuple<double, double, double, double> &tuple_2);


} // namespace factory
} // namespace tracer

#endif
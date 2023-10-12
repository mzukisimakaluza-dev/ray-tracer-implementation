#ifndef TUPLE_HELPERS_HPP
#define TUPLE_HELPERS_HPP

#include <tuple>

namespace tracer
{
namespace factory
{
bool is_point(const std::tuple<double, double, double, double> &my_tuple);
bool is_vector(const std::tuple<double, double, double, double> &my_tuple);

std::tuple<double, double, double, double> point(double x, double y, double z);
std::tuple<double, double, double, double> vector(double x, double y, double z);

// NB: Not to be called directly by user, it's a helper
template <std::size_t... I, typename... Ts>
auto add_tuples(const std::tuple<Ts...>& tuple_1, const std::tuple<Ts...>& tuple_2, std::index_sequence<I...>);

template <typename... Ts>
auto add_tuples(const std::tuple<Ts...>& tuple_1, const std::tuple<Ts...>& tuple_2);


} // namespace factory
} // namespace tracer

#endif
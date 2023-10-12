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

// NB: Not to be called directly by user, it's a helper
template <std::size_t... I, typename... Ts>
auto tuple_add(const std::tuple<Ts...>& tuple_1, const std::tuple<Ts...>& tuple_2, std::index_sequence<I...>) {
    return std::make_tuple(std::get<I>(tuple_1) + std::get<I>(tuple_2)...);
}

template <typename... Ts>
auto tuple_add(const std::tuple<Ts...>& tuple_1, const std::tuple<Ts...>& tuple_2) {
    return tuple_add(tuple_1, tuple_2, std::index_sequence_for<Ts...>());
}
} // namespace factory
} // namespace tracer
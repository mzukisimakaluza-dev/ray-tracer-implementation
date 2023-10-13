#ifndef TUPLE_HELPERS_HPP
#define TUPLE_HELPERS_HPP

#include <tuple>
#include <cmath>

namespace tracer
{
namespace factory
{
bool is_point(const std::tuple<double, double, double, double> &my_tuple);
bool is_vector(const std::tuple<double, double, double, double> &my_tuple);

std::tuple<double, double, double, double> point(double x, double y, double z);
std::tuple<double, double, double, double> vector(double x, double y, double z);

std::tuple<double, double, double, double> add_tuples(const std::tuple<double, double, double, double> &tuple_1, const std::tuple<double, double, double, double> &tuple_2);
std::tuple<double, double, double, double> negate_tuple(const std::tuple<double, double, double, double> &tuple);
double magnitude(const std::tuple<double, double, double, double> &tuple);

std::tuple<double, double, double, double> normalize(const std::tuple<double, double, double, double> &vector);
double dot(const std::tuple<double, double, double, double> &vector_1, const std::tuple<double, double, double, double> &vector_2);
std::tuple<double, double, double, double> cross(const std::tuple<double, double, double, double> &vector_1, const std::tuple<double, double, double, double> &vector_2);

std::tuple<double, double, double, double> operator*(const std::tuple<double, double, double, double> &tuple, double scaler);
std::tuple<double, double, double, double> operator/(const std::tuple<double, double, double, double> &tuple, double scaler);

std::tuple<double, double, double, double> subtract_points(const std::tuple<double, double, double, double> &point_1, const std::tuple<double, double, double, double> &point_2);
std::tuple<double, double, double, double> subtract_vector_from_point(const std::tuple<double, double, double, double> &point, const std::tuple<double, double, double, double> &vector);
std::tuple<double, double, double, double> subtract_vectors(const std::tuple<double, double, double, double> &vector_1, const std::tuple<double, double, double, double> &vector_2);

} // namespace factory
} // namespace tracer

#endif
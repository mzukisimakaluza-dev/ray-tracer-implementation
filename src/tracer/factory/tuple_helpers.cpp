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

std::tuple<double, double, double, double> negate_tuple(const std::tuple<double, double, double, double> &tuple)
{
    return std::make_tuple(std::get<0>(tuple) * -1,
                            std::get<1>(tuple) * -1,
                            std::get<2>(tuple) * -1,
                            std::get<3>(tuple) * -1
    );
}

double magnitude(const std::tuple<double, double, double, double> &tuple)
{
    return std::sqrt((std::pow(std::get<0>(tuple), 2) + std::pow(std::get<1>(tuple), 2) + std::pow(std::get<2>(tuple), 2) + std::pow(std::get<3>(tuple), 2)));
}

std::tuple<double, double, double, double> normalize(const std::tuple<double, double, double, double> &vector)
{
    auto _magnitude = magnitude(vector);
    return std::make_tuple(std::get<0>(vector)/_magnitude, std::get<1>(vector)/_magnitude, std::get<2>(vector)/_magnitude, std::get<3>(vector)/_magnitude);
}

double dot(const std::tuple<double, double, double, double> &vector_1, const std::tuple<double, double, double, double> &vector_2)
{
    return (std::get<0>(vector_1) * std::get<0>(vector_2) +
            std::get<1>(vector_1) * std::get<1>(vector_2) +
            std::get<2>(vector_1) * std::get<2>(vector_2) +
            std::get<3>(vector_1) * std::get<3>(vector_2)
    );
}

std::tuple<double, double, double, double> cross(const std::tuple<double, double, double, double> &vector_1, const std::tuple<double, double, double, double> &vector_2)
{
    return vector(std::get<1>(vector_1)*std::get<2>(vector_2) - std::get<2>(vector_1)*std::get<1>(vector_2),
                std::get<2>(vector_1)*std::get<0>(vector_2) - std::get<0>(vector_1)*std::get<2>(vector_2),
                std::get<0>(vector_1)*std::get<1>(vector_2) - std::get<1>(vector_1)*std::get<0>(vector_2)
    );
}

std::tuple<double, double, double, double> operator*(const std::tuple<double, double, double, double> &tuple, double scaler)
{
    return std::make_tuple<double, double, double, double>(std::get<0>(tuple) * scaler, std::get<1>(tuple) * scaler, std::get<2>(tuple) * scaler, std::get<3>(tuple) * scaler);
}

std::tuple<double, double, double, double> operator/(const std::tuple<double, double, double, double> &tuple, double scaler)
{
    return std::make_tuple<double, double, double, double>(std::get<0>(tuple) / scaler, std::get<1>(tuple) / scaler, std::get<2>(tuple) / scaler, std::get<3>(tuple) / scaler);
}

std::tuple<double, double, double, double> subtract_points(const std::tuple<double, double, double, double> &point_1, const std::tuple<double, double, double, double> &point_2)
{
        return std::make_tuple(std::get<0>(point_1) - std::get<0>(point_2),
                            std::get<1>(point_1) - std::get<1>(point_2),
                            std::get<2>(point_1) - std::get<2>(point_2),
                            std::get<3>(point_1) - std::get<3>(point_2)
    );
}

std::tuple<double, double, double, double> subtract_vector_from_point(const std::tuple<double, double, double, double> &point, const std::tuple<double, double, double, double> &vector)
{
        return std::make_tuple(std::get<0>(point) - std::get<0>(vector),
                            std::get<1>(point) - std::get<1>(vector),
                            std::get<2>(point) - std::get<2>(vector),
                            std::get<3>(point) - std::get<3>(vector)
    );
}

std::tuple<double, double, double, double> subtract_vectors(const std::tuple<double, double, double, double> &vector_1, const std::tuple<double, double, double, double> &vector_2)
{
        return std::make_tuple(std::get<0>(vector_1) - std::get<0>(vector_2),
                            std::get<1>(vector_1) - std::get<1>(vector_2),
                            std::get<2>(vector_1) - std::get<2>(vector_2),
                            std::get<3>(vector_1) - std::get<3>(vector_2)
    );
}
} // namespace factory
} // namespace tracer
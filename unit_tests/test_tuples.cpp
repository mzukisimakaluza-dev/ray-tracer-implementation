#include "doctest.h"
#include "tracer_common.hpp"
#include "tuple_helpers.hpp"

SCENARIO("A tuple with w=1.0 is a point")
{
    GIVEN("A tuple a")
    {
        std::tuple<double, double, double, double> a = std::make_tuple(4.3, -4.2, 3.1, 1.0);
        WHEN("Accessing the tuple values")
        {
            THEN("The tuple values must be what is expected")
            {
                REQUIRE(std::get<0>(a) == 4.3);
                REQUIRE(std::get<1>(a) == -4.2);
                REQUIRE(std::get<2>(a) == 3.1);
                REQUIRE(std::get<3>(a) == 1.0);

                REQUIRE(tracer::factory::is_point(a) == true);
                REQUIRE(tracer::factory::is_vector(a) == false);
            }
        }
    }
}

SCENARIO("A tuple with w=0 is a vector")
{
    GIVEN("A tuple a")
    {
        std::tuple<double, double, double, double> a = std::make_tuple(4.3, -4.2, 3.1, 0.0);
        WHEN("Accessing the tuple values")
        {
            THEN("The tuple values must be what is expected")
            {
                REQUIRE(std::get<0>(a) == 4.3);
                REQUIRE(std::get<1>(a) == -4.2);
                REQUIRE(std::get<2>(a) == 3.1);
                REQUIRE(std::get<3>(a) == 0.0);

                REQUIRE(tracer::factory::is_point(a) == false);
                REQUIRE(tracer::factory::is_vector(a) == true);
            }
        }
    }
}

SCENARIO("point() function creates a tuple with w=1")
{
    GIVEN("A point p with x,y,z")
    {
        std::tuple<double, double, double, double> p = tracer::factory::point(4, -4, 3);

        THEN("p must equate the tuple (4, -4, 3, 1)")
        {
            REQUIRE(p == std::make_tuple(4, -4, 3, 1));
        }
    }
}

SCENARIO("vector() function creates a tuple with w=0")
{
    GIVEN("A point p with x,y,z")
    {
        std::tuple<double, double, double, double> p = tracer::factory::vector(4, -4, 3);

        THEN("p must equate the tuple (4, -4, 3, 0)")
        {
            REQUIRE(p == std::make_tuple(4, -4, 3, 0));
        }
    }
}

SCENARIO("Adding two tuples")
{
    GIVEN("a1 and a2")
    {
        std::tuple<double, double, double, double> a1(3, -2, 5, 1);
        std::tuple<double, double, double, double> a2(-2, 3, 1, 0);

        THEN("a1 + a2 must equate the sum of individual corresponding values")
        {
            auto sum = tracer::factory::add_tuples(a1, a2);
            REQUIRE(sum == std::make_tuple(1, 1, 6, 1));
        }
    }
}

SCENARIO("Subtracting two points")
{
    GIVEN("p1 and p2")
    {
        std::tuple<double, double, double, double> p1 = tracer::factory::point(3, 2, 1);
        std::tuple<double, double, double, double> p2 = tracer::factory::point(5, 6, 7);

        THEN("p1 - p2 must equate vector(-2, -4, -6)")
        {
            REQUIRE(tracer::factory::subtract_points(p1, p2) == tracer::factory::vector(-2, -4, -6));
        }
    }
}

SCENARIO("Subtracting two points")
{
    GIVEN("p1 and p2")
    {
        std::tuple<double, double, double, double> p = tracer::factory::point(3, 2, 1);
        std::tuple<double, double, double, double> v = tracer::factory::vector(5, 6, 7);

        THEN("p - v must equate point(-2, -4, -6)")
        {
            REQUIRE(tracer::factory::subtract_vector_from_point(p, v) == tracer::factory::point(-2, -4, -6));
        }
    }
}

SCENARIO("Subtracting two vectors")
{
    GIVEN("v1 and v2")
    {
        std::tuple<double, double, double, double> v1 = tracer::factory::vector(3, 2, 1);
        std::tuple<double, double, double, double> v2 = tracer::factory::vector(5, 6, 7);

        THEN("v1 - v2 must equate vector(-2, -4, -6)")
        {
            REQUIRE(tracer::factory::subtract_vectors(v1, v2) == tracer::factory::vector(-2, -4, -6));
        }
    }
}

SCENARIO("Subtracting a vector from the zero vector")
{
    GIVEN("zero vector(0, 0, 0) and v vector(-1, 2, -3)")
    {
        std::tuple<double, double, double, double> zero = tracer::factory::vector(0, 0, 0);
        std::tuple<double, double, double, double> v = tracer::factory::vector(1, -2, 3);
        
        THEN("zero -v must equate vector(-1, 2, -3)")
        {
            REQUIRE(tracer::factory::subtract_vectors(zero, v) == tracer::factory::vector(-1, 2, -3));
        }
    }
}

SCENARIO("Negating a tuple")
{
    GIVEN("a as tuple (1, -2, 3, -4)")
    {
        std::tuple<double, double, double, double> a(1, -2, 3, -4);

        THEN("-a must equate tuple (-1, 2, -3, 4)")
        {
            REQUIRE(tracer::factory::negate_tuple(a) == std::make_tuple<double, double, double, double>(-1, 2, -3, 4));
        }
    }
}

SCENARIO("Multiplying a tuple by a scaler")
{
    GIVEN("a as tuple(1, -2, 3, -4)")
    {
        std::tuple<double, double, double, double> a(1, -2, 3, -4);
        THEN("a * 3.5 must equate tuple(3.5, -7, 10.5, -14) and a * 0.5 tuple(0.5, -1, 1.5, -2)")
        {
            using namespace tracer::factory;
            REQUIRE(a * 3.5 == std::make_tuple<double, double, double, double>(3.5, -7, 10.5, -14));
            REQUIRE(a * 0.5 == std::make_tuple<double, double, double, double>(0.5, -1, 1.5, -2));
        }
    }
}

SCENARIO("Dividing a tuple by a scalar")
{
    GIVEN("a as tuple(1, -2, 3, -4)")
    {
        std::tuple<double, double, double, double> a(1, -2, 3, -4);
        THEN("a / 2 must equate tuple(0.5, -1, 1.5, -2)")
        {
            using namespace tracer::factory;
            REQUIRE(a / 2 == std::make_tuple<double, double, double, double>(0.5, -1, 1.5, -2));
        }
    }
}

SCENARIO("Computing the magnitude of vectors (1,0,0), (0,1,0), (0,0,1), (1,2,3), (-1,-2,-3)")
{
    GIVEN("v1, v2, v3, v4, v5 as vectors (1,0,0), (0,1,0), (0,0,1), (1,2,3), (-1,-2,-3) respectively")
    {
        auto v1 = tracer::factory::vector(1, 0, 0);
        auto v2 = tracer::factory::vector(0, 1, 0);
        auto v3 = tracer::factory::vector(0, 0, 1);
        auto v4 = tracer::factory::vector(1, 2, 3);
        auto v5 = tracer::factory::vector(-1, -2, -3);

        THEN("magnitude(v1) = 1")
        {
            std::cout << tracer::factory::magnitude(v1) << "\n";
            REQUIRE(tracer::factory::magnitude(v1) == 1);
        }
        THEN("magnitude(v2) = 1")
        {
            REQUIRE(tracer::factory::magnitude(v2) == 1);
        }
        THEN("magnitude(v3) = 1")
        {
            REQUIRE(tracer::factory::magnitude(v3) == 1);
        }
        THEN("magnitude(v4) = sqrt(14)")
        {
            REQUIRE(tracer::factory::magnitude(v4) == std::sqrt(14));
        }
        THEN("magnitude(v5) = sqrt(14)")
        {
            REQUIRE(tracer::factory::magnitude(v5) == std::sqrt(14));
        }
    }
}

SCENARIO("Normalizing vector(4, 0, 0) gives (1, 0, 0)")
{
    GIVEN("v as vector(4, 0, 0)")
    {
        auto v = tracer::factory::vector(4, 0, 0);
        THEN("normalize(v) == vector(1, 0, 0)")
        {
            REQUIRE(tracer::factory::normalize(v) == tracer::factory::vector(1, 0, 0));
        }
    }
}

SCENARIO("Normalizing vector(1, 2, 3)")
{
    GIVEN("v as vector(1, 2, 3)")
    {
        auto v = tracer::factory::vector(1, 2, 3);
        THEN("normalize(v) == vector(1, 0, 0)")
        {
            REQUIRE(tracer::factory::normalize(v) == tracer::factory::vector(1/std::sqrt(14), 2/std::sqrt(14), 3/std::sqrt(14)));
        }
    }
}

SCENARIO("The magnitude of a normalized vector")
{
    GIVEN("v as vector(1, 2, 3)")
    {
        auto v = tracer::factory::vector(1, 2, 3);
        WHEN("norm = normalize(v)")
        {
            auto norm = tracer::factory::normalize(v);
            THEN("maginitude(norm) == 1")
            {
                REQUIRE(tracer::factory::magnitude(norm) == 1);
            }
        }
    }
}

SCENARIO("The dot product of two tuples")
{
    GIVEN("a as vector(1, 2, 3) and b as vector(2, 3, 4)")
    {
        auto a = tracer::factory::vector(1, 2, 3);
        auto b = tracer::factory::vector(2, 3, 4);
        THEN("dot(a, b) == 20")
        {
            REQUIRE(tracer::factory::dot(a, b) == 20);
        }
    }
}

SCENARIO("The cross product of two vectors")
{
    GIVEN("a as vector(1, 2, 3) and b as vector(2, 3, 4)")
    {
        auto a = tracer::factory::vector(1, 2, 3);
        auto b = tracer::factory::vector(2, 3, 4);
        THEN("cross(a, b) == vector(-1, 2, -1) and cross(b, a) == vector(1, -2, 1)")
        {
            REQUIRE(tracer::factory::cross(a, b) == tracer::factory::vector(-1, 2, -1));
            REQUIRE(tracer::factory::cross(b, a) == tracer::factory::vector(1, -2, 1));
        }
    }   
}
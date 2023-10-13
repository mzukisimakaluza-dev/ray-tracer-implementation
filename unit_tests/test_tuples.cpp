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
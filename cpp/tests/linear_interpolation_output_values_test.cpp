#include "linear_interpolation.hpp"
#include "linear_interpolation_base.hpp"
#include <gtest/gtest.h>
#include <tuple>

class LinearInterpolationBoundaryOutputTest : public LinearInterpolationTestConstants,
                                              public ::testing::Test {
};

TEST_F(LinearInterpolationBoundaryOutputTest, X1ReturnsY1)
{
    ASSERT_EQ(y1, linear_interpolation(x1, x2, y1, y2, x1));
}

TEST_F(LinearInterpolationBoundaryOutputTest, X2ReturnsY2)
{
    ASSERT_EQ(y2, linear_interpolation(x1, x2, y1, y2, x2));
}

class LinearInterpolationOutputTestFixture
    : public ::testing::TestWithParam<
          std::tuple<LinearInterpolationTestConstants, double, double>> {
};

TEST_P(LinearInterpolationOutputTestFixture, ExpectedValueReturned)
{
    auto const test_constants = std::get<0>(GetParam());
    double const x = std::get<1>(GetParam());
    double const expected_y = std::get<2>(GetParam());

    ASSERT_DOUBLE_EQ(expected_y,
        linear_interpolation(
            test_constants.x1, test_constants.x2, test_constants.y1, test_constants.y2, x));
}

INSTANTIATE_TEST_SUITE_P(LinearInterpolationIdOutputTest, LinearInterpolationOutputTestFixture,
    ::testing::Values(std::make_tuple(LinearInterpolationTestConstants {}, 0.1, 0.1),
        std::make_tuple(LinearInterpolationTestConstants {}, 0.2, 0.2),
        std::make_tuple(LinearInterpolationTestConstants {}, 0.5, 0.5),
        std::make_tuple(LinearInterpolationTestConstants {}, 0.8, 0.8),
        std::make_tuple(LinearInterpolationTestConstants {}, 0.9, 0.9)));

INSTANTIATE_TEST_SUITE_P(LinearInterpolationNegIdOutputTest, LinearInterpolationOutputTestFixture,
    ::testing::Values(
        std::make_tuple(LinearInterpolationTestConstants { 0.0, 1.0, 1.0, 0.0 }, 0.1, 0.9),
        std::make_tuple(LinearInterpolationTestConstants { 0.0, 1.0, 1.0, 0.0 }, 0.2, 0.8),
        std::make_tuple(LinearInterpolationTestConstants { 0.0, 1.0, 1.0, 0.0 }, 0.5, 0.5),
        std::make_tuple(LinearInterpolationTestConstants { 0.0, 1.0, 1.0, 0.0 }, 0.8, 0.2),
        std::make_tuple(LinearInterpolationTestConstants { 0.0, 1.0, 1.0, 0.0 }, 0.9, 0.1)));

INSTANTIATE_TEST_SUITE_P(LinearInterpolationSlope2OutputTest, LinearInterpolationOutputTestFixture,
    ::testing::Values(
        std::make_tuple(LinearInterpolationTestConstants { 0.0, 1.0, 0.0, 2.0 }, 0.1, 0.2),
        std::make_tuple(LinearInterpolationTestConstants { 0.0, 1.0, 0.0, 2.0 }, 0.2, 0.4),
        std::make_tuple(LinearInterpolationTestConstants { 0.0, 1.0, 0.0, 2.0 }, 0.5, 1.0),
        std::make_tuple(LinearInterpolationTestConstants { 0.0, 1.0, 0.0, 2.0 }, 0.8, 1.6),
        std::make_tuple(LinearInterpolationTestConstants { 0.0, 1.0, 0.0, 2.0 }, 0.9, 1.8)));

INSTANTIATE_TEST_SUITE_P(LinearInterpolationSlopeNeg2OutputTest,
    LinearInterpolationOutputTestFixture,
    ::testing::Values(
        std::make_tuple(LinearInterpolationTestConstants { 0.0, 1.0, 0.0, -2.0 }, 0.1, -0.2),
        std::make_tuple(LinearInterpolationTestConstants { 0.0, 1.0, 0.0, -2.0 }, 0.2, -0.4),
        std::make_tuple(LinearInterpolationTestConstants { 0.0, 1.0, 0.0, -2.0 }, 0.5, -1.0),
        std::make_tuple(LinearInterpolationTestConstants { 0.0, 1.0, 0.0, -2.0 }, 0.8, -1.6),
        std::make_tuple(LinearInterpolationTestConstants { 0.0, 1.0, 0.0, -2.0 }, 0.9, -1.8)));

INSTANTIATE_TEST_SUITE_P(LinearInterpolationSlope1OffsetOutputTest,
    LinearInterpolationOutputTestFixture,
    ::testing::Values(
        std::make_tuple(LinearInterpolationTestConstants { 0.0, 1.0, 1.0, 2.0 }, 0.1, 1.1),
        std::make_tuple(LinearInterpolationTestConstants { 0.0, 1.0, 1.0, 2.0 }, 0.2, 1.2),
        std::make_tuple(LinearInterpolationTestConstants { 0.0, 1.0, 1.0, 2.0 }, 0.5, 1.5),
        std::make_tuple(LinearInterpolationTestConstants { 0.0, 1.0, 1.0, 2.0 }, 0.8, 1.8),
        std::make_tuple(LinearInterpolationTestConstants { 0.0, 1.0, 1.0, 2.0 }, 0.9, 1.9)));

INSTANTIATE_TEST_SUITE_P(LinearInterpolationSlope2OffsetOutputTest,
    LinearInterpolationOutputTestFixture,
    ::testing::Values(
        std::make_tuple(LinearInterpolationTestConstants { 0.0, 1.0, 1.0, 3.0 }, 0.1, 1.2),
        std::make_tuple(LinearInterpolationTestConstants { 0.0, 1.0, 1.0, 3.0 }, 0.2, 1.4),
        std::make_tuple(LinearInterpolationTestConstants { 0.0, 1.0, 1.0, 3.0 }, 0.5, 2.0),
        std::make_tuple(LinearInterpolationTestConstants { 0.0, 1.0, 1.0, 3.0 }, 0.8, 2.6),
        std::make_tuple(LinearInterpolationTestConstants { 0.0, 1.0, 1.0, 3.0 }, 0.9, 2.8)));

INSTANTIATE_TEST_SUITE_P(LinearInterpolationComplexOffsetOutputTest,
    LinearInterpolationOutputTestFixture,
    ::testing::Values(
        std::make_tuple(LinearInterpolationTestConstants { -2.0, 2.0, 5.0, 0.0 }, 0.0, 2.5)));

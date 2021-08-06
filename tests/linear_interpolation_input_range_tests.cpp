#include "linear_interpolation.hpp"
#include "linear_interpolation_base.hpp"
#include <gtest/gtest.h>

class LinearInterpolationBoundaryInvalidValuesTestFixture
    : public LinearInterpolationTestConstants,
      public ::testing::TestWithParam<double> {
};

TEST_P(LinearInterpolationBoundaryInvalidValuesTestFixture, ValueOutsideXRangeThrowsException)
{
    double const x = GetParam();
    ASSERT_THROW(linear_interpolation(x1, x2, y1, y2, x), std::invalid_argument);
}

INSTANTIATE_TEST_SUITE_P(LinearInterpolationBoundaryTest,
    LinearInterpolationBoundaryInvalidValuesTestFixture,
    ::testing::Values(
        -1.0, 2.0, std::numeric_limits<double>::max(), std::numeric_limits<double>::lowest()));

INSTANTIATE_TEST_SUITE_P(LinearInterpolationBoundaryEdgeCasesTest,
    LinearInterpolationBoundaryInvalidValuesTestFixture,
    ::testing::Values(
        -std::numeric_limits<double>::epsilon(), 1.0 + std::numeric_limits<double>::epsilon()));

class LinearInterpolationBoundaryValidValuesTestFixture : public LinearInterpolationTestConstants,
                                                          public ::testing::TestWithParam<double> {
};

TEST_P(LinearInterpolationBoundaryValidValuesTestFixture, ValueInsideXRangeThrowsNoExeption)
{
    double const x = GetParam();
    ASSERT_NO_THROW(linear_interpolation(x1, x2, y1, y2, x));
}

INSTANTIATE_TEST_SUITE_P(LinearInterpolationBoundaryValidValuesTest,
    LinearInterpolationBoundaryValidValuesTestFixture,
    ::testing::Values(0.1, 0.5, 0.9, std::numeric_limits<double>::epsilon(),
        std::numeric_limits<double>::min(), 1.0 - std::numeric_limits<double>::epsilon()));


TEST(LinearInterpolationXORdering, IncorrectXOrderingThrowsException)
{
    ASSERT_THROW(linear_interpolation(1.0, 0.0, 1.0, 0.0, 0.5) , std::invalid_argument);
}

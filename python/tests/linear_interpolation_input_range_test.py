import sys
import pytest
from linear_interpolation import linear_interpolation


@pytest.mark.parametrize("x_value", [-1.0, 2.0, sys.float_info.max, -sys.float_info.max])
def test_input_range_outside_values(x_value):
    with pytest.raises(Exception) as e_info:
        linear_interpolation(0.0, 1.0, 0.0, 1.0, x_value)


@pytest.mark.parametrize("x_value", [-sys.float_info.epsilon, 1.0 + sys.float_info.epsilon])
def test_input_range_edge_cases(x_value):
    with pytest.raises(Exception) as e_info:
        linear_interpolation(0.0, 1.0, 0.0, 1.0, x_value)


@pytest.mark.parametrize("x_value", [0.0, 0.1, 0.5, 0.9, 1.0])
def test_input_range_valid_input(x_value):
    linear_interpolation(0.0, 1.0, 0.0, 1.0, x_value)


@pytest.mark.parametrize("x_value", [sys.float_info.epsilon, 1.0 - sys.float_info.epsilon])
def test_input_range_valid_input_edge_cases(x_value):
    linear_interpolation(0.0, 1.0, 0.0, 1.0, x_value)


def test_input_range_invalid_x_ordering():
    with pytest.raises(Exception) as e_info:
        linear_interpolation(1.0, 0.0, 0.0, 1.0, 0.5)

import pytest

from linear_interpolation import linear_interpolation


def test_linear_interpolation_output_test_x1_returns_y1():
    assert linear_interpolation(0.0, 1.0, 0.0, 1.0, 0.0) == 0.0


def test_linear_interpolation_output_test_x2_returns_y2():
    assert linear_interpolation(0.0, 1.0, 0.0, 1.0, 1.0) == 1.0


@pytest.mark.parametrize("x1,x2,y1,y2,x,y", [(0.0, 1.0, 0.0, 1.0, 0.1, 0.1),
                                             (0.0, 1.0, 0.0, 1.0, 0.2, 0.2),
                                             (0.0, 1.0, 0.0, 1.0, 0.5, 0.5),
                                             (0.0, 1.0, 0.0, 1.0, 0.8, 0.8),
                                             (0.0, 1.0, 0.0, 1.0, 0.9, 0.9)])
def test_linear_interpolation_output_test_values_id(x1, x2, y1, y2, x, y):
    assert linear_interpolation(x1, x2, y1, y2, x) == pytest.approx(y)


@pytest.mark.parametrize("x1,x2,y1,y2,x,y", [(0.0, 1.0, 1.0, 0.0, 0.1, 0.9),
                                             (0.0, 1.0, 1.0, 0.0, 0.2, 0.8),
                                             (0.0, 1.0, 1.0, 0.0, 0.5, 0.5),
                                             (0.0, 1.0, 1.0, 0.0, 0.8, 0.2),
                                             (0.0, 1.0, 1.0, 0.0, 0.9, 0.1)])
def test_linear_interpolation_output_test_values_neg_id(x1, x2, y1, y2, x, y):
    assert linear_interpolation(x1, x2, y1, y2, x) == pytest.approx(y)


@pytest.mark.parametrize("x1,x2,y1,y2,x,y", [(0.0, 1.0, 0.0, 2.0, 0.1, 0.2),
                                             (0.0, 1.0, 0.0, 2.0, 0.2, 0.4),
                                             (0.0, 1.0, 0.0, 2.0, 0.5, 1.0),
                                             (0.0, 1.0, 0.0, 2.0, 0.8, 1.6),
                                             (0.0, 1.0, 0.0, 2.0, 0.9, 1.8)])
def test_linear_interpolation_output_test_values_slope2(x1, x2, y1, y2, x, y):
    assert linear_interpolation(x1, x2, y1, y2, x) == pytest.approx(y)


@pytest.mark.parametrize("x1,x2,y1,y2,x,y", [(0.0, 1.0, 0.0, -2.0, 0.1, -0.2),
                                             (0.0, 1.0, 0.0, -2.0, 0.2, -0.4),
                                             (0.0, 1.0, 0.0, -2.0, 0.5, -1.0),
                                             (0.0, 1.0, 0.0, -2.0, 0.8, -1.6),
                                             (0.0, 1.0, 0.0, -2.0, 0.9, -1.8)])
def test_linear_interpolation_output_test_values_slope_neg2(x1, x2, y1, y2, x, y):
    assert linear_interpolation(x1, x2, y1, y2, x) == pytest.approx(y)


@pytest.mark.parametrize("x1,x2,y1,y2,x,y", [(0.0, 1.0, 1.0, 2.0, 0.1, 1.1),
                                             (0.0, 1.0, 1.0, 2.0, 0.2, 1.2),
                                             (0.0, 1.0, 1.0, 2.0, 0.5, 1.5),
                                             (0.0, 1.0, 1.0, 2.0, 0.8, 1.8),
                                             (0.0, 1.0, 1.0, 2.0, 0.9, 1.9)])
def test_linear_interpolation_output_test_values_slope_1_offset(x1, x2, y1, y2, x, y):
    assert linear_interpolation(x1, x2, y1, y2, x) == pytest.approx(y)

@pytest.mark.parametrize("x1,x2,y1,y2,x,y", [(0.0, 1.0, 1.0, 3.0, 0.1, 1.2),
                                             (0.0, 1.0, 1.0, 3.0, 0.2, 1.4),
                                             (0.0, 1.0, 1.0, 3.0, 0.5, 2.0),
                                             (0.0, 1.0, 1.0, 3.0, 0.8, 2.6),
                                             (0.0, 1.0, 1.0, 3.0, 0.9, 2.8)])
def test_linear_interpolation_output_test_values_slope_2_offset(x1, x2, y1, y2, x, y):
    assert linear_interpolation(x1, x2, y1, y2, x) == pytest.approx(y)


@pytest.mark.parametrize("x1,x2,y1,y2,x,y", [(-2.0, 2.0, 5.0, 0.0, 0.0, 2.5)])
def test_linear_interpolation_output_test_values_complicated_function(x1, x2, y1, y2, x, y):
    assert linear_interpolation(x1, x2, y1, y2, x) == pytest.approx(y)

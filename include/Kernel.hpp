#pragma once

#include "utils.hpp"

#include <opencv2/core/core.hpp>

namespace terrain
{

enum KernelType { MOORE, VON_NEUMANN, VON_NEUMANN2 };
using Point = cv::Point2i;

class Kernel
{
  public:
    std::vector<Point> neighbours(Point point, int rows, int cols);

    static std::vector<Point> neighbours(Point point, int rows, int cols, KernelType kt);

    virtual void apply(cv::Mat& img, int iterations) = 0;

  protected:
    KernelType kernel_type;
};

} // namespace terrain
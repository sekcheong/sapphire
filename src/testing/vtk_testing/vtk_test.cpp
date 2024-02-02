#include <iostream>
#include "itkImage.h"

int main()
{
  using ImageType = itk::Image<unsigned short, 3>;
  auto image = ImageType::New();
  std::cout << "ITK Hello World!" << std::endl;
  std::cout << image << std::endl;
}

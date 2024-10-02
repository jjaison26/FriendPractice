#include <iostream>

using namespace std;

class GeometricScaler;
class GeometricSwapper;
class Rectangle
{
  int width, height;

public:
  Rectangle(int w, int h) : width(w), height(h) {}

  int area()
  {
    return (width * height);
  }
  int getWidth() {
      return this->width;
  }
  int getHeight() {
      return this->height;
  }
  void scale(GeometricScaler scalar);
  void swap(GeometricSwapper swapper);
};

class GeometricScaler
{
private:
  friend class Rectangle;
  int factor;

public:
  GeometricScaler(int factor)
  {
    this->factor = factor;
  }
};
class GeometricSwapper {
    private:
    friend class Rectangle;
    int width;
    int height;
};

void Rectangle::scale(GeometricScaler scalar)
{
  this->width = this->width * scalar.factor;
  this->height = this->height * scalar.factor;
}

void Rectangle::swap(GeometricSwapper swapper) {
    swapper.width = this->height;
    swapper.height = this->width;
    this->width = swapper.width;
    this->height = swapper.height;
}

int main()
{
  Rectangle rectangle(1, 2);
  cout << "Area of the Rectangle: " << rectangle.area() << endl;

  GeometricScaler scaler(5);
  rectangle.scale(scaler);

  cout << "Area of the Rectangle: " << rectangle.area() << endl;
  
  GeometricSwapper swapper;
  cout << "Width and Height of Rectangle before : " << rectangle.getWidth() << ", " << rectangle.getHeight() << endl;
  rectangle.swap(swapper);
  cout << "Width and Height of Rectangle after : " << rectangle.getWidth() << ", " << rectangle.getHeight() << endl;

  return 0;
}

class Shape {
  double area() {
    return 0;
  }

  void displayInfo() {
    print("Displaying shape");
  }
}

class Circle extends Shape {
  double radius;

  Circle(this.radius);

  @override
  double area() {
    return 3.14 * radius * radius;
  }

  @override
  void displayInfo() {
    print("Radius of the circle $radius");
    print("Area of the circle ${area()}");
  }
}

class Rectangle extends Shape {
  double length;
  double width;

  Rectangle(this.length, this.width);

  @override
  double area() {
    return length * width;
  }

  @override
  void displayInfo() {
    print("Length of rectangle $length and width $width.");
    print("area of the rectangle${area()}.");
  }
}

void main() {
  Circle circle = Circle(5.0);
  circle.displayInfo();
  Rectangle rectangle = Rectangle(4.0, 6.0);
  rectangle.displayInfo();
}

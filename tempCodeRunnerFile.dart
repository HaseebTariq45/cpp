class Shape {
  double area() 
  {

    return 0;
  }

  void displayInfo() {
    print("This is a shape.");
  }
}

class Circle extends Shape {
  double radius;

  Circle(this.radius);

  @override
  double area() {
    return 3.14159 * radius * radius;
  }

  @override
  void displayInfo() {
    print("This is a circle with radius $radius");
    print("The area of the circle is ${area()}");
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
    print("This is a rectangle with length $length and width $width.");
    print("The area of the rectangle is ${area()}.");
  }
}

void main() {
  Circle circle = Circle(5.0);
  circle.displayInfo();
  Rectangle rectangle = Rectangle(4.0, 6.0);
  rectangle.displayInfo();
}

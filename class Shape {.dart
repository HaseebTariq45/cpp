class Shape {
  double area();

  @override //+
  double area() {
    //+
    // Implement the area calculation for the shape.//+
    // For example, for a circle, the area would be 3.14159 * radius * radius.//+
    // For a rectangle, the area would be length * width.//+
    // Replace this comment with the actual implementation.//+
    return 0.0; //+
  } //+
// {"conversationId":"bc4546d4-46ed-43e9-aef4-73ba2f2f3f7b","source":"instruct"}

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

#include <stdio.h>

struct Shape {
    double (*area)(void *);
    void (*draw)(void *);
};

struct Circle {
    double radius;
    struct Shape base; // Inheritance of Shape
};

// Function to calculate the area of a circle
double circleArea(void *shape) {
    struct Circle *c = (struct Circle *)shape;
    return 3.14159 * c->radius * c->radius;
}

// Function to draw a circle
void circleDraw(void *shape) {
    printf("Drawing a circle with radius %.2f\n", ((struct Circle *)shape)->radius);
}

int main() {
    struct Circle myCircle = {5.0, {circleArea, circleDraw}};
    
    printf("Area: %.2f\n", myCircle.base.area(&myCircle));
    myCircle.base.draw(&myCircle);
    
    return 0;
}


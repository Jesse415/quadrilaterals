//This is the start to the quadrilaterals C++ file
#include <iostream>
#include <cmath>
using namespace std;

/*write a point class represented by two values x and y.*/
class Point{
public:
  int x1, y1, x2, y2, x3, y3, x4, y4;
  Point()
  Point(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4):

  display(){
    return string("The area is: ", getArea());
  }
};

/*abstract quadrilateral class*/
/*quadrilateral has four points and for sides where sum of any three sides is larger than
  the fourth side. sum of the angles between adjacent sides are 360.*/
class Quadrilateral: public Point{
  int cd1, cd2, cd3, cd4;
public:
  Quadrilateral(): Point(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4){
    cd1 = new Coordinate(x1, y1);
    cd2 = new Coordinate(x2, y2);
    cd3 = new Coordinate(x3, y3);
    cd4 = new Coordinate(x4, y4);
  }
  lengthA(){
    return math.abs(cd2.x - cd1.x);
  }
  lengthB(){
    return math.abs(cd4.x - cd3.x);
  }
  lengthC(){
    return math.abs(cd3.y - cd1.y);
   }
  lengthD(){
    return math.abs(cd4.y - cd2.y);
   }
  height(){
    return math.abs(cd3.y-cd1.y)
  }
  double getArea();
};
/*Parallelogram is a quadrilateral where its opposite sides are parallel and equal and
  the angles between adjacent sides are all 90 deg.*/
class Parallelogram: public Quadrilateral{
  int side, pHeight;
public:
  Parallelogram(int x1, int y1, int x2, int y2, int x3, int y3):
    quadrilateral(x1, y1, x2, y2, x3, y3, 0, 0){
    side = lengthA();
    pHeight = height();
  }
  double getArea(){
    return side*pHeight;
  }
};

class Rectangle: public Parallelogram{
  int sideA, sideC;
public:
  Rectangle(): Parallelogram(int x1, int y1, int x2, int y2, int x3, int y3):
               parallelogram(x1, y1, x2, y2, x3, y3){
    sideA = lengthA();
    sideC = lengthC();
  }
  double getArea(){
    return sideA*sideC;
  }
};


/*square is a quadrilateral where its all sides are equal, opposite sides are parallel, and
  the angles between adjacent are all 90 deg.*/
class Square: public Rectangle{
public:
  int side;
  Square(): Rectangle(int x1, int y1, int x2, int y2):
    quadrilateral(x1, y1, x2, y2, 0, 0, 0, 0){
    side = lengthA();
  }
  double getArea(){
    return math.pow(side, 2);
  }
};
/*rhombus is a quadrilateral where its all sides are equal, opposite sides are parallel*/
class Rhombus: public Square{
  Rhombus(): Square(int x1, int y1, int x2, int y2)

};


/*if you declare the destruct-or of a class to be virtual and with = 0 then the class will be abstract. The quadrilateral will have an abstract method to calculate its area.*/

/*for parallelograms, rectangles, squares, and rhombuses, will need concrete classes using inheritance where the chain of inheritance is as long as possible. override the area calculation method in the sub-classes.*/

/*Each class will have setters, getters, constructors, destructors, and assignments*/

/*assume one corner of each quadrilateral will be (0,0) and the largest side will be on the x axis.*/

/*Example: parallelogram with a, b, and 0, the other three corners are (a,O), (b cos0, b sin0), and (a + b cos0, b sin0).*/

/*Figure out the formulas to calculate the coordinates of the corner points of other types of quadrilateral. Also, figure out the formulas to calculate the areas of the quadrilaterals.*/

/*WRITE a main function to define an array of quadrilaterals.*/
/*it will then provide a menu to create a rectangle, a parallelogram, a square, or a rhombus,*/

//main function menu
int main(){
  myQuadrilaterals quad1;
  int a, b, angle1, angle2, display;
  char selection[10];
  bool menu = true;

  while(menu){
    cout << "Enter your choice, [r]ectangle, [p]arallelogram, [s]quare, [R]hombus, [d]isplay, or [q]uit." endl;
    cin >> selection;

    if(strcmp(selection, "q")==0){
      cout << "Exiting Program." << endl;
      menu = false;
    } else if(strcmp(selection, "r")==0){
      cout << "Enter two sides of the rectangle, first side (A): " << endl;
      a = errorCheck();
      cout << "Now side (B): " << endl;
      b = errorCheck();
      quad1.rectangle(a, b);
    } else if(strcmp(selection, "p")==0){
      cout << "Enter two side of the parallelogram, first side (A): " << endl;
      a = errorCheck();
      cout << "Now side (B): " << endl;
      b = errorCheck();
      cout << "Now the angle: " << endl;
      quad1.parallelogram(a, b, angle);
    } else if(strcmp(selection, "s")==0){
      cout << "Enter one side of the square (A): " << endl;
      a = errorCheck();
      quad1.square(a);
    } else if(strcmp(selection, "R")==0){
      cout << "Enter side (A) of the rhombus: " << endl;
      a = errorCheck();
      cout << "Now enter the angle between the two adjacent sides: "
      angle = errorCheck();
      quad1.rhombus(a, angle1, angle2);
    } else if(strcmp(selection, "d")==0){
        cout << "Enter the index to display: " << endl;
        dIndex = errorCheck();
        quad1.display(dIndex);
    }
    return 0;
  }
}

/*1. Rectangle user will need to input two sides, A & B.
  2. Parallelogram, user input two sides, A & B and the angle 0 between the two sides.
  3. Square, user will input only the side A.
  4. Rhombus, user input the side A and the angle 0 between two adjacent sides.*/

/*menu needs a display item. Index of a quadrilateral will be given as input and the program will display the coordinates of the four corners, its area, and which kind of quadrilateral it is.*/

/*Will need exception handling wherever possible in each class.

  Example: A & B cannot be zero in a rectangle pr a parallelogram, 0 cannot be zero in a rhombus or a parallelogram. Find other exception situations.*/

/*Submission will include (the UML diagrams and codes) by 13/09*/
int errorCheck() {
  int Check;
  while (!(cin >> Check)) {
    cin.clear();
    cin.ignore(100, '\n');
    cout << "Your input is not valid! Try again!" << endl;
  }
  return Check;
}

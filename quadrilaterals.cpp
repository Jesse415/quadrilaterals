//This is the start to the quadrilaterals C++ file
#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;
int errorCheck();


/*write a point class represented by two values x and y.*/
class Points {
protected:
  double x, y;
public:
  Points(double x, double y){
    x=x;
    y=y;
  }
  Points(): Points(0, 0) {}
  double getX(){
    return x;
  }
  double getY(){
    return y;
  }
  void setPoint(int x, int y){
    x=x;
    y=y;
  }
};

/*abstract quadrilateral class
  quadrilateral has four points and for sides where sum of any three sides
  is larger than the fourth side. sum of the angles between adjacent sides are 360.
  The is the main base class.*/
class Quadrilateral {
protected:
  Points point1, point2, point3, point4;
  double sideA, sideB, sideC, sideD, area;
public:
  Quadrilateral (double x, double y): point1(Points(0,0)){}
  /*getters for points*/
  Points getPoint1(){
    return point1;
  }
  Points getPoint2(){
    return point2;
  }
  Points getPoint3(){
    return point3;
  }
  Points getPoint4(){
    return point4;
  }
  double getSideA (){
    return sideA;
  }
  double getSideB (){
    return sideB;
  }
  double getSideC (){
    return sideC;
  }
  double getSideD (){
    return sideD;
  }
  virtual void setArea()=0;
  virtual double getArea() = 0;
};

/*Parallelogram is a quadrilateral where its opposite sides are parallel and equal*/
class Parallelogram: public Quadrilateral {
protected:
  int angle;
public:
  Parallelogram (int x, int y): Quadrilateral(x, y){}
  void setValues(int a, int b, int inAngle){
    sideA = a;
    sideB = b;
    angle = inAngle;
  }
  void setPoints(){
    point2.setPoint(sideA, 0);
    point3.setPoint(sideB * cos(angle), sideB * sin(angle));
    point4.setPoint(sideA + sideB * cos(angle), sideB * sin(angle));
  }
  void setArea(){
    area = ((sideB*sideA)*(sin(angle)));
  }
  double getArea() {
    return area;
  }
};


/*rhombus is a quadrilateral where its all sides are equal, opposite sides are parallel*/
class Rhombus: public Parallelogram {
protected:
  int angle;
public:
  Rhombus (int x, int y): Parallelogram (x, y){}
  void setValues(int a, int inAngle){
    sideA = a;
    angle = inAngle;
  }
  void setPoints(){
   point2.setPoint(0, (360-(angle*2))/2);
   point3.setPoint((360-(angle*2))/2, 0);
   point4.setPoint((360-(angle*2))/2, (360-(angle*2))/2);
  }
  void setArea(){
    area = sqrt(sideA)*sin(angle);
  }
  double getArea(){
    return area;
  }
};

class Rectangle: public Quadrilateral {
public:
  Rectangle (int x, int y): Quadrilateral(x, y){}
  void setValues(int a, int b){
    sideA = a;
    sideB = b;
  }
  void setPoints(){
    point2.setPoint(sideA, 0);
    point3.setPoint(0, sideB);
    point4.setPoint(sideB, sideA);
  }
  void setArea(){
    area = sideA*sideB;
  }
  double getArea(){
    return area;
  }
};

/*square is a quadrilateral where its all sides are equal, opposite sides are parallel, and
  the angles between adjacent are all 90 deg.*/
class Square: public Rectangle {
public:
  Square(int x): Rectangle(x, y){}
  void setValues(int a){
    sideA = a;
  }
  void setPoints(){
    point2.setPoint(sideA, 0);
    point3.setPoint(0, sideA);
    point4.setPoint(sideA, sideA);
  }
  void setArea(){
    area = sqrt(sideA);
  }
  double getArea() {
    return area;
  }
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
  Quadrilateral *quads[1000000];
  int a, b, angle1, dIndex;
  char selection[10];
  bool menu = true;

  while(menu){
    cout << "Enter your choice, [r]ectangle, [p]arallelogram, [s]quare, [R]hombus, [d]isplay, or [q]uit." << endl;
    cin >> selection;

    if(strcmp(selection, "q")==0){
      cout << "Exiting Program." << endl;
      menu = false;
    } else if(strcmp(selection, "r")==0){
      cout << "Enter two sides of the rectangle, first side (A): " << endl;
      a = errorCheck();
      cout << "Now side (B): " << endl;
      b = errorCheck();
      quads.setValues(a, b);
    } else if(strcmp(selection, "p")==0){
      cout << "Enter two side of the parallelogram, first side (A): " << endl;
      a = errorCheck();
      cout << "Now side (B): " << endl;
      b = errorCheck();
      cout << "Now the angle: " << endl;
      quads = setValues(a, b, angle1);
      quads = getArea();
    } else if(strcmp(selection, "s")==0){
      cout << "Enter one side of the square (A): " << endl;
      a = errorCheck();
      Square(a);
    } else if(strcmp(selection, "R")==0){
      cout << "Enter side (A) of the rhombus: " << endl;
      a = errorCheck();
      cout << "Now enter the angle between the two adjacent sides: " << endl;
      angle1 = errorCheck();
      Rhombus rhom (a, angle1);
    } else if(strcmp(selection, "d")==0){
        cout << "Enter the index to display: " << endl;
        dIndex = errorCheck();
        display(dIndex);
    }
    return 0;
  }
};

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


#include <iostream>
#include <string>
#include "ShapesGood.h"

using namespace std;

Shape::Shape() : length(0), width(0), color("colorless") {}
Shape::Shape(int len, int wid, string col) : length(len), width(wid), color(col) {}
Shape::~Shape() {}
int Shape::getLength() const { return length; }
int Shape::getWidth() const { return width; }
string Shape::getColor() const { return color; }

Filled::Filled(string fillCol) : fillColor(fillCol) {}
string Filled::getFillColor()
{
    return fillColor;
}
void Filled::fill()
{
    cout << " With " + getFillColor() + " fill.";
}

Labeled::Labeled(string textCol) : textColor(textCol) {}
string Labeled::getTextColor()
{
    return textColor;
}
void Labeled::label()
{
    cout << " Containing the text: \"" << getTextColor() << "\".";
}

Square::Square(int len, int wid, string col) : Shape(len, wid, col) {}
void Square::draw()
{
    cout << "\nDrawing a " + getColor() + " square.";
}

FilledSquare::FilledSquare(int len, int wid, string col, string fillCol) : Square(len, wid, col), Filled(fillCol)
{
}
void FilledSquare::draw()
{
    cout << "\nDrawing a " + getColor() + " square.";
    fill();
}

FilledTextSquare::FilledTextSquare(int len, int wid, string col, string fillCol, string textCol) : Square(len, wid, col), Filled(fillCol), Labeled(textCol) {}
void FilledTextSquare::drawText(string text)
{
}
void FilledTextSquare::draw()
{
    cout << "\nDrawing a " + getColor() + " square.";
    fill();
    label();
}
Circle::Circle(int len, int wid, string col) : Shape(len, wid, col) {}
void Circle::draw()
{
    cout << "\nDrawing a " + getColor() + " circle.";
}

FilledCircle::FilledCircle(int len, int wid, string col, string fillCol) : Circle(len, wid, col), Filled(fillCol) {}
void FilledCircle::draw()
{
    cout << "\nDrawing a " + getColor() + " circle.";
    fill();
}

Arc::Arc(int len, int wid, string col) : Shape(len, wid, col) {}
void Arc::draw()
{
    cout << "\nDrawing a " + getColor() + " arc.";
}

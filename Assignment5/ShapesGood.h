#pragma once

#include <string>
using namespace std;

class Shape
{
public:
    Shape();
    Shape(int, int, string);
    virtual ~Shape();
    int getLength() const;
    int getWidth() const;
    virtual void draw() = 0;
    string getColor() const;

private:
    int width;
    int length;
    string color;
};

class Filled
{
public:
    Filled(string);
    void fill();
    string getFillColor();

private:
    string fillColor;
};

class Labeled
{
public:
    Labeled(string);
    string getTextColor();
    void label();

private:
    string textColor;
};

class Square : public Shape
{
public:
    Square(int, int, string);
    virtual void draw();
};

class FilledSquare : public Square, public Filled
{
public:
    FilledSquare(int, int, string, string);
    virtual void draw();
};

class FilledTextSquare : public Square, public Filled, public Labeled
{
public:
    FilledTextSquare(int, int, string, string, string);
    void drawText(string);
    virtual void draw();
};

class Circle : public Shape
{
public:
    Circle(int, int, string);
    virtual void draw();
};

class FilledCircle : public Circle, public Filled
{
public:
    FilledCircle(int, int, string, string);
    virtual void draw();
};

class Arc : public Shape
{
public:
    Arc(int, int, string);
    virtual void draw();
};
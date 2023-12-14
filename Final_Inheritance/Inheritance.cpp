#include <iostream>
#include <stdexcept>
#include <string>
class Shape
{
    public:
        Shape();
        Shape(double h, double w);
        virtual ~Shape();
        virtual void scale(double sFactor) = 0;
        virtual double area() = 0;
        virtual double perimeter() = 0;
        virtual void displayProperties();

        protected:
            double m_h;
            double m_w;
            std::string m_type;

};
void Shape::displayProperties()
{
    std::cout << "type: " << m_type << ", height: " << m_h << ", width: " << m_w << std::endl;
}
Shape::Shape()
{
    m_h = 1.0;
    m_w = 1.0;
}
Shape::Shape(double h, double w)
{
    m_h = h;
    m_w = w;
}
Shape::~Shape(){}
class Rectangle : public Shape
{
    public:
        Rectangle(double h, double w);
        virtual ~Rectangle();
        void scale(double sFactor);
        double area();
        double perimeter();
};
Rectangle::Rectangle(double h, double w)
{
    m_h = h;
    m_w = w;
    m_type = "Rectangle";
}
Rectangle::~Rectangle(){}
void Rectangle::scale(double sFactor)
{
    m_h *= 2;
    m_w *= 2;
}
double Rectangle::area()
{
    return m_h * m_w;
}
double Rectangle::perimeter()
{
    return 2 * m_h + 2 * m_w;
}
class Circle : public Shape
{
     public:
        Circle(double h, double w);
        virtual ~Circle();
        void scale(double sFactor);
        double area();
        double perimeter();
};
Circle::Circle(double h, double w)
{
    m_h = h;
    m_w = w;
    m_type = "Circle";
}
Circle::~Circle(){}
void Circle::scale(double sFactor)
{
    m_h *= 2;
    m_w *= 2;
}
double Circle::area()
{
    return 0.25 * 3.1416 * m_h;
}
double Circle::perimeter()
{
    return m_h * 3.1416;
}
int main()
{
    Rectangle* r = new Rectangle(2.0,3.0);
    Circle* c = new Circle(2.0,2.0);

    Shape* p_shapes[2];
    p_shapes[0] = c;
    p_shapes[1] = r;
    
    for(int i = 0; i < 2; i++)
    {
        p_shapes[i]->displayProperties();
        std::cout << "area: " << p_shapes[i]->area() << std::endl;
        std::cout << "perimiter: " << p_shapes[i]->perimeter() << std::endl;
        p_shapes[i]->scale(2.0);
        p_shapes[i]->displayProperties();
        std::cout << "area: " << p_shapes[i]->area() << std::endl;
        std::cout << "perimiter: " << p_shapes[i]->perimeter() << std::endl;
    }
    delete[] p_shapes;
    return 0;
};
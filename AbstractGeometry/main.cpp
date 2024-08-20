//AbstractGeometry
#include<Windows.h>
#include<iostream>
using namespace std;

namespace Geometry
{
	enum Color //ENUM - это перечисление.Перечисление-это набор целочисленных констант
	{
		CONSOLE_BLUE = 0X09,
		CONSOLE_GREEN = 0XAA,
		CONSOLE_RED = 0XCC,
		CONSOLE_DEFAULT = 0X07

	};

	class Shape
	{
		Color color;
	public:
		Shape(Color color) :color(color) {}
		virtual~Shape() {}
		virtual double get_area()const = 0;
		virtual double get_perimetr()const = 0;
		virtual void draw()const = 0;
		Color get_color()const
		{
			return color;
		}
		void set_color(Color color)
		{
			this->color = color;
		}
		virtual void info()const
		{
			cout << "Площадь фигуры: " << get_area() << endl;
			cout << "Периметр фигуры: " << get_perimetr() << endl;
			draw();
		}

	};

	class Square :public Shape
	{
		double side;
	public:
		Square(double side, Color color) :Shape(color)
		{
			set_side(side);
		}
		virtual~Square() {}
		double get_area()const override
		{
			return side * side;
		}
		double get_perimetr()const
		{
			return side * 4;
		}
		void draw()const override
		{
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

			SetConsoleTextAttribute(hConsole, get_color());
			for (int i = 0; i < side; i++)
			{
				for (int i = 0; i < side; i++)
				{
					cout << "* ";
				}
				cout << endl;
			}
			SetConsoleTextAttribute(hConsole, Color::CONSOLE_DEFAULT);
		}

		double get_side()const
		{
			return side;
		}
		void set_side(double side)
		{
			this->side = side;
		}
		void info()const override
		{
			cout << typeid(*this).name() << endl;
			cout << "Длина стороны: " << side << endl;
			Shape::info();
		}
	};

	class Rectandle :public Shape
	{
		double width;
		double height;
	public:
		Rectandle(double width, double height, Color color) :Shape(color)
		{
			set_width(width);
			set_height(height);
		}
		~Rectandle() {}
		double get_area()const override
		{
			return width * height;
		}
		double get_perimetr()const override
		{
			return (width * height) * 2;
		}

		void draw()const override
		{
			for (int i = 0; i < height; i++)
			{
				for (int j = 0; j < width; j++)
				{
					cout << "* ";

				}
				cout << endl;
			}
		}

		double get_height()const
		{
			return height;
		}
		void set_wedht(double width)
			void info()const override
		{
			cout << "Высота: " << get_height() << endl;
			cout << "Ширина: " << get_wedht() << endl;
			Shape::info();
		}
	};
}
void main()
{
	setlocale(LC_ALL, "");
	//Shape shape(Color::CONSOLE_BLUE);
	Geometry::square square(5,Geometry::Color::CONSOLE_RED);
	/*cout << "Длина стороны квадрата: " << square.get_side() << endl;
	cout << "Площадь квадрата: " << square.get_area() << endl;
	cout << "Периметр квадрата: " << square.get_perimetr() << endl;*/
	square.info();

	Geometry::Rectangle rect{ 15, 8, Geometry::Color::CONSOLE_RED };
	rect.info();
}
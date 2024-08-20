//AbstractBaseClass
#include<iostream>
using namespace std;

class Animal
{
public:
	virtual void sound() = 0;
};
class Cat :public Animal{};
class Tiger :public Cat
{
public:
	void sound() override
	{
		cout << "rrrrrrr" << endl;
	}
};
class HomeCat :public Cat
{
public:
	void sound() override
	{
		cout << "Myu-myu-myu" << endl;
	}
};
void main()
{
	setlocale(LC_ALL, "");
	cout << "Hello AbstractBaseClass ";
	//Animal animal;
	//Cat cat;
	Tiger tiger;
	tiger.sound();
	HomeCat homecat;
	homecat.sound();
}
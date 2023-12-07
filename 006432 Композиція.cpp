/*
Розробіть клас “Автомобіль”. За допомогою композиції використайте всередині цього
класа об’єкти інших класів: Двигуна, Кузова, Коліс, тощо. Розробіть конструктор
копіювання таким чином, щоб на основі готового об’єкта Автомобіль можна було
створити ще один такий самий об’єкт, але при цьому можна було би змінити деякі
властивості, наприклад забарвлення кузова.
*/

#include <iostream>
#include <string>

class Engine
{
private:
	std::string type;

public:
	Engine(const std::string type) : type(type) {}

	std::string getType() const
	{
		return type;
	}
};

class Body
{
private:
	std::string color;

public:
	Body(const std::string color) : color(color) {}

	std::string getColor() const
	{
		return color;
	}
};

class Wheels
{
private:
	int count;

public:
	Wheels(int count) : count(count) {}

	int getCount() const
	{
		return count;
	}
};

class Car
{
private:
	std::string brand;
	Engine engine;
	Body body;
	Wheels wheels;

public:
	Car(const std::string brand, const Engine& engine, const Body& body, const Wheels& wheels)
		: brand(brand), engine(engine), body(body), wheels(wheels) {}

	Car(const Car& otherCar)
		: brand(otherCar.brand), engine(otherCar.engine), body(otherCar.body), wheels(otherCar.wheels) {}

	void changeBodyColor(const std::string& newColor)
	{
		body = Body(newColor);
	}

	void printInfo() const
	{
		std::cout << "Автомобіль марки " << brand << ":" << std::endl;
		std::cout << "Тип двигуна - " << engine.getType() << std::endl;
		std::cout << "Колір кузова - " << body.getColor() << std::endl;
		std::cout << "Кількість коліс - " << wheels.getCount() << std::endl;
	}
};

int main()
{
	system("chcp 1251>null");

	Engine carEngine("бензиновий");
	Body carBody("синій");
	Wheels carWheels(4);

	Car car("Toyota", carEngine, carBody, carWheels);
	car.printInfo();

	std::cout << std::endl;
	std::cout << "Змінюємо колір кузова" << std::endl;
	std::cout << std::endl;

	Car changeCar = car;
	changeCar.changeBodyColor("червоний");
	changeCar.printInfo();
}
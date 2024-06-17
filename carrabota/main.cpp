#include <iostream>
using namespace std;

class Car
{
	char* model;
	int year;
	double price;
public:
	Car()
	{
		model = nullptr;
		year = 0;
		price = 0.0;
	}
	Car(const char* mod)
	{
		model = new char[strlen(mod) + 1];
		strcpy_s(model, strlen(mod) + 1, mod);
	}
	Car(const char* mod, int y, double pr):Car(mod)
	{
		year = y;
		price = pr;
	}
	Car(const Car& obj):Car(obj.model,obj.year,obj.price)
	{

	}
	Car& operator=(const Car& obj)//2
	{
		if (this == &obj)
		{
			return *this;
		}
		if (model != nullptr)
		{
			delete[] model;
		}
		model = new char[strlen(obj.model) + 1];
		strcpy_s(model, strlen(obj.model) + 1, obj.model);
		year = obj.year;
		price = obj.price;
		
		return *this;
	}
	~Car()//3
	{
		delete[] model;
	}
	const char* getModel()
	{
		return model;
	}
	int GetYear()
	{
		return year;
	}
	double GetPrice()
	{
		return price;
	}
	void SetModel(const char* mod)
	{
		if (model != nullptr)
		
			delete[]model;
		
		model = new char[strlen(mod) + 1];
		strcpy_s(model, strlen(mod) + 1, mod);
	}
	void SetYear(int y)
	{
		year = y;
	}
	void SetPrice(double pr)
	{
		price = pr;
	}
};

ostream& operator<<(ostream& os, Car& obj)
{
	os << obj.getModel() << "\t" << obj.GetYear() << "\t" << obj.GetPrice() << endl;
	return os;
}

istream& operator>>(istream& is, Car& obj)
{
	char buff[20];
	cout << "Enter model --> ";
	cin >> buff;
	obj.SetModel(buff);
	int y;
	double pr;
	cout << "Enter year --> ";
	is >> y;
	obj.SetYear(y);
	cout << "Enter price --> ";
	is >> pr;
	obj.SetPrice(pr);
	return is;
}
Car operator+= (Car& a, int b)
{
	a.SetPrice(a.GetPrice() + b);
	return a;
}
Car operator-= (Car& a, int b)
{
	a.SetPrice(a.GetPrice() - b);
	return a;
}
Car operator++ (Car& a)
{
	a.SetYear(a.GetYear() + 1);
	return a;
}
Car operator-- (Car& a)
{
	a.SetYear(a.GetYear() - 1);
	return a;
}
Car operator- (Car& a, Car& b)
{
	return Car(a.getModel(), a.GetYear(), a.GetPrice() - b.GetPrice());
}
Car operator+ (Car& a, Car& b)
{
	return Car(a.getModel(), a.GetYear(), a.GetPrice() + b.GetPrice());
}
int main()
{

	Car obj1("Audi A5", 2023, 500000);
	Car obj2("BMW X5", 2022, 400000);
	cout << obj1 << endl;
	/*cin >> obj1;
	cout << obj1;*/

	
	obj1 += 1000; // увеличиваем стоимость на 1000
	cout << obj1;
	
	obj1 -= 1000;// уменьшаем стоимость на 1000
	cout << obj1;
	
	++obj1; // увеличиваем год на 1
	cout << obj1;
	
	--obj1; // уменьшаем год на 1
	cout << obj1;
	
	Car r = obj1 - obj2; // разница стоимости автомобилей
	cout << r << endl;
	
	Car sum = obj1 + obj2; // сумма стоимости автомобилей , возвращается общая сумма
	cout << sum << endl;

 
}
#include <iostream>

class Animals;
class Dog;
class Cat;
class owl;
class fish;
class snake;
class Avestruz;
class Comida;
class Carne;
class Fruta;

class Animals
{
protected:
	const char *m_name;
	bool carnivoro;
public:
	virtual void move() { std::cout << "Me desplazo" << std::endl; };
	virtual void SetName(const char *name) { m_name = "name"; };
	virtual const char *getName() = 0;
};
class Dog : public Animals{
	void move() { std::cout << "Corro" << std::endl; }
	bool carnivoro = false;
public:
	void SetName(const char *name) {
		m_name = name;
	};
	const char *getName() {
		return m_name;
	}
};
class Cat : public Animals {
	void move() { std::cout << "Gateo" << std::endl; }
public:
	void SetName(const char *name) {
		m_name = name;
	};
	const char *getName() {
		return m_name;
	}
};
class owl : public Animals {
	void move() { std::cout << "Vuelo" << std::endl; }
public:
	void SetName(const char *name) {
		m_name = name;
	}
	const char *getName() {
		return m_name;

	}
};
class fish : public Animals {
	void move() { std::cout << "Nado" << std::endl; }
	bool carnivoro = false;
public:
	void SetName(const char *name) {
		m_name = name;
	};
	const char *getName() {
		return m_name;
	}
};
class Snake : public Animals {
	void move() { std::cout << "Repto" << std::endl; }
public:
	void SetName(const char *name) {
		m_name = name;
	};
	const char *getName() {
		return m_name;
	}
};
class Avestruz : public Animals{ 
	bool carnivoro = false;
	void SetName(const char *name) {
		m_name = name;
	};
	const char *getName() {
		return m_name;
	}
};
class Comida {
	friend class Animals;
protected:
	virtual void alimentar() = 0;
 };


int main() {
	Animals* animal;
	Avestruz roco;
	animal = &roco;
	animal->SetName("Roco");
	std::cout << animal->getName()<< std::endl;
	animal->move();
	system("pause");
	return 0;
}
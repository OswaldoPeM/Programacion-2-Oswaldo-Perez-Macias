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
	friend class Comida;
protected:
	const char *m_name;
	bool carnivoro;
public:
	virtual void move() { std::cout << "Me desplazo" << std::endl; };
	virtual void SetName(const char *name) { m_name = "name"; };
	virtual const char *getName() = 0;
	bool iscarnivoro() { return carnivoro; };
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
public:
	virtual void alimentar(Animals& b)=0;
protected:
 };
class carne : public Comida {
public:
	void alimentar(Animals& b) {
		if (b.iscarnivoro()) { std::cout << "Alimentado" << std::endl; return; }
		std::cout << "No se puede alimentar con esto" << std::endl;
	}
};
class fruta :public Comida {
public:
	void alimentar(Animals& b) {
		if (!b.iscarnivoro()) { std::cout << "Alimentado" << std::endl; return; }
		std::cout << "No se puede alimentar con esto" << std::endl;
	}
};

int main() {
	Animals* animal;
	Avestruz roco;
	Comida* comida;
	carne filete;
	comida = &filete;
	animal = &roco;
	animal->SetName("Roco");
	comida->alimentar(roco);
	std::cout << animal->getName()<< std::endl;
	animal->move();

	system("pause");
	return 0;
}
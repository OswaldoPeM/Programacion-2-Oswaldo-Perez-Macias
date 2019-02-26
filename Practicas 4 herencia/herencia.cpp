#include <iostream>
//TAREAAAAA!!!!!!!!!! abstacta, amistad, herencia , interfaz y metodo virtual.
class Nameable
{
protected:
	const char *m_name;
public:
	virtual void SetName(const char *name) { m_name = "name"; };// virtual funciona para heredar un metodo que puede ser que se 
																//reescriba en el codigo del metodo (en la clase perro ver que pasa
																//cuado comentas el mentodo set name)
	virtual const char *getName() = 0;
};
class Person {
public:

	void nameDog(Dog d, const char * name);

};
class Dog : public Nameable // clase nombre : public clase_padre, hereda lo que haya en protected y public
{
	friend class Person;
public:
	void SetName(const char *name) {
		m_name = name; 
	};
	const char *getName() {
		return m_name;
	}
private:

};

void Person::nameDog(Dog d, const char *name) {
	(d.SetName(name));
}
int main() {
	Dog pepe;
	Nameable *n;;
	n = &pepe;
	n->SetName("Pepe");
	std::cout << pepe.getName() << std::endl;
	return 0;
}
// Prototype.cpp  |  https://www.youtube.com/watch?v=KBkkEKNlE6I&list=PLk6CEY9XxSIDZhQURp6d8Sgp-A0yKKDKV&index=6
// Store some dummy object that you always want, so you will always get that object.
// And then only you will start working with that object.  Don't create object again and again.

#include <string>
#include <memory>
#include <unordered_map>
#include <iostream>
using namespace std;

/** Bullet is the base Prototype */
class Bullet
{
public:
	Bullet() {}

	Bullet(string bulletName, float speed, float firePower, float damagePower)
		: _bulletName(bulletName), _speed(speed), _firePower(firePower), _damagePower(damagePower)
	{}
	virtual ~Bullet() {}
	virtual unique_ptr<Bullet> clone() = 0;
	
	void fire(float direction)
	{
		_direction = direction;

		cout << "Name        : " << _bulletName << endl
			<< "Speed       : " << _speed << endl
			<< "FirePower   : " << _firePower << endl
			<< "DamagePower : " << _damagePower << endl
			<< "Direction   : " << _direction << endl << endl;
	}

protected:
	string _bulletName = "";
	float _speed = 0.0f;
	float _firePower = 0.0f;
	float _damagePower = 0.0f;
	float _direction = 0.0f;
};

/** SimpleBullet is a Concrete Prototype */
class SimpleBullet : public Bullet
{

public:
	SimpleBullet(string bulletName, float speed, float firePower, float damagePower) :
		Bullet(bulletName, speed, firePower, damagePower)
	{
	}

	// This is the method you'll be using for PROTOTYPING your object.
	// Whoever is implementing this abstract class, they have to
	// their own implementation of this clone, and return their own type.
	unique_ptr<Bullet> clone() override
	{
		return make_unique<SimpleBullet>(*this);
	}
};

/** GoodBullet is the Concrete Prototype */
class GoodBullet : public Bullet
{
public:
	GoodBullet(string bulletName, float speed, float firePower, float damagePower)
		: Bullet(bulletName, speed, firePower, damagePower)
	{
	}

	unique_ptr<Bullet> clone() override
	{
		return std::make_unique<GoodBullet>(*this);
	}
};

/** Opaque Bullet type, avoids exposing concrete implementations */
enum BulletType
{
	SIMPLE,
	GOOD
};

/** BulletFactory is the client */
class BulletFactory
{
private:
	unordered_map<BulletType, unique_ptr<Bullet>, hash<int> > m_Bullets;

public:
	BulletFactory()
	{
		m_Bullets[SIMPLE] = make_unique<SimpleBullet>("Simple Bullet", 50, 75, 75);
		m_Bullets[GOOD] = make_unique<GoodBullet>("Good Bullet", 75, 100, 100);
	}

	unique_ptr<Bullet> createBullet(BulletType BulletType)
	{
		return m_Bullets[BulletType]->clone();
	}
};

int main()
{
	// When the BulletFactory is created, one instance of a bullet per bullet type 
	// is created and stored in the factory's unordered_map.
	BulletFactory bulletFactory; 

	// Creates a copy of a SIMPLE bullet already stored from the factory, 
	// instead of instatiating a whole new object
	// All other properties of bullet are set on the original instance of the bullet except direction.
	// Direction is set when the Bullet->Fire(direction) is called.  
	unique_ptr<Bullet> Bullet = bulletFactory.createBullet(SIMPLE);
	Bullet->fire(90);

	Bullet = bulletFactory.createBullet(GOOD);
	Bullet->fire(100);
}

// Creating an object is more expensive than copying an object.
// All Object Initial State is common and takes time to build.
// Composition, creation, and representation of object should be decoupled from the system.
// Hide the complexity of creating new instance from the user.
// Which classes to create are specified at runtime.
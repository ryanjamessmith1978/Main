#pragma once
#include <iostream>
#include <ctime>

class Random
{
public:
	Random(const Random&) = delete; // deletes the ability to use the copy constructor.

	static Random& Get()
	{
		// static Random instance;
		return r_Instance;
	}

	float GetRandomNumber() { return m_RandomNumber; }

	static float CreateRandomNumber() { return Get().ICreateRandomNumber(); }

private:
	float ICreateRandomNumber()
	{
		srand(time(0));
		return (float)(rand()) / (float)(rand());
	}

	Random() { m_RandomNumber = 0.0f; } //

	float m_RandomNumber;

	static Random r_Instance; // This and Random() allows an instance get instantiated automatically
};
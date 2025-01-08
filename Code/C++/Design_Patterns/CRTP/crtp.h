#pragma once

template <typename Derived>
class Base
{
public:
	Base() = default;

	void DoSomething()
	{
		Derived& derived = static_cast<Derived&>(*this);
	}
};

class Derived : public Base<Derived>
{
public:
	Derived() = default;
};
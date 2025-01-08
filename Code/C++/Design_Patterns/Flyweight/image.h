#pragma once

#include <iostream>

class Image
{
public:
	virtual ~Image() {};
	virtual void Print() = 0;
};

class JPG : public Image
{
public:
	virtual void Print() override
	{
		std::cout << "I am a JPG!" << std::endl;
	}
};

class PNG : public Image
{
public:
	virtual void Print() override
	{
		std::cout << "I am a PNG!" << std::endl;
	}
};

class GIF : public Image
{
public:
	virtual void Print() override
	{
		std::cout << "I am a GIF!" << std::endl;
	}
};
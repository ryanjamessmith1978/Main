#pragma once
#include <string>
#include <iostream>
#include <map>
#include "image.h"

class Flyweight_ImageManager
{
public:
    Flyweight_ImageManager();
    ~Flyweight_ImageManager();

    template<typename T>
    void AddImage(const std::string& resourceName);

    void DeleteImage(const std::string& resourceName);

    Image* GetImage(const std::string& resourceName);

private:
    std::map<std::string, Image*> Images;
};

//  ### .CPP File ### 
Flyweight_ImageManager::Flyweight_ImageManager() 
    : Images() {}

Flyweight_ImageManager::~Flyweight_ImageManager() 
{
    std::cout << "----- DESTRUCTOR ------" << std::endl;
    for (std::pair<std::string, Image*> p : Images)
        delete p.second;

    Images.clear();
}

template <typename T>
void Flyweight_ImageManager::AddImage(const std::string& resourceName)
{
    std::map<std::string, Image*>::iterator it = Images.find(resourceName);

    if (it == Images.end())
    {
        Images[resourceName] = new T();
        std::cout << "ADD - Added New Image! " << std::endl;
    }
    else
    {
        delete it->second; // Could just cout that "Image file name already exists".  
        it->second = new T(); // Could also add more logic to have the same name with multiple image types.
        std::cout << "ADD - Replaced Image! " << std::endl;
    }
}

void Flyweight_ImageManager::DeleteImage(const std::string& resourceName) 
{
    std::map<std::string, Image*>::iterator it = Images.find(resourceName);

    if (it != Images.end())
    {
        delete it->second;
        Images.erase(it);
        std::cout << "DELETED IMAGE - Image Found " << std::endl;
    }
    else
    {
        std::cout << "DELETE IMAGE FAIL - Image NOT Found!" << std::endl;
    }
};

Image* Flyweight_ImageManager::GetImage(const std::string& resourceName) 
{
    std::map<std::string, Image*>::iterator it = Images.find(resourceName);

    if (it != Images.end())
    {
        std::cout << "GetImage - Image Found! " << std::endl;
        return it->second;
    }
   
    std::cout << "GetImage - No Image Found! " << std::endl;

    return nullptr;
};


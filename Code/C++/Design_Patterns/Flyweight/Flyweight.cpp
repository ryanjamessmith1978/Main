// Flyweight.cpp | https://www.youtube.com/watch?v=CY0iCHSH7oM

#include <iostream>
#include <string>
#include <map>
#include "image.h"
#include "Flyweight_ImageManager.h"

int PrintMenuAndGetChoice()
{
    std::cout << "\n1) Add image \n2) Delete image \n3) Get image \n4) Exit program\n?: ";
    int choice;
    std::cin >> choice;
    return choice;
}

void AddImage(Flyweight_ImageManager* fManager)
{
    std::cout << "---\n ADD \n----\n";
    std::cout << "NAME: ";
    std::string name;
    std::cin >> name;
    std::cout << "1) JPG \n2) GIF \n3) PNG \n4) Return\n?: ";

    int choice;
    std::cin >> choice;

    switch (choice)
    {
    case 1:
        fManager->AddImage<JPG>(name);
        break;
    case 2:
        fManager->AddImage<GIF>(name);
        break;
    case 3:
        fManager->AddImage<PNG>(name);
        break;
    default:
        break;
    };

    return;
}

void DeleteImage(Flyweight_ImageManager* fManager)
{
    std::cout << "---\n DELETE \n----\n";
    std::cout << "NAME: ";
    std::string name;
    std::cin >> name;
    fManager->DeleteImage(name);
}

void GetImage(Flyweight_ImageManager* fManager)
{
    std::cout << "---\n GET \n----\n";
    std::cout << "NAME: ";
    std::string name;
    std::cin >> name;
    Image* image = fManager->GetImage(name);

    if (image == nullptr)
        std::cout << "NULL PTR returned" << std::endl;
    else
        image->Print();
}

int main()
{
    // This specific flyweight pattern example is used with image objects
    // via the map data structure in the Flyweight_ImageManager class.
    
    Flyweight_ImageManager* Manager = new Flyweight_ImageManager();

    int choice = 0;
    bool getChoice = true;

    do
    {
        choice = PrintMenuAndGetChoice();
        if (choice == 1)
            AddImage(Manager);
        else if (choice == 2)
            DeleteImage(Manager);
        else if (choice == 3)
            GetImage(Manager);
        else
            getChoice = false;

    } while(getChoice);

    system("pause");
}

// *** FLYWEIGHT PATTERN NOTES ***
// Map with extra steps.  
// Any resource manager is a flyweight pattern
// Instance of an item versus a definition of an item.  
// Think about MMO Inventory problem.
// Manager that ensures I only add an image once, and 
// then share it when any other class/function needs it with get()
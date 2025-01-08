// STD_Maps.cpp : Key-Value pair data structure 
// https://www.youtube.com/watch?v=aEgG4pidcKU&t=2s
//  
// Maps order elements by key, in ascending order.
// Keys have to be unique.

#include <iostream>
#include <string>
#include <map>
#include <unordered_map>
#include <list>
using namespace std;

void BasicMapFunctions();
void UnOrderedMap();
void PokeDex();

int main()
{    
    BasicMapFunctions(); 
    PokeDex();  
    system("pause");
}

void BasicMapFunctions()
{    
    // map are ordered(by key) by default
    map<string, string> myMap; 

    // insert - doesn't matter which order you insert them in, 
    // map will order elements by key in ascending order.
    myMap.insert(pair<string, string>("banana", "die Banane")); // 2nd element - "banana"
    myMap.insert(pair<string, string>("apple", "der Apfel")); // 1rst element - "apple"
    myMap.insert(pair<string, string>("orange", "die Orange")); // 3rd element 
    myMap.insert(pair<string, string>("strawberry", "die Erdbeere")); // 5th element
   
    // The advantage of emplace is, it does in-place insertion 
    // and avoids an unnecessary copy of object.
    myMap.emplace("raspberry", "die Rasbere"); // 4th element
    myMap.emplace("blueberry", "die bluouse"); // either syntax works for emplace.

    // print map 
    for (pair<string, string> element : myMap) // for(auto& pair : myMap)
        cout << element.first << " - " << element.second << endl;
     
    // size()
    cout << "Size of myMap: " << myMap.size() << "\n\n";

    // access and change element of a map.
    myMap["strawberry"] = "fruit";
    
    
    // find if a key exists
    if (myMap.find("apple") != myMap.end()) // safer to use .at()
        cout << "myMap[""apple""]: " << myMap.at("apple") << endl;
    else
        cout << "apple is NOT present" << endl;

    // erase - remove individual elements by key.
    cout << "---- apple key being erased with myMap.erase ----" << endl;
    myMap.erase("apple");    

    for (map<string, string>::iterator it = myMap.begin(); it != myMap.end(); it++)
    {
        cout << "key: " << it->first << ", value: " << it->second << endl;
    }
    cout << "\n";


    // Print them backwards with reverse iterators
    for (auto it = myMap.rbegin(); it != myMap.rend(); it++)
    {
        cout << it->first << " = " << it->second << endl;
    }
    
    cout << "Size of myMap: " << myMap.size() << "\n";


    // find if a key exists
    if (myMap.count("apple"))
        cout << "apple is present" << endl;
    else
        cout << "apple is NOT present" << endl;

    // clears all map elements.
    myMap.clear();

    cout << "\n";
}

void PokeDex()
{
    // When using a container as a variable type in another container, 
    // that variable container doesn't need a name.  list<string> as map value in this case.
    map<string, list<string>> pokeDex;

    list<string> pikachuAttacks{ "thunder shock", "tail whip", "quick attack" };
    list<string> charmanderAttacks{ "flame thrower", "scary face" };
    list<string> chikoritaAttacks{ "razor leaf", "poison powder" };

    pokeDex.insert(pair<string, list<string>>("Pikachu", pikachuAttacks));
    pokeDex.insert(pair<string, list<string>>("Charmander", charmanderAttacks));
    
    // map_name.emplace_hint(position, key, element)
    // emplace_hint speeds up the insertion process by hinting the map where to start the insert.
    pokeDex.emplace_hint(pokeDex.begin(), pair<string, list<string>>("Chikorita", chikoritaAttacks));
    
    for (pair<string, list<string>> pair : pokeDex) // range-based for loop for Map.
    {
        cout << pair.first << " - ";

        for (string attack : pair.second) // range-based for loop for list.
            cout << attack << ", ";

        cout << "\n";
    }
}

void UnOrderedMap()
{
    cout << "\n --------- UNORDERED MAP ------------ \n";

    // unordered_map are ordered by when they were added to map to the back of the data structure.  
    unordered_map<string, string> myUnorderedMap;

    // insert - doesn't matter which order you insert them in, map will order elements by key in ascending order.
    myUnorderedMap.insert(pair<string, string>("banana", "die Banane")); // 2nd element - "banana
    myUnorderedMap.insert(pair<string, string>("apple", "der Apfel")); // 1rst element - "apple"
    myUnorderedMap.insert(pair<string, string>("orange", "die Orange")); // 3rd element
    myUnorderedMap.insert(pair<string, string>("strawberry", "die Erdbeere")); // 4th element

    // print map 
    for (auto pair : myUnorderedMap)
        cout << pair.first << " - " << pair.second << endl;

    cout << "\n";
}

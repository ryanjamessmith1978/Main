// ChernoMap.cpp | https://www.youtube.com/watch?v=KiB0vRi2wlc
// Unordered Map is a Hash Table - uses a hash function to hash your key
// then uses generated index to find which bucket your value lies in, and retrieves it.

#include <iostream>
#include <stdlib.h>
#include <stddef.h>
#include <vector>
#include <string>
#include <unordered_map>
#include <map>
#include <tuple>

struct CityRecord
{
    std::string Name;
    uint64_t Population = 0;
    double Latitude = 0.0, Longitude = 0.0;

    CityRecord() {}
    CityRecord(std::string s, uint64_t i, double lat, double l) 
        : Name(s), Population(i), Latitude(lat), Longitude(l) {}

    bool operator<(const CityRecord& other) const // < operator defines the unique key inside your actual map
    {
        return Population < other.Population;
    }
};

// Template specialization for std::hash struct that is specific to CityRecord value
// if you attempt to use a custom class as a key in a map, you need to create 
// a template specialization so that the compiler knows how to hash it.
namespace std 
{
    template<>
    struct hash<CityRecord> 
    {
        // call operator comes with hash struct
        size_t operator()(const CityRecord& key) // key that we will be hashing.
        {
            // how the call will be 'hashed', this is by name for simplicity, but latitude and longitude would be better.
            return hash<std::string>()(key.Name); // construct it then call it. 
        }
    };
}

int main()
{
    std::unordered_map<std::string, CityRecord> cityMap;
    
    cityMap["Melbourne"] = CityRecord{"Melbourne", 50000, 2.4, 9.4};   
    cityMap["Lol-town"] = CityRecord {"Lol-town", 50, 2.4, 9.4};
    cityMap["Berlin"] = CityRecord {"Berlin", 250000, 2.4, 9.4};
    cityMap["Paris"] = CityRecord {"Paris", 3000000, 2.4, 9.4};
    cityMap["London"] = CityRecord {"London", 7723828, 2.4, 9.4};

    cityMap.emplace(std::pair("Conord", CityRecord{ "Concord", 30000, 37.3, 47.2 }));   

    // Index operator works differently in C++ than in other languages.
    // There is no const version of insertion operator, C++ will always insert things into map.
    // Insert operator for maps have the ability to mutate objects, via insert
    CityRecord& bostonData = cityMap["Boston"]; // Create a blank reference (entry) and auto insert it into map. *Note below.    
    // reference ^ to already in-place memory, I don't need to set it, just access and fill out the other variables of Boston CityRecord.
    bostonData.Name = "Boston"; // Fill out the reference data directly.  Saves on copying.
    bostonData.Population = 1200000;
    bostonData.Longitude = 178.493;
    bostonData.Latitude = 38.382;
    CityRecord& bData = cityMap.at("Boston"); // To retrieve a copy of data without inserting it, use the at() function.

    const auto& cities = cityMap;
    
    if (cities.find("Boston") != cities.end())
    {
        // CityRecord& bostonData = cities["Boston"]; // Error, creating a new map entry with a new reference variable requires a non-const map.
        const CityRecord& bDataConst = cities.at("Boston"); // Need to use .at() to retrieve data, without inserting it. works on const and non-const alike
    }      

    for (auto& [name, city] : cityMap) // Structure binding (Only available in C++17) 
    {
        std::cout << name << "\n Population: " << city.Population << std::endl; // Not printed in alphabetic order (unordered map)
    }    
        
    std::map<CityRecord, uint32_t> foundedMap; // possible because of template specialization for hashing CityRecord.
    foundedMap[CityRecord{ "Melbourne", 500000, 2.4, 9.4 }] = 1850; //| Illegal Expression?
    // uint32_t melbourneFounded = foundedMap[CityRecord{"Melbourne", 500000, 2.4, 9.4}];
    
    system("pause");
}

// NOTE: References always need to be initialized to a known value, in this *case the value is being created and then it's referenced.
// NOTE2: Iterating through a vector is always faster than iterating through a Map.

/*  // Iterating a map in C++ v14
    for (auto& mp : cityMap) 
    {
        const std::string& name = mp.first;
        CityRecord& city = mp.second;
    }
*/

// The rule is: If you have a variable shared with 2 or more threads, and at least one of those threads modifies said variable, 
// then you need synchronization. Without you have a data race and UB 
// HashMaps v Hashtables v unordered_map - thread safe? synchronization
// Hashtable v Hashmap
// Hashtable is synchronized and thread safe, Hashmap is not.
// Hashmap allows for a NULL key and many NULL values, Hashtables do not.
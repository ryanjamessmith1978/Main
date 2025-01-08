#include "resource.h"
#include <list>

// Object Pool
class ObjectPool {
private:

    ObjectPool() {} // default constructor
    static ObjectPool* instance; // ** NEED to define where it is used.
    std::list<Resource*> resources;

public:
    
     // Static method for accessing class instance.
     // Part of Singleton design pattern.     
     // return ObjectPool instance.    
    static ObjectPool* getInstance() {
        if (instance == 0) {
            instance = new ObjectPool;
        }
        return instance;
    }
    
    // Returns instance of Resource. 
    // New resource will be created if all the resources
    // were used at the time of the request. return Resource instance.     
    Resource* getResource() 
    {
        // resources is a member variable list, checks if a Resource* is empty
        if (resources.empty()) {
            std::cout << "Creating new." << std::endl;
            // if resource list empty, create a new resource and return it.
            return new Resource; 
        }
        else {
            std::cout << "Reusing existing." << std::endl;
            Resource* resource = resources.front();
            resources.pop_front();
            return resource;
        }
    }
    
     // Return resource back to the pool. The resource must be initialized back
     // to the default settings before someone else attempts to use it.
     // param object Resource instance.
     // return void     
    void returnResource(Resource* object) {
        object->reset();
        resources.push_back(object);
    }
};
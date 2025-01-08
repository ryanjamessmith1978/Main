// Adapter.cpp | https://www.youtube.com/watch?v=BLaz_Nct1eI&list=PLk6CEY9XxSIDZhQURp6d8Sgp-A0yKKDKV&index=8
//
// Example: you have an Indian socket but want to plug it into a USA socket.

#include <iostream>
#include <memory>
using namespace std;

// Socket we currently have
class IndianSocket
{
public: // Can only define virtual functions in one socket Type
    // Then in the adapter you override them.
    // In the adapter, you can write as many functions you want to call other socket type functions.
    virtual void indiancharge(int) = 0;
    virtual void myOtherCharge() = 0;
};

// Socket which we want to use
class USASocket
{
public:  
    void usacharge() { std::cout << "USA Plug charging" << std::endl; }  
};

// Socket which we want to use
class GSocket
{
public:
    void germanyCharge() { std::cout << "German Plug adapter used" << std::endl; }

    void gcharge()
    {
        std::cout << "G Plug charging" << std::endl;
    }

    // Need to abstract a virtual function here in order to define in the socket adapter    
};

// This is the adapter, used to charge with USA Socket
class SocketAdapter : public IndianSocket, public USASocket, public GSocket
{
public:
    void myOtherCharge()
    {
        germanyCharge();
    }

    void indiancharge(int type)
    {
        switch (type)
        {
        case 1:
            usacharge();
            break;            
        case 2:
            gcharge();
            break;            
        default:
            break;
        }
    }    
};

int main()
{
    // client only supports Indian Charger.
    //unique_ptr<IndianSocket> socket = make_unique<SocketAdapter>();
    //socket->indiancharge(1); // you don't want to see what's there,
    //socket->indiancharge(2);

    unique_ptr<IndianSocket> socket2 = make_unique<SocketAdapter>();
    socket2->myOtherCharge();

    system("pause");
}

// ADAPTER PATTERN (USB Type A --> USB Type C adapter)
// Client wants to call some API which is not compatible.
// Client calls Paint(x,y); You want to use a library that has a Paint(x,y,z) function.
// Inside of Paint(x,y), there exists an interface adapter that calls Paint(x,y,z) from ext. library.
// Increases complexity by routing your call.
// 
// 
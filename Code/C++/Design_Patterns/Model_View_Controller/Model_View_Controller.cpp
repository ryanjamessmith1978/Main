// Model_View_Controller.cpp | https://www.youtube.com/watch?v=LyoOkle-n50

#include <iostream>
#include <string>

// Everything UI related
// Demonstrate the separation of responsbilities of each component and flow of data.
namespace View 
{
    class UI
    {
    public:
        // We know this goes to the View portion of pattern, but it interacts with the user.
        void prompt(std::string s)
        {
            std::cout << s << std::endl;
        }

        void prompt(int i)
        {
            std::cout << i << std::endl;
        }

        int getInput()
        {
            int x;
            std::cin >> x;
            return x;
        }
    };
};

// Everything data and storage related, and services on that data
namespace Model
{
    class Storage
    {
    private:
        int x;

    public:
        void storeValue(int n)
        {
            x = n;
        }

        int retrieve()
        {
            return x;
        }
    };
};

// Everything that is business logic related
namespace Controller // ViewModel
{
    class Logic
    {
        View::UI* ui;
        Model::Storage* store;

    public:
        Logic(View::UI* u, Model::Storage* s)
        {
            ui = u;
            store = s;

            doLogic();
        }

        void doLogic()
        {
            // ask user for number using UI object (view)
            ui->prompt("Enter a number: ");

            // store number in Storage object (Model)
            int i = ui->getInput();
            store->storeValue(i);

            // retrieve number from storage object (Model)
            int x = store->retrieve();

            // display that to the user using the UI object (view)
            ui->prompt("Here is the number you entered: ");
            ui->prompt(x);
            ui->prompt("\n");
        }
    };
};


int main()
{
    View::UI u;
    Model::Storage s;
    Controller::Logic logic(&u, &s);

    system("pause");
}


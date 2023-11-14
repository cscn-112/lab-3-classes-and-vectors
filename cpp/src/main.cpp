#include <iostream>
#include <string>

#include "lib/employee.h"
#include "lib/app.h"

void app();

int main()
{
    app();

    return 0;
}

void app()
{
    Employee CurrentEmployee;

    const int QUIT_SENTINEL = 5;

    std::string input_buf = "";
    int current_choice = 0;

    std::cout << "Welcome!" << std::endl
              << std::endl;

    while (current_choice != QUIT_SENTINEL)
    {

        std::cout << "1 - Display Employee Info" << std::endl;
        std::cout << "2 - Add Score to Employee Info" << std::endl;
        std::cout << "3 - Create Employee and Save to Memory" << std::endl;
        std::cout << "4 - Save Employee to Disk" << std::endl;

        std::cout << QUIT_SENTINEL << " - Quit" << std::endl
                  << std::endl;

        std::cout << "Choice: ";
        std::cin >> input_buf;

        current_choice = std::stoi(input_buf);

        switch (current_choice)
        {
        case 1:
            CurrentEmployee = display_scores();
            std::cout << "Loaded this employee to memory!" << std::endl;
            break;
        case 2:
            add_score(CurrentEmployee);
            break;
        case 3:
            CurrentEmployee = add_employee();
            break;
        case 4:
            store_scores(CurrentEmployee);
            break;
        case QUIT_SENTINEL:
            std::cout << "Thanks!" << std::endl;
            break;

        default:
            display_scores();
            break;
        }
    }
}

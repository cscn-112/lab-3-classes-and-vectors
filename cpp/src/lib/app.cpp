#include <iostream>

#include "employee.h"

Employee display_scores()
{
    std::string file_title = "";

    std::cout << "Employee ID: ";
    std::cin >> file_title;

    std::fstream EmployeeFile(file_title + ".txt", std::ios::in);

    Employee Emp(EmployeeFile, {false});

    EmployeeFile.close();

    Emp.sort_scores();

    Emp.print_employee_info(std::cout, {true});

    return Emp;
}

std::string add_score(Employee Emp)
{
    std::string score_buf = "0";

    std::cout << "\nEnter a score for the employee: ";
    std::cin >> score_buf;

    if (score_buf != "0")
    {
        Emp.add_score(std::stof(score_buf));
    }

    return score_buf;
}

Employee add_employee()
{
    std::string name, city, id;

    std::cout << "\nEnter employee name: ";
    std::cin >> name;

    std::cout << "\nEnter employee city: ";
    std::cin >> city;

    std::cout << "\nEnter employee ID: ";
    std::cin >> id;

    Employee Emp({name, city, id});

    std::string score_buf = "";
    while (score_buf != "0")
    {
        score_buf = add_score(Emp);
    }

    return Emp;
}

void store_scores(Employee Emp)
{
    std::ofstream OutFile(Emp.get_id() + ".txt");

    Emp.print_employee_info(OutFile, {false});

    OutFile.close();
}

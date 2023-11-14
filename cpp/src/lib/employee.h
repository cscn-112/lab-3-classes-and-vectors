#pragma once

#include <string>
#include <vector>
#include <fstream>

struct EmployeeInfo
{
    std::string name;
    std::string city;
    std::string id;
};

struct PrintInfoOptions {
    bool pretty_print;
};

struct FileOptions {
    bool close_when_complete;
};

class Employee
{
public:
    Employee();
    Employee(EmployeeInfo info);
    Employee(std::fstream &File, FileOptions opts);

    std::string get_name() const;
    std::string get_city() const;
    std::string get_id() const;

    void set_name(std::string employee_name);
    void set_city(std::string employee_city);
    void set_id(std::string employee_id);

    void add_score(float employee_score);
    void sort_scores();
    float average_score() const;
    float min_score() const;
    float max_score() const;
    int num_scores() const;

    void print_employee_info(std::ostream &out, PrintInfoOptions opts) const;

private:
    std::string name;
    std::string city;
    std::string id;

    std::vector<float> Scores;
};

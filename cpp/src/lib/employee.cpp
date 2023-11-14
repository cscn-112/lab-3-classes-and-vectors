#include <algorithm>
#include <numeric>
#include <iostream>

#include "employee.h"
#include "utils.h"

Employee::Employee()
{
    set_name("");
    set_city("");
    set_id("");
}

Employee::Employee(EmployeeInfo info)
{
    set_name(info.name);
    set_city(info.city);
    set_id(info.id);
}

Employee::Employee(std::fstream &File, FileOptions opts)
{
    if (File.fail())
    {
        std::cout << "ERROR: An error occurred when opening the file! Using empty construction procedure..." << std::endl;
        set_name("");
        set_city("");
        set_id("");
        return;
    }

    if (!File.is_open())
    {
        std::cout << "ERROR: Bad filename! Using empty construction procedure..." << std::endl;
        set_name("");
        set_city("");
        set_id("");
        return;
    }

    set_name(read_line(File));
    set_city(read_line(File));
    set_id(read_line(File));

    std::string score_buf = "";
    while (getline(File, score_buf))
    {
        add_score(std::stof(score_buf));
    }

    if (opts.close_when_complete)
    {
        File.close();
    }
}

std::string Employee::get_name() const
{
    return name;
}

std::string Employee::get_city() const
{
    return city;
}

std::string Employee::get_id() const
{
    return id;
}

void Employee::set_name(std::string employee_name)
{
    name = employee_name;
}

void Employee::set_city(std::string employee_city)
{
    city = employee_city;
}

void Employee::set_id(std::string employee_id)
{
    id = employee_id;
}

void Employee::add_score(float employee_score)
{
    Scores.push_back(employee_score);
}

void Employee::sort_scores()
{
    std::sort(Scores.begin(), Scores.end());
}

float Employee::average_score() const
{
    float initial_value = 0.0;

    float total = std::accumulate(Scores.begin(), Scores.end(), initial_value, std::plus<float>());

    return (total / num_scores());
}

float Employee::min_score() const
{
    float initial_value = Scores.at(0);

    return std::accumulate(Scores.begin(), Scores.end(), initial_value, less_than);
}

float Employee::max_score() const
{
    float initial_value = Scores.at(0);

    return std::accumulate(Scores.begin(), Scores.end(), initial_value, greater_than);
}

int Employee::num_scores() const
{
    return Scores.size();
}

void Employee::print_employee_info(std::ostream &out, PrintInfoOptions opts) const
{
    if (opts.pretty_print)
    {
        out << "=== Info ===" << std::endl;
    }
    out << get_name() << std::endl;
    out << get_city() << std::endl;
    out << get_id() << std::endl;

    if (opts.pretty_print)
    {
        out << "=== Stats ===" << std::endl;
        out << "Avg: " << average_score() << std::endl;
        out << "Min: " << min_score() << std::endl;
        out << "Max: " << max_score() << std::endl;
    }

    if (opts.pretty_print)
    {
        out << "=== Scores ===" << std::endl;
    }
    for (float score : Scores)
        out << score << std::endl;
}

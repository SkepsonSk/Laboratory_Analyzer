#include <iostream>
#include "arithmetic_operation.h"
#include "../../program/program.h"

program_state arithmetic_operation::run(icsv* csv) {
    std::cout << "Select column to perform calculations on: " << std::endl;
    std::cout << "Available columns: ";
    for (auto &c : csv->get_columns()) {
        std::cout << c.get_name() << " ";
    }
    std::cout << std::endl;

    std::string column_name;
    std::cin >> column_name;

    column* c;
    try {
        c = csv->get_column(column_name);
        c->calc_bas_arith_properties();
    } catch (std::invalid_argument& err) {
        program::get_program()->set_error("No column found.");
        return FAIL;
    } catch (std::runtime_error& err) {
        program::get_program()->set_error("Column is not suitable for calculations.");
        return FAIL;
    }

    std::cout << "Basic Arithmetic Properties for column " << c->get_name() << ":" << std::endl;
    std::cout << "Average of values: " << c->get_avg() << ":" << std::endl;
    std::cout << "Median: " << c->get_median() << ":" << std::endl;
    std::cout << "Standard Deviation: " << c->get_std_deviation() << ":" << std::endl;

    return OK;
}

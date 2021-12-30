#include "program.h"

#include <iostream>

program* program::instance = nullptr;

void program::register_operation(operation* o) {
    this->operations.push_back(o);
}

program_state program::run() {
    std::cout << "Data file status: " << this->get_data_status() << std::endl << std::endl;

    if (this->csv != nullptr) {
        std::cout << "Choose an operation to perform: " << std::endl;
        for (auto & o : this->operations) {
            std::cout << o->get_operation_name() << " -> " << o->get_operation_desc() << std::endl;
        }

        std::string operation_name;
        std::cin >> operation_name;

        program_state state;

        try {
            operation* o = this->get_operation(operation_name);
            state = o->run(this->csv);
        } catch (std::invalid_argument& e) {
            this->set_error("No such operation found.");
            return FAIL;
        }

        return state;

    }
    else {
        std::string file_name;

        std::cout << "Please, enter the data file name:" << std::endl;
        std::cin >> file_name;

        try {
            this->csv = new icsv(file_name);
        } catch (std::invalid_argument& err) {
            this->csv = nullptr;
            std::cout << "An error occurred: " << err.what() << std::endl;
        }

        return OK;
    }
}

operation* program::get_operation(const std::string& operation_name) {
    for (auto &o : this->operations) {
        if (o->get_operation_name() == operation_name) {
            return o;
        }
    }

    throw std::invalid_argument("Unknown operation.");
}

void program::set_error(std::string err) {
    this->error = std::move(err);
}

std::string program::get_error() {
    return this->error;
}

program *program::get_program() {
    if (program::instance == nullptr) {
        program::instance = new program;
    }
    return program::instance;
}

void program::clear_error() {
    this->error = nullptr;
}

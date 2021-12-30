#ifndef LAB_OPERATION_H
#define LAB_OPERATION_H


#include <string>
#include <utility>
#include <iostream>
#include "../icsv.h"
#include "../program/program_state.h"

class operation {

private:
    std::string operation_name;
    std::string operation_desc;

public:
    explicit operation(std::string operation_name, std::string operation_desc)
        :operation_name(std::move(operation_name)), operation_desc(std::move(operation_desc)) {};

    virtual program_state run(icsv* csv) { return OK; };

    std::string get_operation_name();
    std::string get_operation_desc();
};


#endif //LAB_OPERATION_H

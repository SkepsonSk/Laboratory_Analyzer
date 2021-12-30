#ifndef LAB_PROGRAM_H
#define LAB_PROGRAM_H


#include <string>
#include "../operation/operation.h"
#include "program_state.h"

class program {

private:
    static program* instance;

    icsv* csv = nullptr;
    std::vector<operation*> operations;

    std::string get_data_status() {
        return this->csv == nullptr ? "NOT LOADED" : "LOADED";
    }

    std::string error;

public:
    static program* get_program();

    void register_operation(operation* o);
    program_state run();

    operation* get_operation(const std::string& operation_name);

    void set_error(std::string err);
    std::string get_error();
    void clear_error();
};


#endif //LAB_PROGRAM_H
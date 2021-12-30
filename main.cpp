#include "obj/icsv.h"
#include "obj/program/program.h"
#include "obj/operation/operations/arithmetic_operation.h"
#include "obj/operation/operations/z2_avg_deviation_operation.h"
#include "obj/operation/operations/cross_correlation_operation.h"
#include "obj/operation/operations/halt_operation.h"

program* init();

int main() {
    program* p = init();
    program_state state;

    do {
        state = p->run();

        if (state == FAIL) {
            std::cout << "An error occurred: " << p->get_error() << std::endl;
            state = OK;
        }
    } while (state == OK);

    return 0;
}

program* init() {
    program* p = program::get_program();
    p->register_operation(new arithmetic_operation());
    p->register_operation(new z2_avg_deviation_operation());
    p->register_operation(new cross_correlation_operation());
    p->register_operation(new halt_operation());
    return p;
}
#include "halt_operation.h"

program_state halt_operation::run(icsv *csv) {
    std::cout << "Bye" << std::endl;
    return HALT;
}

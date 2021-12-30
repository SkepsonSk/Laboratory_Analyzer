#ifndef LAB_ARITHMETIC_OPERATION_H
#define LAB_ARITHMETIC_OPERATION_H


#include "../operation.h"

class arithmetic_operation : public operation {

public:
    program_state run(icsv* csv) override;

    arithmetic_operation()
    : operation("arithmetic",
                "Calculates basic arithmetic properties (avg, std deviation, median)") {};

};


#endif //LAB_ARITHMETIC_OPERATION_H

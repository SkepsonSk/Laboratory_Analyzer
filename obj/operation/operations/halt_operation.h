#ifndef LAB_HALT_OPERATION_H
#define LAB_HALT_OPERATION_H


#include "../operation.h"

class halt_operation : public operation {

public:
    program_state run(icsv* csv) override;

    halt_operation()
            : operation("halt",
                        "Halts and exits the program.") {};

};


#endif //LAB_HALT_OPERATION_H

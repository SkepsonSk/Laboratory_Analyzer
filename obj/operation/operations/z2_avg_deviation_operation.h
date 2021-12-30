#ifndef LAB_Z2_AVG_DEVIATION_OPERATION_H
#define LAB_Z2_AVG_DEVIATION_OPERATION_H


#include "../operation.h"

class z2_avg_deviation_operation : public operation {

public:
    program_state run(icsv* csv) override;

    z2_avg_deviation_operation()
            : operation("z2_avg_dev",
                        "Calculates the deviation between the given value and Z2 col. average of its values.") {};

};


#endif //LAB_Z2_AVG_DEVIATION_OPERATION_H

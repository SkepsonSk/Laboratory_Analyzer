#ifndef LAB_CROSS_CORRELATION_OPERATION_H
#define LAB_CROSS_CORRELATION_OPERATION_H


#include "../operation.h"

class cross_correlation_operation : public operation {

private:
    static std::vector<double>* read_add_num_file(const std::string& file_name);
    static double calc_cross_correlation(const std::vector<double>& nums, const std::vector<double>& add_nums);
    static double avg(const std::vector<double>& vec);

public:
    program_state run(icsv* csv) override;

    cross_correlation_operation()
            : operation("cross_correlation",
                        "Calculates the cross correlation between the 10 rows and 10 numbers from a text file.") {};

};


#endif //LAB_CROSS_CORRELATION_OPERATION_H

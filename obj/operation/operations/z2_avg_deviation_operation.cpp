#include "z2_avg_deviation_operation.h"

program_state z2_avg_deviation_operation::run(icsv *csv) {
    column* col = csv->get_column("Z2");
    col->calc_bas_arith_properties();

    std::cout << "To calculate avg. deviation provide the value of the deviation." << std::endl;
    std::cout << "The values between the following borders will be returned: (avg-r, avg+r)" << std::endl << std::endl;
    std::cout << "Deviation:" << std::endl;

    double r,
           avg = col->get_avg();
    std::cin >> r;

    double bot_border = avg-r;
    double top_border = avg+r;

    int c = 0;
    for (auto & v : col->get_values()) {
        if (v >= bot_border && v <= top_border) {
            std::cout << v << " ";
            c++;
        }
    }

    std::cout << std::endl << "Summary" << std::endl;
    std::cout << "There is " << c << " values in the given range." << std::endl;

    return OK;
}

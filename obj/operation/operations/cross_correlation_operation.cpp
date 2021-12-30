#include <fstream>
#include <valarray>
#include "cross_correlation_operation.h"
#include "../../program/program.h"

program_state cross_correlation_operation::run(icsv *csv) {

    std::cout << "The operation needs additional numeric data from a external file." << std::endl;
    std::cout << "as well as 10 rows from the loaded data file." << std::endl << std::endl;

    std::cout << "1.1. Provide the column name" << std::endl;
    std::cout << "(Available columns: ";
    for (auto &c : csv->get_columns()) {
        std::cout << c.get_name() << " ";
    }
    std::cout << "):" << std::endl;

    std::string column_name;
    std::cin >> column_name;

    column* c;
    try {
        c = csv->get_column(column_name);
        c->calc_bas_arith_properties();
    } catch (std::invalid_argument& err) {
        program::get_program()->set_error("No column found.");
        return FAIL;
    } catch (std::runtime_error& err) {
        program::get_program()->set_error("Column is not suitable for calculations.");
        return FAIL;
    }

    std::cout << "1.2. Provide the ord. num. of the row to get the next 9" << std::endl;
    std::cout << "(Accepting from 0 to " << c->get_rows()-10 << ")" << std::endl;

    int row_num;
    std::cin >> row_num;

    if (row_num < 0 || row_num > c->get_rows()-10) {
        program::get_program()->set_error("Invalid ord. row number. The value is either negative or beyond the range.");
        return FAIL;
    }

    std::vector<double> row_nums;
    for (int i = row_num ; i < row_num+10 ; i++) {
        row_nums.push_back(c->get_values()[i]);
    }

    std::cout << "2. Provide the name of the file containing the additional numeric information:" << std::endl;

    std::string file_name;
    std::cin >> file_name;

    auto* nums = read_add_num_file(file_name);

    double correlation = calc_cross_correlation(row_nums, *nums);

    std::cout << "The cross correlation is " << correlation << std::endl;

    return OK;
}

std::vector<double>* cross_correlation_operation::read_add_num_file(const std::string& file_name) {
    std::ifstream fin(file_name);
    if (fin.good()) {

        auto* nums = new std::vector<double>;

        double num;
        int c = 0;
        while (!fin.eof()) {
            fin >> num;
            nums->push_back(num);
            c++;
        }

        return nums;

    }

    throw std::invalid_argument("Cannot open a file under the given name.");
}

double cross_correlation_operation::calc_cross_correlation(const std::vector<double> &nums,
                                                           const std::vector<double> &add_nums) {

    double nums_avg = avg(nums);
    double add_nums_avg = avg(add_nums);

    double meter = 0, denominator_num = 0, denominator_add_nums = 0;

    for (int i = 1 ; i <= 10 ; i++) {
        meter += (std::pow(nums[i], i) - nums_avg) * (std::pow(add_nums[i], i) - add_nums_avg);
        denominator_num += std::pow(nums[i] - nums_avg, 2);
        denominator_add_nums += std::pow(add_nums[i] - add_nums_avg, 2);
    }

    return meter / std::sqrt(denominator_num * denominator_add_nums);
}

double cross_correlation_operation::avg(const std::vector<double> &vec) {
    double s = 0;
    for (auto& v : vec) {
        s += v;
    }
    return s/(double) vec.size();
}

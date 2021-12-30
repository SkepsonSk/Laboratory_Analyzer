#ifndef LAB_COLUMN_H
#define LAB_COLUMN_H


#include <string>
#include <utility>
#include <vector>

class column {

private:
    std::string name;
    std::vector<double> values;

    double avg{};
    double median{};
    double std_deviation{};

    void calc_avg();
    void calc_median();
    void calc_std_deviation();

public:
    explicit column(std::string name):
            name(std::move(name)) {};

    void add_value(double value);

    std::string get_name();
    std::vector<double> get_values();

    void calc_bas_arith_properties();

    double get_avg() const;
    double get_median() const;
    double get_std_deviation() const;

    unsigned long long get_rows();
};


#endif //LAB_COLUMN_H

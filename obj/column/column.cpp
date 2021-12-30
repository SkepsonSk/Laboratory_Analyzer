#include <algorithm>
#include <iostream>
#include <valarray>
#include "column.h"

void column::add_value(double value) {
    this->values.push_back(value);
}

std::string column::get_name() {
    return this->name;
}

std::vector<double> column::get_values() {
    return this->values;
}

double column::get_avg() const {
    return this->avg;
}

double column::get_median() const {
    return this->median;
}

double column::get_std_deviation() const {
    return this->std_deviation;
}

void column::calc_avg() {
    this->avg = 0;
    for (auto &v : this->values) {
        this->avg += v;
    }
    this->avg /= (double) this->values.size();
}

void column::calc_median() {
    std::vector<double> val_copy = this->values;
    std::sort (val_copy.begin(), val_copy.end());

    int n = (int) val_copy.size();

    if (n % 2 == 0) {
        this->median = (val_copy[(n-1)/2] + val_copy[n/2]) / 2.0;
    }
    else {
        this->median = val_copy[n/2];
    }
}

void column::calc_std_deviation() {
    this->std_deviation = 0;

    for (auto& v : this->values) {
        this->std_deviation += std::pow(v - this->avg, 2);
    }

    auto n = (double) this->values.size();
    this->std_deviation = std::sqrt( this->std_deviation/n );
}

void column::calc_bas_arith_properties() {
    if (!this->values.empty()) {
        this->calc_avg();
        this->calc_median();
        this->calc_std_deviation();
    }
    else {
        throw std::runtime_error("Column has no values.");
    }
}

unsigned long long column::get_rows() {
    return this->values.size();
}

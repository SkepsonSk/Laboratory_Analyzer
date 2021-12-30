#include <fstream>
#include <sstream>
#include <iostream>
#include <utility>
#include "icsv.h"

void icsv::read(const std::string& text) {
    std::ifstream fin;
    fin.open(text);

    if (!fin.good()) {
        throw std::invalid_argument("Cannot find file under the given name.");
    }

    std::string temp, line, element;

    bool col_names = true;
    while (fin >> temp) {
        std::getline(fin, line);
        std::stringstream ss(temp + line);

        int counter = 0;
        while (getline(ss, element, ',')) {
            if (col_names) {
                column col(element + "");
                //col.name = element + "";
                this->columns.push_back(col);
            }
            else {
                this->parse_entry(element + "", counter);
                counter++;
            }

            //std::cout << element << " | ";
        }

        if (col_names) {
            col_names = false;
        }
        //std::cout << std::endl;

    }
}

column* icsv::get_column(const std::string &name) {
    for (auto & col : this->columns) {
        if (col.get_name() == name) {
            return &col;
        }
    }

    throw std::invalid_argument("Cannot find column under given name.");
}

std::vector<column> icsv::get_columns() const {
    return this->columns;
}

void icsv::parse_entry(const std::string& element, int counter) {
    if (counter != 8 && counter != 9) {
        this->columns[counter].add_value(std::stod(element));
    }
}
#ifndef LAB_ICSV_H
#define LAB_ICSV_H

#include <string>
#include <vector>
#include "column/column.h"

class icsv {

private:
    std::vector<column> columns;

    void read(const std::string& text);
    void parse_entry(const std::string& element, int counter);

public:
    explicit icsv(const std::string& text) {
        this->read(text);
    }

    column* get_column(const std::string& name);

    std::vector<column> get_columns() const;
};


#endif //LAB_ICSV_H

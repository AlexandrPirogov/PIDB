#pragma once
#include <string>
#include "Row.h"
#include "Table.h"

class crudTable : public Table
{
    public:
        crudTable(std::string name);
        ~crudTable();

        void create();
        void drop();
        void update();

        int get_create_status();
        int get_drop_status();
        int get_update_status();
    private:
    protected:
};

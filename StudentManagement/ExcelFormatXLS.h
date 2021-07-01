#pragma once
#include "ISupportedExcel.h"
class ExcelFormatXLS :
    public ISupportedExcel
{
public:
    vector<string> readFile(string link);
    bool writeFile(string link, vector<string> input, vector<string> columnsName);
};


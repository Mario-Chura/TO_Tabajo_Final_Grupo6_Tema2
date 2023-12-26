#ifndef CSV_PARSER_H
#define CSV_PARSER_H

#include <fstream>
#include <sstream>
#include <vector>
#include "PacienteData.h"

class CsvParser {
public:
    static std::vector<PacienteData> parseCsv(const std::string& filename);
};

#endif // CSV_PARSER_H

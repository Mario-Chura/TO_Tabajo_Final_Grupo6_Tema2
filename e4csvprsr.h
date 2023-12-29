#ifndef E4CSVPRSR_H
#define E4CSVPRSR_H
#include <fstream>
#include <sstream>
#include <vector>
#include "e4paciente.h"

class e4csvprsr
{
public:
    static std::vector<e4paciente> parseCsv(const std::string& filename);
};

#endif // E4CSVPRSR_H

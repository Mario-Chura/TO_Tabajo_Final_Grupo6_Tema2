#ifndef E2CSVPRSR_H
#define E2CSVPRSR_H
#include <fstream>
#include <sstream>
#include <vector>
#include "e2paciente.h"

class e2csvprsr
{
public:
 static std::vector<e2paciente> parseCsv(const std::string& filename);
};

#endif // E2CSVPRSR_H

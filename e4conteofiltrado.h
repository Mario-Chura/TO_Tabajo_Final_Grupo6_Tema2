#ifndef E4CONTEOFILTRADO_H
#define E4CONTEOFILTRADO_H
#include <vector>
#include <QStringList>
#include "e4paciente.h"

class e4conteofiltrado
{
public:

    std::vector<QStringList> realizarConteo(const std::vector<e4paciente>& dataVector);
};

#endif // E4CONTEOFILTRADO_H

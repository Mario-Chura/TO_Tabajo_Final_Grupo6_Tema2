#ifndef E2CONTEOFILTRADO_H
#define E2CONTEOFILTRADO_H
#include <vector>
#include <QStringList>
#include "e2paciente.h"

class e2conteofiltrado
{
public:

    std::vector<QStringList> realizarConteo(const std::vector<e2paciente>& dataVector);
    };

#endif // E2CONTEOFILTRADO_H

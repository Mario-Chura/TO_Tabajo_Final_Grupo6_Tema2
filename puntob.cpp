#include "puntob.h"
#include "ui_puntob.h"
#include "QPdfWriter"
#include "QPainter"
#include "QMessageBox"
#include "QDesktopServices"
#include "QUrl"
#include <QFile>

puntob::puntob(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::puntob)
{
    ui->setupUi(this);
}

puntob::~puntob()
{
    delete ui;
}

void puntob::on_pushButton_clicked()
{
    std::vector<PacienteData> dataVector = CsvParser::parseCsv("p2.csv");
    ConteoFiltrado::realizarConteo(dataVector);

}


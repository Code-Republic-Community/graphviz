#include "graphviz.h"
#include "./ui_graphviz.h"

GraphViz::GraphViz(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::GraphViz)
{
    ui->setupUi(this);
}

GraphViz::~GraphViz()
{
    delete ui;
}


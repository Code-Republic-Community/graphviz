#ifndef GRAPHVIZ_H
#define GRAPHVIZ_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class GraphViz; }
QT_END_NAMESPACE

class GraphViz : public QMainWindow
{
    Q_OBJECT

public:
    GraphViz(QWidget *parent = nullptr);
    ~GraphViz();

private:
    Ui::GraphViz *ui;
};
#endif // GRAPHVIZ_H

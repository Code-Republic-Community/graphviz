#include "graphviz.h"

#include <QApplication>

//int main(int argc, char *argv[])
//{
//    QApplication a(argc, argv);
//    GraphViz w;
//    w.show();
//    return a.exec();
//}

#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <QGraphicsView>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QDebug>
#include <QFile>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Read graph data from export.json
    QFile file("export.json");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Failed to open file";
        return -1;
    }
    // Seed the random number generator
    srand(11);

    QJsonParseError jsonError;
    QJsonDocument jsonDoc = QJsonDocument::fromJson(file.readAll(), &jsonError);
    if (jsonError.error != QJsonParseError::NoError) {
        qDebug() << "Failed to parse JSON:" << jsonError.errorString();
        return -1;
    }

    QGraphicsScene scene;
    QGraphicsView view(&scene);
    view.setWindowTitle("GraphViz");
    view.setRenderHint(QPainter::Antialiasing);
    view.setDragMode(QGraphicsView::ScrollHandDrag);

    // Parse graph data
    QJsonObject graphObj = jsonDoc.object();

    // Define variables for positioning the graphs
    int cur_row = 0;
    int cur_col = 0;

    for (auto it = graphObj.begin(); it != graphObj.end(); ++it) {
        QString graphName = it.key();
        QJsonObject graphData = it.value().toObject();

        QJsonArray nodeArray = graphData["node"].toArray();
        QMap<int, QPointF> nodeMap;


        // Add nodes to the scene
        for (auto nodeIt = nodeArray.begin(); nodeIt != nodeArray.end(); ++nodeIt) {
            int nodeId = nodeIt->toInt();
            QJsonObject nodeObj = graphData[QString::number(nodeId)].toObject();
            int nodeValue = nodeObj["value"].toInt();

//            QPointF pos(rand() % 800, rand() % 800);

            // Calculate the position of the node based on its column and row
            QPointF pos(cur_col + rand()%100, cur_row + rand()%50);
            cur_col += 100;
            cur_row += 50;
            nodeMap[nodeId] = pos;
            QGraphicsEllipseItem* nodeItem = new QGraphicsEllipseItem(QRectF(-15, -15, 20, 20));
            nodeItem->setPos(pos);
            nodeItem->setBrush(Qt::black);

            // Create a text item to show the node's id and value
            QGraphicsTextItem* textItem = new QGraphicsTextItem(QString("id: %1\nvalue: %2").arg(nodeId).arg(nodeValue));
            textItem->setPos(pos + QPointF(-10, -25)); // Position the text above the node
            textItem->setDefaultTextColor(Qt::white);

            // Add the text item to the node's parent item
            QGraphicsItemGroup* groupItem = new QGraphicsItemGroup();
            groupItem->addToGroup(nodeItem);
            groupItem->addToGroup(textItem);
            scene.addItem(groupItem);
        }

        // Add graph name to the scene
        QGraphicsTextItem* graphNameItem = new QGraphicsTextItem(graphName);
        graphNameItem->setPos(nodeMap.first() + QPointF(-50, -50));
        scene.addItem(graphNameItem);

        // Add edges to the scene
        for (auto nodeIt = nodeArray.begin(); nodeIt != nodeArray.end(); ++nodeIt) {
            int srcNodeId = nodeIt->toInt();
            QJsonObject srcNodeObj = graphData[QString::number(srcNodeId)].toObject();
            QJsonArray neighborArray = srcNodeObj["neighbors"].toArray();

            for (auto neighborIt = neighborArray.begin(); neighborIt != neighborArray.end(); ++neighborIt) {
                int destNodeId = neighborIt->toInt();
                QGraphicsLineItem* edgeItem = new QGraphicsLineItem(QLineF(nodeMap[srcNodeId], nodeMap[destNodeId]));
                edgeItem->setPen(QPen(Qt::red));
                scene.addItem(edgeItem);
            }
        }
    }

    view.fitInView(scene.sceneRect(), Qt::KeepAspectRatio);
    view.show();

    return a.exec();
}


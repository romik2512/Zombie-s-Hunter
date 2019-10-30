#ifndef BAM_H
#define BAM_H

#include <QGraphicsPixmapItem>
#include <QObject>
class Bam: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
        Bam(QGraphicsItem*parent=nullptr);
public slots:
      void deletebam();
};

#endif // BAM_H

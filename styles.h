#ifndef STYLES_H
#define STYLES_H

#include <QObject>

class Styles : public QObject
{
    Q_OBJECT
public:
    explicit Styles(QObject *parent = 0);
    static QString getElegantGnomeStyle();

signals:

public slots:

};

#endif // STYLES_H

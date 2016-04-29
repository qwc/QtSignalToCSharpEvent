#ifndef MANAGEDCPP_H
#define MANAGEDCPP_H

#include <QObject>
#include <QList>
#include "PureQt_global.h"

class PUREQTSHARED_EXPORT PureQt : public QObject
{
    Q_OBJECT

public:
    PureQt(QString name);
    ~PureQt(){}
    QString getSomeVar();
    void someFunc(const QString & string);
public slots:
signals:
    void someFuncWasCalled(const QString &string);
private:
    QString someVar;
};

#endif // MANAGEDCPP_H

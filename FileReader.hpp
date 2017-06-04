#ifndef FILE_READER_HPP
#define FILE_READER_HPP

#include <QObject>
#include <QVector>

#include "CpuCore.hpp"

class FileReader : public QObject
{
    Q_OBJECT
public:
    explicit FileReader(QObject *parent = 0);

    QVector<CpuCore> readAndParseFile() const;
};

#endif

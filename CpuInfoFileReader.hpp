#ifndef CPU_INFO_FILEREADER_HPP
#define CPU_INFO_FILEREADER_HPP

#include "CpuCore.hpp"
#include <QVector>

/**
 * @brief The CpuInfoFileReader class reads
 * and parses contents of /proc/cpuinfo file
 * in Linux operating system
 */
class CpuInfoFileReader
{
public:
    CpuInfoFileReader();

    QVector<CpuCore> readAndParse() const;
};

#endif

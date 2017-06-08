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
    /**
     * @brief CpuInfoFileReader Ctor
     * @param filename Input filename for reader
     */
    CpuInfoFileReader(const QString& filename);

    /**
     * @brief readAndParse Reads and parses contents of file
     * @return Returns vector of CpuCore data structs
     */
    QVector<CpuCore> readAndParse() const;

private:
    QString m_filename;
};

#endif

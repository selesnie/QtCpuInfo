#include "FileReader.hpp"

#include <QDir>
#include <QTextStream>

FileReader::FileReader(QObject *parent)
    : QObject(parent)
{
}

QVector<CpuCore> FileReader::readAndParseFile() const
{
    QFile cpuInfoFile("/proc/cpuinfo");

    if (!cpuInfoFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        throw std::runtime_error("Error opening " + cpuInfoFile.fileName().toLatin1());
    }

    QTextStream inputFileStream(&cpuInfoFile);
    QString line = inputFileStream.readLine();

    QVector<CpuCore> cpuCoreVec;
    CpuCore cpuCore;

    while (!line.isNull())
    {
        if (line.contains("processor"))
        {
            cpuCore = CpuCore();
            cpuCore.processor = line.split(':').last();
        }
        else
        {
            if (line.contains("vendor_id"))
            {
                cpuCore.vendor = line.split(':').last();
            }

            if (line.contains("model name"))
            {
                cpuCore.model = line.split(':').last();
            }

            if (line.contains("cpu MHz"))
            {
                cpuCore.clockFreqMhz = line.split(':').last();
                cpuCoreVec.push_back(cpuCore);
            }
        }

        line = inputFileStream.readLine();
    }

    return cpuCoreVec;
}

#include "CpuInfoFileReader.hpp"

#include <QFile>
#include <QTextStream>

CpuInfoFileReader::CpuInfoFileReader(const QString& filename)
    : m_filename(filename)
{
}

QVector<CpuCore> CpuInfoFileReader::readAndParse() const
{
    QFile cpuInfoFile(m_filename);

    if (!cpuInfoFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        //Throw exception and terminate application if file cannot be opened.
        throw std::runtime_error("Error opening " + cpuInfoFile.fileName().toLatin1());
    }

    //Read and parse file line by line
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
            cpuCore.processor.trimmed();
        }
        else
        {
            if (line.contains("vendor_id"))
            {
                cpuCore.vendor = line.split(':').last();
                cpuCore.vendor.trimmed();
            }

            if (line.contains("model name"))
            {
                cpuCore.model = line.split(':').last();
                cpuCore.model.trimmed();
            }

            if (line.contains("cpu MHz"))
            {
                cpuCore.clockFreqMhz = line.split(':').last().trimmed();
            }

            if (line.contains("cache size"))
            {
                cpuCore.cacheSize = line.split(':').last().trimmed();
            }

            if (line.contains("flags"))
            {
                cpuCore.flags = line.split(':').last().trimmed();
            }

            if (line.contains("cpu family"))
            {
                cpuCore.cpuFamily = line.split(':').last().trimmed();
            }

            if (line.contains("bogomips"))
            {
                cpuCore.bogoMips = line.split(':').last().trimmed();
            }

            if (line.contains("power management"))
            {
                //This is last item we are interested in.
                //Add cpuCore in the vector
                cpuCoreVec.push_back(cpuCore);
            }
        }

        //Read next line
        line = inputFileStream.readLine();
    }

    return cpuCoreVec;
}

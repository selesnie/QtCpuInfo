#include "CpuInfoDataModel.hpp"

#include "CpuInfoFileReader.hpp"

namespace {
constexpr auto TIMER_INTERVAL_MILLISECONDS = 2000;
}

CpuInfoDataModel::CpuInfoDataModel(const QString& filename, QObject *parent)
    : QAbstractListModel(parent),
      m_filename(filename),
      m_timerCallback()
{
    addFileContentsToDataModel();

    //Register timer callback function that is called
    //when timer elapses
    m_timerCallback.registerTimerElapsedCallback([this]()
    {
        addFileContentsToDataModel();
    });

    m_timerCallback.start(TIMER_INTERVAL_MILLISECONDS);
}

void CpuInfoDataModel::addDataToModel(const QVector<CpuCore>& cpuCoreVec)
{
    beginInsertRows(QModelIndex(), rowCount(), rowCount());

    for (const auto& cpuCore : cpuCoreVec)
    {
        m_cpuCores << cpuCore;
    }

    endInsertRows();
}

void CpuInfoDataModel::updateDataInModel(const QVector<CpuCore>& cpuCoreVec)
{
    auto columnIndex = 0;

    for (const auto& cpuCore : cpuCoreVec)
    {
        m_cpuCores[columnIndex++] = cpuCore;
    }

    //Indicate that model's columns have been updated
    emit dataChanged(index(0), index(columnIndex - 1));
}

void CpuInfoDataModel::addOrUpdateDataModel(const QVector<CpuCore>& cpuCoreVec)
{
    if (m_cpuCores.empty())
    {
        //Data model is empty, insert columns in the model
        addDataToModel(cpuCoreVec);
    }
    else
    {
        //Data model already has all its items (columns)
        //so its enough just update the model
        updateDataInModel(cpuCoreVec);
    }
}

int CpuInfoDataModel::rowCount(const QModelIndex & parent) const
{
    Q_UNUSED(parent);
    return m_cpuCores.count();
}

QVariant CpuInfoDataModel::data(const QModelIndex & index, int role) const
{
    if (index.row() < 0 || index.row() >= m_cpuCores.count())
    {
        return QVariant();
    }

    const CpuCore &cpuCore = m_cpuCores[index.row()];

    switch (role)
    {
    case ProcessorIdRole:
        return cpuCore.processor;
    case VendorRole:
        return cpuCore.vendor;
    case ModelNameRole:
        return cpuCore.model;
    case ClockFreqRole:
        return cpuCore.clockFreqMhz;
    case CacheSize:
        return cpuCore.cacheSize;
    case Flags:
        return cpuCore.flags;
    case CpuFamily:
        return cpuCore.cpuFamily;
    case BogoMips:
        return cpuCore.bogoMips;
    }

    return QVariant();
}

QHash<int, QByteArray> CpuInfoDataModel::roleNames() const
{
    QHash<int, QByteArray> roles;

    roles[ProcessorIdRole] = "processor";
    roles[VendorRole] = "vendor";
    roles[ModelNameRole] = "model";
    roles[ClockFreqRole] = "clockFreqMhz";
    roles[CacheSize] = "cacheSize";
    roles[Flags] = "cpuFlags";
    roles[CpuFamily] = "cpuFamily";
    roles[BogoMips] = "bogoMips";

    return roles;
}

void CpuInfoDataModel::addFileContentsToDataModel()
{
    CpuInfoFileReader cpuInfoFileReader(m_filename);
    QVector<CpuCore> cpuCoreVec = cpuInfoFileReader.readAndParse();

    addOrUpdateDataModel(cpuCoreVec);
}

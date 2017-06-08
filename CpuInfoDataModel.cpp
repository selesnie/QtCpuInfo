#include "CpuInfoDataModel.hpp"

#include "CpuInfoFileReader.hpp"

namespace {
constexpr auto TIMER_INTERVAL_MILLISECONDS = 2000;
}

CpuInfoDataModel::CpuInfoDataModel(QObject *parent)
    : QAbstractListModel(parent),
      m_timerCallback()
{
    addFileContentsToDataModel();

    //Register timer callback function that is called
    //when timer elapses
    m_timerCallback.registerTimerElapsedCallback([this]()
    {
        resetDataModel();
        addFileContentsToDataModel();
    });

    m_timerCallback.start(TIMER_INTERVAL_MILLISECONDS);
}

void CpuInfoDataModel::addToDataModel(const CpuCore &cpuCore)
{
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    m_cpuCores << cpuCore;
    endInsertRows();
}

void CpuInfoDataModel::resetDataModel()
{
    beginResetModel();
    m_cpuCores.clear();
    endResetModel();
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

    return roles;
}

void CpuInfoDataModel::addFileContentsToDataModel()
{
    CpuInfoFileReader cpuInfoFileReader;
    QVector<CpuCore> cpuCoreVec = cpuInfoFileReader.readAndParse();

    for (const auto& cpuCore : cpuCoreVec)
    {
        addToDataModel(cpuCore);
    }
}

#include "CpuDataModel.hpp"

CpuDataModel::CpuDataModel(QObject *parent)
    : QAbstractListModel(parent)
{
}

void CpuDataModel::addToModel(const CpuCore &CpuCore)
{
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    m_cpuCores << CpuCore;
    endInsertRows();
}

void CpuDataModel::clearModel()
{
    m_cpuCores.clear();
}

int CpuDataModel::rowCount(const QModelIndex & parent) const
{
    Q_UNUSED(parent);
    return m_cpuCores.count();
}

QVariant CpuDataModel::data(const QModelIndex & index, int role) const
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

QHash<int, QByteArray> CpuDataModel::roleNames() const
{
    QHash<int, QByteArray> roles;

    roles[ProcessorIdRole] = "processor";
    roles[VendorRole] = "vendor";
    roles[ModelNameRole] = "model";
    roles[ClockFreqRole] = "clockFreqMhz";

    return roles;
}

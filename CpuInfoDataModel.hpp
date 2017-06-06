#ifndef CPU_INFO_DATAMODEL_HPP
#define CPU_INFO_DATAMODEL_HPP

#include "CpuCore.hpp"
#include "TimerCallback.hpp"

#include <QAbstractListModel>

class CpuInfoDataModel : public QAbstractListModel
{
    Q_OBJECT
public:
    enum ProcessorRoles
    {
        ProcessorIdRole = Qt::UserRole + 1,
        VendorRole,
        ModelNameRole,
        ClockFreqRole
    };

    explicit CpuInfoDataModel(QObject *parent = 0);

    int rowCount(const QModelIndex & parent = QModelIndex()) const override;
    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const override;

    void addToDataModel(const CpuCore &CpuCore);
    void resetDataModel();

protected:
    QHash<int, QByteArray> roleNames() const override;

private:
    void addFileContentsToDataModel();

    QList<CpuCore> m_cpuCores;
    TimerCallback m_timerCallback;
};

#endif

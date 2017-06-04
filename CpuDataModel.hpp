#ifndef CPU_DATAMODEL_HPP
#define CPU_DATAMODEL_HPP

#include "CpuCore.hpp"

#include <QAbstractListModel>

class CpuDataModel : public QAbstractListModel
{
    Q_OBJECT
public:
    enum ProcessorRoles {
        ProcessorIdRole = Qt::UserRole + 1,
        VendorRole,
        ModelNameRole,
        ClockFreqRole
    };

    CpuDataModel(QObject *parent = 0);

    void addCpuCore(const CpuCore &CpuCore);
    int rowCount(const QModelIndex & parent = QModelIndex()) const override;
    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const override;

protected:
    QHash<int, QByteArray> roleNames() const override;
private:
    QList<CpuCore> m_cpuCores;
};

#endif

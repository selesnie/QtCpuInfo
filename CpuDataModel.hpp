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

    int rowCount(const QModelIndex & parent = QModelIndex()) const override;
    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const override;

    void addToModel(const CpuCore &CpuCore);
    void clearModel();

protected:
    QHash<int, QByteArray> roleNames() const override;
private:
    QList<CpuCore> m_cpuCores;
};

#endif

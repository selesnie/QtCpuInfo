#ifndef CPU_INFO_DATAMODEL_HPP
#define CPU_INFO_DATAMODEL_HPP

#include "CpuCore.hpp"
#include "TimerCallback.hpp"

#include <QAbstractListModel>

/**
 * @brief The CpuInfoDataModel class is the data model
 * that encapsulates model in the model-view
 * architecture. When model's data is changed it
 * notifies view to update its data.
 */
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

    /**
     * @brief addToDataModel Adds data to model
     * @param CpuCore Data added to model
     */
    void addToDataModel(const CpuCore &cpuCore);

    /**
     * @brief resetDataModel Resets data model. Model data is cleared.
     */
    void resetDataModel();

protected:
    QHash<int, QByteArray> roleNames() const override;

private:
    /**
     * @brief addFileContentsToDataModel Adds contents of file into data model
     */
    void addFileContentsToDataModel();

    QList<CpuCore> m_cpuCores;
    TimerCallback m_timerCallback;
};

#endif

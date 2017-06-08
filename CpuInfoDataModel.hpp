#ifndef CPU_INFO_DATAMODEL_HPP
#define CPU_INFO_DATAMODEL_HPP

#include "CpuCore.hpp"
#include "TimerCallback.hpp"

#include <QAbstractListModel>

/**
 * @brief The CpuInfoDataModel class is the data model
 * that encapsulates model part in the model-view
 * architecture. When model data is changed it
 * notifies a view part to update its data.
 */
class CpuInfoDataModel : public QAbstractListModel
{
    Q_OBJECT
public:
    /**
     * @brief The ProcessorRoles enum presents
     * data roles in the model
     */
    enum ProcessorRoles
    {
        ProcessorIdRole = Qt::UserRole + 1,
        VendorRole,
        ModelNameRole,
        ClockFreqRole
    };

    /**
     * @brief CpuInfoDataModel Default ctor
     * @param parent Pointer to parent object
     */
    explicit CpuInfoDataModel(QObject *parent = 0);

    int rowCount(const QModelIndex & parent = QModelIndex()) const override;
    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const override;

    /**
     * @brief addToDataModel Adds data to model
     * @param Constant reference to data to be added in model
     */
    void addToDataModel(const CpuCore &cpuCore);

    /**
     * @brief resetDataModel Resets data model.
     * All data items in model are deleted.
     */
    void resetDataModel();

protected:
    QHash<int, QByteArray> roleNames() const override;

private:
    /**
     * @brief addFileContentsToDataModel Adds file contents to data model
     */
    void addFileContentsToDataModel();

    QList<CpuCore> m_cpuCores;
    TimerCallback m_timerCallback;
};

#endif

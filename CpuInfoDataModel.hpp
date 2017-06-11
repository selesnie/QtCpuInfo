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
        ClockFreqRole,
        CacheSize,
        Flags,
        CpuFamily,
        BogoMips
    };

    /**
     * @brief CpuInfoDataModel Ctor
     * @param filename Input filename for model data
     * @param parent Parent object
     */
    explicit CpuInfoDataModel(const QString& filename, QObject *parent = 0);

    int rowCount(const QModelIndex & parent = QModelIndex()) const override;
    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const override;

    /**
     * @brief addOrUpdateDataModel Adds or updates data items in the model
     * @param cpuCoreVec Vector of data elements to be added or updated in the model
     */
    void addOrUpdateDataModel(const QVector<CpuCore>& cpuCoreVec);

protected:
    QHash<int, QByteArray> roleNames() const override;

private:
    /**
     * @brief addFileContentsToDataModel Adds file contents to data model
     */
    void addFileContentsToDataModel();

    /**
     * @brief addDataToModel Adds new data in the model
     * @param cpuCoreVec Vector of data elemens to be added in model
     */
    void addDataToModel(const QVector<CpuCore>& cpuCoreVec);

    /**
     * @brief updateDataInModel Updates data in the model
     * @param cpuCoreVec Vector of data elements to be updated in model
     */
    void updateDataInModel(const QVector<CpuCore>& cpuCoreVec);

    QList<CpuCore> m_cpuCores;
    QString m_filename;
    TimerCallback m_timerCallback;
};

#endif

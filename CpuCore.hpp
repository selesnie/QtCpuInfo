#ifndef CPU_CORE_HPP
#define CPU_CORE_HPP

#include <QString>

/**
 * @brief The CpuCore struct presents
 * parameters of one CPU core in the
 * system. System processor has
 * typically multiple CPU cores.
 */
struct CpuCore
{
    QString processor {};
    QString vendor {};
    QString model {};
    QString clockFreqMhz {};
};

#endif

#ifndef CPU_CORE_HPP
#define CPU_CORE_HPP

#include <QString>

struct CpuCore
{
    QString processor {};
    QString vendor {};
    QString model {};
    QString clockFreqMhz {};
};

#endif

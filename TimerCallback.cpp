#include "TimerCallback.hpp"

TimerCallback::TimerCallback(QObject *parent)
    : QObject(parent),
      m_timer(),
      m_callback()
{
    connect(&m_timer, SIGNAL(timeout()), this, SLOT(handleTimeout()));
}

void TimerCallback::registerTimerElapsedCallback(std::function<void()> func)
{
    m_callback = func;
}

void TimerCallback::start(int timeoutInMilliseconds)
{
    if (m_timer.isActive())
    {
        m_timer.stop();
    }

    m_timer.setInterval(timeoutInMilliseconds);
    m_timer.start();
}

void TimerCallback::handleTimeout()
{
    m_callback();
}

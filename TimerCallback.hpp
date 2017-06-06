#ifndef TIMER_CALLBACK_HPP
#define TIMER_CALLBACK_HPP

#include <QObject>
#include <QTimer>

#include <functional>

class TimerCallback : public QObject
{
    Q_OBJECT
public:
    explicit TimerCallback(QObject *parent = nullptr);

    void registerTimerElapsedCallback(std::function<void()> func);

    void start(int timeoutInMilliseconds);

private slots:
    void handleTimeout();

private:
    QTimer m_timer;
    std::function<void()> m_callback;
};

#endif

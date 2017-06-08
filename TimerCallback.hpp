#ifndef TIMER_CALLBACK_HPP
#define TIMER_CALLBACK_HPP

#include <QObject>
#include <QTimer>

#include <functional>

/**
 * @brief The TimerCallback class creates timer
 * that calls callback function when timer elapses.
 */
class TimerCallback : public QObject
{
    Q_OBJECT
public:
    explicit TimerCallback(QObject *parent = nullptr);

    /**
     * @brief registerTimerElapsedCallback Registers a function that
     * is called when timer elapses
     * @param func Function that is called when timer elapses
     */
    void registerTimerElapsedCallback(std::function<void()> func);

    /**
     * @brief start Starts timer
     * @param timeoutInMilliseconds Timer timeout in milliseconds
     */
    void start(int timeoutInMilliseconds);

private slots:
    /**
     * @brief handleTimeout Slot that is called when timer elapses
     */
    void handleTimeout();

private:
    QTimer m_timer;
    //Callback function that is called after timer elapses
    std::function<void()> m_callback;
};

#endif

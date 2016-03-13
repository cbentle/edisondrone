#include "server.h"

using namespace EdisonDrone;

Server::Server(unsigned int imu_update_ms,
               IMU &imu)
    : m_attitude_updater(imu_update_ms, imu)
    , m_is_running(false) {
}

bool Server::isRunning() {
    return m_is_running;
}

int Server::start() {
    m_start_stop_mutex.lock();

    if(isRunning()) {
        m_start_stop_mutex.unlock();
        return 1;
    }

    m_attitude_updater.start();
    m_is_running = true;

    m_start_stop_mutex.unlock();
    return 0;
}

void Server::stop() {
    m_start_stop_mutex.lock();

    m_attitude_updater.stop();
    m_is_running = false;

    m_start_stop_mutex.unlock();
}

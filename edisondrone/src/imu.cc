#include "imu.h"

#include <functional>

#define PI 3.1415926535897

using namespace EdisonDrone;

IMU::IMU(Gyro &gyro, unsigned int gyro_update_usecs)
	: m_update_secs(gyro_update_usecs / (1000.0 * 1000.0))
    , m_gyro_listener(gyro,
                      std::bind(&IMU::onGyroUpdate, this,
                                std::placeholders::_1),
                      gyro_update_usecs)
    , m_position(PI / 2, 0, 0) {
}

void IMU::start() {
    m_gyro_listener.start();
}

void IMU::stop() {
    m_gyro_listener.stop();
}

void IMU::join() {
    m_gyro_listener.join();
}

const Quaternion &IMU::attitude() const {
	return m_position;
}

void IMU::onGyroUpdate(GyroEvent &ev) {
	Quaternion ev_q(ev.x * m_update_secs,
					ev.y * m_update_secs,
					ev.z * m_update_secs);
	m_position.rotate(ev_q);
    m_position.normalize();
}

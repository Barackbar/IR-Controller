
#ifndef __IR_CONTROLLER_UTILS_HH__
#define __IR_CONTROLLER_UTILS_HH__

#include <string>

namespace ir_controller
{

void UtilTest();

/* Device Status
 * Returns whether the device is a sender, receiver, or neither.
 * Arguments:
 *   dev: Full path to device, normally "/dev/lirc[0,1]"
 * Returns:
 *  -1: Some other kind of failure.
 *   0: Device is neither a sender or receiver.
 *   1: Device is a receiver.
 *   2: Device is a sender.
 */
int DeviceStatus(std::string dev);

/* Send IR
 * Sends the contents of the provided file through
 * the provided IR sending device.
 */
int SendIR(std::string dev, std::string filename);

} // namespace ir_controller

#endif

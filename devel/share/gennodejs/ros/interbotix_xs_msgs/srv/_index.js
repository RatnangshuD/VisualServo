
"use strict";

let TorqueEnable = require('./TorqueEnable.js')
let RobotInfo = require('./RobotInfo.js')
let MotorGains = require('./MotorGains.js')
let OperatingModes = require('./OperatingModes.js')
let Reboot = require('./Reboot.js')
let RegisterValues = require('./RegisterValues.js')

module.exports = {
  TorqueEnable: TorqueEnable,
  RobotInfo: RobotInfo,
  MotorGains: MotorGains,
  OperatingModes: OperatingModes,
  Reboot: Reboot,
  RegisterValues: RegisterValues,
};

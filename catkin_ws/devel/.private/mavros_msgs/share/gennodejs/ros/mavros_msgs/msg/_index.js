
"use strict";

let GlobalPositionTarget = require('./GlobalPositionTarget.js');
let BatteryStatus = require('./BatteryStatus.js');
let HilSensor = require('./HilSensor.js');
let ExtendedState = require('./ExtendedState.js');
let Vibration = require('./Vibration.js');
let RCOut = require('./RCOut.js');
let CommandCode = require('./CommandCode.js');
let OverrideRCIn = require('./OverrideRCIn.js');
let FileEntry = require('./FileEntry.js');
let VFR_HUD = require('./VFR_HUD.js');
let RadioStatus = require('./RadioStatus.js');
let CamIMUStamp = require('./CamIMUStamp.js');
let DebugValue = require('./DebugValue.js');
let ActuatorControl = require('./ActuatorControl.js');
let RTCM = require('./RTCM.js');
let HilGPS = require('./HilGPS.js');
let Altitude = require('./Altitude.js');
let OpticalFlowRad = require('./OpticalFlowRad.js');
let TimesyncStatus = require('./TimesyncStatus.js');
let AttitudeTarget = require('./AttitudeTarget.js');
let RCIn = require('./RCIn.js');
let Waypoint = require('./Waypoint.js');
let LogEntry = require('./LogEntry.js');
let Mavlink = require('./Mavlink.js');
let Thrust = require('./Thrust.js');
let State = require('./State.js');
let ADSBVehicle = require('./ADSBVehicle.js');
let ParamValue = require('./ParamValue.js');
let HilControls = require('./HilControls.js');
let StatusText = require('./StatusText.js');
let HomePosition = require('./HomePosition.js');
let WaypointList = require('./WaypointList.js');
let HilStateQuaternion = require('./HilStateQuaternion.js');
let PositionTarget = require('./PositionTarget.js');
let WaypointReached = require('./WaypointReached.js');
let HilActuatorControls = require('./HilActuatorControls.js');
let ManualControl = require('./ManualControl.js');
let Trajectory = require('./Trajectory.js');
let LogData = require('./LogData.js');

module.exports = {
  GlobalPositionTarget: GlobalPositionTarget,
  BatteryStatus: BatteryStatus,
  HilSensor: HilSensor,
  ExtendedState: ExtendedState,
  Vibration: Vibration,
  RCOut: RCOut,
  CommandCode: CommandCode,
  OverrideRCIn: OverrideRCIn,
  FileEntry: FileEntry,
  VFR_HUD: VFR_HUD,
  RadioStatus: RadioStatus,
  CamIMUStamp: CamIMUStamp,
  DebugValue: DebugValue,
  ActuatorControl: ActuatorControl,
  RTCM: RTCM,
  HilGPS: HilGPS,
  Altitude: Altitude,
  OpticalFlowRad: OpticalFlowRad,
  TimesyncStatus: TimesyncStatus,
  AttitudeTarget: AttitudeTarget,
  RCIn: RCIn,
  Waypoint: Waypoint,
  LogEntry: LogEntry,
  Mavlink: Mavlink,
  Thrust: Thrust,
  State: State,
  ADSBVehicle: ADSBVehicle,
  ParamValue: ParamValue,
  HilControls: HilControls,
  StatusText: StatusText,
  HomePosition: HomePosition,
  WaypointList: WaypointList,
  HilStateQuaternion: HilStateQuaternion,
  PositionTarget: PositionTarget,
  WaypointReached: WaypointReached,
  HilActuatorControls: HilActuatorControls,
  ManualControl: ManualControl,
  Trajectory: Trajectory,
  LogData: LogData,
};

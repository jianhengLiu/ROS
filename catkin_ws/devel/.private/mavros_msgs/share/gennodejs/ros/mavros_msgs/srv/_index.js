
"use strict";

let ParamGet = require('./ParamGet.js')
let FileRename = require('./FileRename.js')
let FileMakeDir = require('./FileMakeDir.js')
let SetMavFrame = require('./SetMavFrame.js')
let LogRequestEnd = require('./LogRequestEnd.js')
let FileRemove = require('./FileRemove.js')
let LogRequestData = require('./LogRequestData.js')
let CommandHome = require('./CommandHome.js')
let FileChecksum = require('./FileChecksum.js')
let CommandInt = require('./CommandInt.js')
let FileWrite = require('./FileWrite.js')
let FileRead = require('./FileRead.js')
let WaypointClear = require('./WaypointClear.js')
let CommandTOL = require('./CommandTOL.js')
let LogRequestList = require('./LogRequestList.js')
let FileList = require('./FileList.js')
let FileClose = require('./FileClose.js')
let ParamPull = require('./ParamPull.js')
let SetMode = require('./SetMode.js')
let CommandLong = require('./CommandLong.js')
let WaypointPull = require('./WaypointPull.js')
let WaypointSetCurrent = require('./WaypointSetCurrent.js')
let ParamPush = require('./ParamPush.js')
let StreamRate = require('./StreamRate.js')
let FileOpen = require('./FileOpen.js')
let CommandBool = require('./CommandBool.js')
let WaypointPush = require('./WaypointPush.js')
let FileTruncate = require('./FileTruncate.js')
let CommandTriggerControl = require('./CommandTriggerControl.js')
let ParamSet = require('./ParamSet.js')
let FileRemoveDir = require('./FileRemoveDir.js')

module.exports = {
  ParamGet: ParamGet,
  FileRename: FileRename,
  FileMakeDir: FileMakeDir,
  SetMavFrame: SetMavFrame,
  LogRequestEnd: LogRequestEnd,
  FileRemove: FileRemove,
  LogRequestData: LogRequestData,
  CommandHome: CommandHome,
  FileChecksum: FileChecksum,
  CommandInt: CommandInt,
  FileWrite: FileWrite,
  FileRead: FileRead,
  WaypointClear: WaypointClear,
  CommandTOL: CommandTOL,
  LogRequestList: LogRequestList,
  FileList: FileList,
  FileClose: FileClose,
  ParamPull: ParamPull,
  SetMode: SetMode,
  CommandLong: CommandLong,
  WaypointPull: WaypointPull,
  WaypointSetCurrent: WaypointSetCurrent,
  ParamPush: ParamPush,
  StreamRate: StreamRate,
  FileOpen: FileOpen,
  CommandBool: CommandBool,
  WaypointPush: WaypointPush,
  FileTruncate: FileTruncate,
  CommandTriggerControl: CommandTriggerControl,
  ParamSet: ParamSet,
  FileRemoveDir: FileRemoveDir,
};

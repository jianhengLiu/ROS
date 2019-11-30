//
// Created by chrisliu on 2019/11/28.
//

function sysCall_init()
robotHandle=sim.getObjectAssociatedWithScript(sim.handle_self)
leftMotor=sim.getObjectHandle("rosInterfaceControlledBubbleRobLeftMotor") -- Handle of the left motor
        rightMotor=sim.getObjectHandle("rosInterfaceControlledBubbleRobRightMotor") -- Handle of the right motor
        noseSensor=sim.getObjectHandle("rosInterfaceControlledBubbleRobSensingNose") -- Handle of the proximity sensor
-- Launch the ROS client application:
if simROS then
print("<font color='#0F0'>ROS interface was found.</font>@html")
local sysTime=sim.getSystemTimeInMs(-1)
local leftMotorTopicName='leftMotorSpeed'..sysTime -- we add a random component so that we can have several instances of this robot running
local rightMotorTopicName='rightMotorSpeed'..sysTime -- we add a random component so that we can have several instances of this robot running
local sensorTopicName='sensorTrigger'..sysTime -- we add a random component so that we can have several instances of this robot running
local simulationTimeTopicName='simTime'..sysTime -- we add a random component so that we can have several instances of this robot running
-- Prepare the sensor publisher and the motor speed subscribers:
sensorPub=simROS.advertise('/'..sensorTopicName,'std_msgs/Bool')
simTimePub=simROS.advertise('/'..simulationTimeTopicName,'std_msgs/Float32')
leftMotorSub=simROS.subscribe('/'..leftMotorTopicName,'std_msgs/Float32','setLeftMotorVelocity_cb')
rightMotorSub=simROS.subscribe('/'..rightMotorTopicName,'std_msgs/Float32','setRightMotorVelocity_cb')
        -- Now we start the client application:
result=sim.launchExecutable('rosBubbleRob',leftMotorTopicName.." "..rightMotorTopicName.." "..sensorTopicName.." "..simulationTimeTopicName,0)
else
print("<font color='#F00'>ROS interface was not found. Cannot run.</font>@html")
end

        end
function setLeftMotorVelocity_cb(msg)
-- Left motor speed subscriber callback
        sim.setJointTargetVelocity(leftMotor,msg.data)
end

        function setRightMotorVelocity_cb(msg)
-- Right motor speed subscriber callback
        sim.setJointTargetVelocity(rightMotor,msg.data)
end

        function getTransformStamped(objHandle,name,relTo,relToName)
t=sim.getSystemTime()
p=sim.getObjectPosition(objHandle,relTo)
o=sim.getObjectQuaternion(objHandle,relTo)
return {
header={
        stamp=t,
        frame_id=relToName
},
        child_frame_id=name,
        transform={
        translation={x=p[1],y=p[2],z=p[3]},
        rotation={x=o[1],y=o[2],z=o[3],w=o[4]}
}
}
end


        function sysCall_actuation()
-- Send an updated sensor and simulation time message, and send the transform of the robot:
if simROS then
local result=sim.readProximitySensor(noseSensor)
local detectionTrigger={}
detectionTrigger['data']=result>0
simROS.publish(sensorPub,detectionTrigger)
simROS.publish(simTimePub,{data=sim.getSimulationTime()})
-- Send the robot's transform:
simROS.sendTransform(getTransformStamped(robotHandle,'rosInterfaceControlledBubbleRob',-1,'world'))
-- To send several transforms at once, use simROS.sendTransforms instead
end
        end

function sysCall_cleanup()
if simROS then
-- Following not really needed in a simulation script (i.e. automatically shut down at simulation end):
simROS.shutdownPublisher(sensorPub)
simROS.shutdownSubscriber(leftMotorSub)
simROS.shutdownSubscriber(rightMotorSub)
end
        end

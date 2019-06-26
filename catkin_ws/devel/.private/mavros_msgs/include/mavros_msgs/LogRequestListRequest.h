// Generated by gencpp from file mavros_msgs/LogRequestListRequest.msg
// DO NOT EDIT!


#ifndef MAVROS_MSGS_MESSAGE_LOGREQUESTLISTREQUEST_H
#define MAVROS_MSGS_MESSAGE_LOGREQUESTLISTREQUEST_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace mavros_msgs
{
template <class ContainerAllocator>
struct LogRequestListRequest_
{
  typedef LogRequestListRequest_<ContainerAllocator> Type;

  LogRequestListRequest_()
    : start(0)
    , end(0)  {
    }
  LogRequestListRequest_(const ContainerAllocator& _alloc)
    : start(0)
    , end(0)  {
  (void)_alloc;
    }



   typedef uint16_t _start_type;
  _start_type start;

   typedef uint16_t _end_type;
  _end_type end;





  typedef boost::shared_ptr< ::mavros_msgs::LogRequestListRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::mavros_msgs::LogRequestListRequest_<ContainerAllocator> const> ConstPtr;

}; // struct LogRequestListRequest_

typedef ::mavros_msgs::LogRequestListRequest_<std::allocator<void> > LogRequestListRequest;

typedef boost::shared_ptr< ::mavros_msgs::LogRequestListRequest > LogRequestListRequestPtr;
typedef boost::shared_ptr< ::mavros_msgs::LogRequestListRequest const> LogRequestListRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::mavros_msgs::LogRequestListRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::mavros_msgs::LogRequestListRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace mavros_msgs

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'geographic_msgs': ['/opt/ros/kinetic/share/geographic_msgs/cmake/../msg'], 'sensor_msgs': ['/opt/ros/kinetic/share/sensor_msgs/cmake/../msg'], 'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg'], 'mavros_msgs': ['/home/chris/catkin_ws/src/mavros/mavros_msgs/msg'], 'geometry_msgs': ['/opt/ros/kinetic/share/geometry_msgs/cmake/../msg'], 'uuid_msgs': ['/opt/ros/kinetic/share/uuid_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::mavros_msgs::LogRequestListRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::mavros_msgs::LogRequestListRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::mavros_msgs::LogRequestListRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::mavros_msgs::LogRequestListRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::mavros_msgs::LogRequestListRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::mavros_msgs::LogRequestListRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::mavros_msgs::LogRequestListRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "43d5acd48e3ef1843fa7f45876501c02";
  }

  static const char* value(const ::mavros_msgs::LogRequestListRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x43d5acd48e3ef184ULL;
  static const uint64_t static_value2 = 0x3fa7f45876501c02ULL;
};

template<class ContainerAllocator>
struct DataType< ::mavros_msgs::LogRequestListRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "mavros_msgs/LogRequestListRequest";
  }

  static const char* value(const ::mavros_msgs::LogRequestListRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::mavros_msgs::LogRequestListRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "\n\
\n\
\n\
\n\
\n\
uint16 start\n\
uint16 end\n\
";
  }

  static const char* value(const ::mavros_msgs::LogRequestListRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::mavros_msgs::LogRequestListRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.start);
      stream.next(m.end);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct LogRequestListRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::mavros_msgs::LogRequestListRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::mavros_msgs::LogRequestListRequest_<ContainerAllocator>& v)
  {
    s << indent << "start: ";
    Printer<uint16_t>::stream(s, indent + "  ", v.start);
    s << indent << "end: ";
    Printer<uint16_t>::stream(s, indent + "  ", v.end);
  }
};

} // namespace message_operations
} // namespace ros

#endif // MAVROS_MSGS_MESSAGE_LOGREQUESTLISTREQUEST_H

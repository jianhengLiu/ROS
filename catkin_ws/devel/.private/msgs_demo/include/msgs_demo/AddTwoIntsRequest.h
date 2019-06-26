// Generated by gencpp from file msgs_demo/AddTwoIntsRequest.msg
// DO NOT EDIT!


#ifndef MSGS_DEMO_MESSAGE_ADDTWOINTSREQUEST_H
#define MSGS_DEMO_MESSAGE_ADDTWOINTSREQUEST_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace msgs_demo
{
template <class ContainerAllocator>
struct AddTwoIntsRequest_
{
  typedef AddTwoIntsRequest_<ContainerAllocator> Type;

  AddTwoIntsRequest_()
    : a(0)
    , b(0)  {
    }
  AddTwoIntsRequest_(const ContainerAllocator& _alloc)
    : a(0)
    , b(0)  {
  (void)_alloc;
    }



   typedef int32_t _a_type;
  _a_type a;

   typedef int32_t _b_type;
  _b_type b;





  typedef boost::shared_ptr< ::msgs_demo::AddTwoIntsRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::msgs_demo::AddTwoIntsRequest_<ContainerAllocator> const> ConstPtr;

}; // struct AddTwoIntsRequest_

typedef ::msgs_demo::AddTwoIntsRequest_<std::allocator<void> > AddTwoIntsRequest;

typedef boost::shared_ptr< ::msgs_demo::AddTwoIntsRequest > AddTwoIntsRequestPtr;
typedef boost::shared_ptr< ::msgs_demo::AddTwoIntsRequest const> AddTwoIntsRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::msgs_demo::AddTwoIntsRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::msgs_demo::AddTwoIntsRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace msgs_demo

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'nav_msgs': ['/opt/ros/kinetic/share/nav_msgs/cmake/../msg'], 'sensor_msgs': ['/opt/ros/kinetic/share/sensor_msgs/cmake/../msg'], 'actionlib_msgs': ['/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg'], 'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg'], 'geometry_msgs': ['/opt/ros/kinetic/share/geometry_msgs/cmake/../msg'], 'msgs_demo': ['/home/chris/catkin_ws/src/ROS-Academy-for-Beginners/msgs_demo/msg', '/home/chris/catkin_ws/devel/.private/msgs_demo/share/msgs_demo/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::msgs_demo::AddTwoIntsRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::msgs_demo::AddTwoIntsRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::msgs_demo::AddTwoIntsRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::msgs_demo::AddTwoIntsRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::msgs_demo::AddTwoIntsRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::msgs_demo::AddTwoIntsRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::msgs_demo::AddTwoIntsRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "ef8322123148e475e3e93a1f609b2f70";
  }

  static const char* value(const ::msgs_demo::AddTwoIntsRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xef8322123148e475ULL;
  static const uint64_t static_value2 = 0xe3e93a1f609b2f70ULL;
};

template<class ContainerAllocator>
struct DataType< ::msgs_demo::AddTwoIntsRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "msgs_demo/AddTwoIntsRequest";
  }

  static const char* value(const ::msgs_demo::AddTwoIntsRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::msgs_demo::AddTwoIntsRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "\n\
int32 a\n\
int32 b\n\
";
  }

  static const char* value(const ::msgs_demo::AddTwoIntsRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::msgs_demo::AddTwoIntsRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.a);
      stream.next(m.b);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct AddTwoIntsRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::msgs_demo::AddTwoIntsRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::msgs_demo::AddTwoIntsRequest_<ContainerAllocator>& v)
  {
    s << indent << "a: ";
    Printer<int32_t>::stream(s, indent + "  ", v.a);
    s << indent << "b: ";
    Printer<int32_t>::stream(s, indent + "  ", v.b);
  }
};

} // namespace message_operations
} // namespace ros

#endif // MSGS_DEMO_MESSAGE_ADDTWOINTSREQUEST_H

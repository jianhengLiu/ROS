// Generated by gencpp from file msgs_demo/AutoDockingFeedback.msg
// DO NOT EDIT!


#ifndef MSGS_DEMO_MESSAGE_AUTODOCKINGFEEDBACK_H
#define MSGS_DEMO_MESSAGE_AUTODOCKINGFEEDBACK_H


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
struct AutoDockingFeedback_
{
  typedef AutoDockingFeedback_<ContainerAllocator> Type;

  AutoDockingFeedback_()
    : state()
    , text()  {
    }
  AutoDockingFeedback_(const ContainerAllocator& _alloc)
    : state(_alloc)
    , text(_alloc)  {
  (void)_alloc;
    }



   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _state_type;
  _state_type state;

   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _text_type;
  _text_type text;





  typedef boost::shared_ptr< ::msgs_demo::AutoDockingFeedback_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::msgs_demo::AutoDockingFeedback_<ContainerAllocator> const> ConstPtr;

}; // struct AutoDockingFeedback_

typedef ::msgs_demo::AutoDockingFeedback_<std::allocator<void> > AutoDockingFeedback;

typedef boost::shared_ptr< ::msgs_demo::AutoDockingFeedback > AutoDockingFeedbackPtr;
typedef boost::shared_ptr< ::msgs_demo::AutoDockingFeedback const> AutoDockingFeedbackConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::msgs_demo::AutoDockingFeedback_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::msgs_demo::AutoDockingFeedback_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace msgs_demo

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': False}
// {'nav_msgs': ['/opt/ros/kinetic/share/nav_msgs/cmake/../msg'], 'sensor_msgs': ['/opt/ros/kinetic/share/sensor_msgs/cmake/../msg'], 'actionlib_msgs': ['/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg'], 'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg'], 'geometry_msgs': ['/opt/ros/kinetic/share/geometry_msgs/cmake/../msg'], 'msgs_demo': ['/home/chris/catkin_ws/src/ROS-Academy-for-Beginners/msgs_demo/msg', '/home/chris/catkin_ws/devel/.private/msgs_demo/share/msgs_demo/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::msgs_demo::AutoDockingFeedback_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::msgs_demo::AutoDockingFeedback_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::msgs_demo::AutoDockingFeedback_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::msgs_demo::AutoDockingFeedback_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::msgs_demo::AutoDockingFeedback_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::msgs_demo::AutoDockingFeedback_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::msgs_demo::AutoDockingFeedback_<ContainerAllocator> >
{
  static const char* value()
  {
    return "03343b6aa0067ce6251bcc08bf318388";
  }

  static const char* value(const ::msgs_demo::AutoDockingFeedback_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x03343b6aa0067ce6ULL;
  static const uint64_t static_value2 = 0x251bcc08bf318388ULL;
};

template<class ContainerAllocator>
struct DataType< ::msgs_demo::AutoDockingFeedback_<ContainerAllocator> >
{
  static const char* value()
  {
    return "msgs_demo/AutoDockingFeedback";
  }

  static const char* value(const ::msgs_demo::AutoDockingFeedback_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::msgs_demo::AutoDockingFeedback_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======\n\
#feedback\n\
string state\n\
string text\n\
\n\
";
  }

  static const char* value(const ::msgs_demo::AutoDockingFeedback_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::msgs_demo::AutoDockingFeedback_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.state);
      stream.next(m.text);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct AutoDockingFeedback_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::msgs_demo::AutoDockingFeedback_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::msgs_demo::AutoDockingFeedback_<ContainerAllocator>& v)
  {
    s << indent << "state: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.state);
    s << indent << "text: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.text);
  }
};

} // namespace message_operations
} // namespace ros

#endif // MSGS_DEMO_MESSAGE_AUTODOCKINGFEEDBACK_H

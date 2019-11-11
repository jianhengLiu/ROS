// Generated by gencpp from file dashgo_tools/check_msgGoal.msg
// DO NOT EDIT!


#ifndef DASHGO_TOOLS_MESSAGE_CHECK_MSGGOAL_H
#define DASHGO_TOOLS_MESSAGE_CHECK_MSGGOAL_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace dashgo_tools
{
template <class ContainerAllocator>
struct check_msgGoal_
{
  typedef check_msgGoal_<ContainerAllocator> Type;

  check_msgGoal_()
    : method()
    , imu()
    , distance(0.0)
    , angule(0.0)
    , vel(0.0)
    , error(0.0)  {
    }
  check_msgGoal_(const ContainerAllocator& _alloc)
    : method(_alloc)
    , imu(_alloc)
    , distance(0.0)
    , angule(0.0)
    , vel(0.0)
    , error(0.0)  {
  (void)_alloc;
    }



   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _method_type;
  _method_type method;

   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _imu_type;
  _imu_type imu;

   typedef float _distance_type;
  _distance_type distance;

   typedef float _angule_type;
  _angule_type angule;

   typedef float _vel_type;
  _vel_type vel;

   typedef float _error_type;
  _error_type error;





  typedef boost::shared_ptr< ::dashgo_tools::check_msgGoal_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::dashgo_tools::check_msgGoal_<ContainerAllocator> const> ConstPtr;

}; // struct check_msgGoal_

typedef ::dashgo_tools::check_msgGoal_<std::allocator<void> > check_msgGoal;

typedef boost::shared_ptr< ::dashgo_tools::check_msgGoal > check_msgGoalPtr;
typedef boost::shared_ptr< ::dashgo_tools::check_msgGoal const> check_msgGoalConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::dashgo_tools::check_msgGoal_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::dashgo_tools::check_msgGoal_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace dashgo_tools

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': False}
// {'actionlib_msgs': ['/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg'], 'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg'], 'dashgo_tools': ['/home/chrisliu/ROS/Navigation/dashgo_ws/devel/share/dashgo_tools/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::dashgo_tools::check_msgGoal_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::dashgo_tools::check_msgGoal_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::dashgo_tools::check_msgGoal_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::dashgo_tools::check_msgGoal_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::dashgo_tools::check_msgGoal_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::dashgo_tools::check_msgGoal_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::dashgo_tools::check_msgGoal_<ContainerAllocator> >
{
  static const char* value()
  {
    return "80846c2aaf95c842d4343d524003feda";
  }

  static const char* value(const ::dashgo_tools::check_msgGoal_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x80846c2aaf95c842ULL;
  static const uint64_t static_value2 = 0xd4343d524003fedaULL;
};

template<class ContainerAllocator>
struct DataType< ::dashgo_tools::check_msgGoal_<ContainerAllocator> >
{
  static const char* value()
  {
    return "dashgo_tools/check_msgGoal";
  }

  static const char* value(const ::dashgo_tools::check_msgGoal_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::dashgo_tools::check_msgGoal_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======\n\
#goal definition\n\
string method\n\
string imu\n\
float32 distance\n\
float32 angule\n\
float32 vel\n\
float32 error\n\
";
  }

  static const char* value(const ::dashgo_tools::check_msgGoal_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::dashgo_tools::check_msgGoal_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.method);
      stream.next(m.imu);
      stream.next(m.distance);
      stream.next(m.angule);
      stream.next(m.vel);
      stream.next(m.error);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct check_msgGoal_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::dashgo_tools::check_msgGoal_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::dashgo_tools::check_msgGoal_<ContainerAllocator>& v)
  {
    s << indent << "method: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.method);
    s << indent << "imu: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.imu);
    s << indent << "distance: ";
    Printer<float>::stream(s, indent + "  ", v.distance);
    s << indent << "angule: ";
    Printer<float>::stream(s, indent + "  ", v.angule);
    s << indent << "vel: ";
    Printer<float>::stream(s, indent + "  ", v.vel);
    s << indent << "error: ";
    Printer<float>::stream(s, indent + "  ", v.error);
  }
};

} // namespace message_operations
} // namespace ros

#endif // DASHGO_TOOLS_MESSAGE_CHECK_MSGGOAL_H

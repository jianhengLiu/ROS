// Generated by gencpp from file zed_wrapper/reset_odometryResponse.msg
// DO NOT EDIT!


#ifndef ZED_WRAPPER_MESSAGE_RESET_ODOMETRYRESPONSE_H
#define ZED_WRAPPER_MESSAGE_RESET_ODOMETRYRESPONSE_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace zed_wrapper
{
template <class ContainerAllocator>
struct reset_odometryResponse_
{
  typedef reset_odometryResponse_<ContainerAllocator> Type;

  reset_odometryResponse_()
    : reset_done(false)  {
    }
  reset_odometryResponse_(const ContainerAllocator& _alloc)
    : reset_done(false)  {
  (void)_alloc;
    }



   typedef uint8_t _reset_done_type;
  _reset_done_type reset_done;





  typedef boost::shared_ptr< ::zed_wrapper::reset_odometryResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::zed_wrapper::reset_odometryResponse_<ContainerAllocator> const> ConstPtr;

}; // struct reset_odometryResponse_

typedef ::zed_wrapper::reset_odometryResponse_<std::allocator<void> > reset_odometryResponse;

typedef boost::shared_ptr< ::zed_wrapper::reset_odometryResponse > reset_odometryResponsePtr;
typedef boost::shared_ptr< ::zed_wrapper::reset_odometryResponse const> reset_odometryResponseConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::zed_wrapper::reset_odometryResponse_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::zed_wrapper::reset_odometryResponse_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace zed_wrapper

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::zed_wrapper::reset_odometryResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::zed_wrapper::reset_odometryResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::zed_wrapper::reset_odometryResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::zed_wrapper::reset_odometryResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::zed_wrapper::reset_odometryResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::zed_wrapper::reset_odometryResponse_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::zed_wrapper::reset_odometryResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "e1e87fc9e9e6c154eca93b9fa292cc05";
  }

  static const char* value(const ::zed_wrapper::reset_odometryResponse_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xe1e87fc9e9e6c154ULL;
  static const uint64_t static_value2 = 0xeca93b9fa292cc05ULL;
};

template<class ContainerAllocator>
struct DataType< ::zed_wrapper::reset_odometryResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "zed_wrapper/reset_odometryResponse";
  }

  static const char* value(const ::zed_wrapper::reset_odometryResponse_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::zed_wrapper::reset_odometryResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "bool reset_done\n\
";
  }

  static const char* value(const ::zed_wrapper::reset_odometryResponse_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::zed_wrapper::reset_odometryResponse_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.reset_done);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct reset_odometryResponse_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::zed_wrapper::reset_odometryResponse_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::zed_wrapper::reset_odometryResponse_<ContainerAllocator>& v)
  {
    s << indent << "reset_done: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.reset_done);
  }
};

} // namespace message_operations
} // namespace ros

#endif // ZED_WRAPPER_MESSAGE_RESET_ODOMETRYRESPONSE_H
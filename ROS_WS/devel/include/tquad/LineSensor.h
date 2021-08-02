// Generated by gencpp from file tquad/LineSensor.msg
// DO NOT EDIT!


#ifndef TQUAD_MESSAGE_LINESENSOR_H
#define TQUAD_MESSAGE_LINESENSOR_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace tquad
{
template <class ContainerAllocator>
struct LineSensor_
{
  typedef LineSensor_<ContainerAllocator> Type;

  LineSensor_()
    : left(0.0)
    , middle(0.0)
    , right(0.0)  {
    }
  LineSensor_(const ContainerAllocator& _alloc)
    : left(0.0)
    , middle(0.0)
    , right(0.0)  {
  (void)_alloc;
    }



   typedef double _left_type;
  _left_type left;

   typedef double _middle_type;
  _middle_type middle;

   typedef double _right_type;
  _right_type right;





  typedef boost::shared_ptr< ::tquad::LineSensor_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::tquad::LineSensor_<ContainerAllocator> const> ConstPtr;

}; // struct LineSensor_

typedef ::tquad::LineSensor_<std::allocator<void> > LineSensor;

typedef boost::shared_ptr< ::tquad::LineSensor > LineSensorPtr;
typedef boost::shared_ptr< ::tquad::LineSensor const> LineSensorConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::tquad::LineSensor_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::tquad::LineSensor_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace tquad

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg'], 'tquad': ['/home/cherif/OMCRI4CP/T-quad/ROS_WS/src/tquad/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::tquad::LineSensor_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::tquad::LineSensor_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::tquad::LineSensor_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::tquad::LineSensor_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::tquad::LineSensor_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::tquad::LineSensor_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::tquad::LineSensor_<ContainerAllocator> >
{
  static const char* value()
  {
    return "a9d7cdd3125cbdafd369bb29980024d5";
  }

  static const char* value(const ::tquad::LineSensor_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xa9d7cdd3125cbdafULL;
  static const uint64_t static_value2 = 0xd369bb29980024d5ULL;
};

template<class ContainerAllocator>
struct DataType< ::tquad::LineSensor_<ContainerAllocator> >
{
  static const char* value()
  {
    return "tquad/LineSensor";
  }

  static const char* value(const ::tquad::LineSensor_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::tquad::LineSensor_<ContainerAllocator> >
{
  static const char* value()
  {
    return "float64 left\n\
float64 middle\n\
float64 right\n\
";
  }

  static const char* value(const ::tquad::LineSensor_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::tquad::LineSensor_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.left);
      stream.next(m.middle);
      stream.next(m.right);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct LineSensor_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::tquad::LineSensor_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::tquad::LineSensor_<ContainerAllocator>& v)
  {
    s << indent << "left: ";
    Printer<double>::stream(s, indent + "  ", v.left);
    s << indent << "middle: ";
    Printer<double>::stream(s, indent + "  ", v.middle);
    s << indent << "right: ";
    Printer<double>::stream(s, indent + "  ", v.right);
  }
};

} // namespace message_operations
} // namespace ros

#endif // TQUAD_MESSAGE_LINESENSOR_H
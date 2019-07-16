// Generated by gencpp from file ardrone_autonomy/navdata_vision_perf.msg
// DO NOT EDIT!


#ifndef ARDRONE_AUTONOMY_MESSAGE_NAVDATA_VISION_PERF_H
#define ARDRONE_AUTONOMY_MESSAGE_NAVDATA_VISION_PERF_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <std_msgs/Header.h>

namespace ardrone_autonomy
{
template <class ContainerAllocator>
struct navdata_vision_perf_
{
  typedef navdata_vision_perf_<ContainerAllocator> Type;

  navdata_vision_perf_()
    : header()
    , drone_time(0.0)
    , tag(0)
    , size(0)
    , time_corners(0.0)
    , time_compute(0.0)
    , time_tracking(0.0)
    , time_trans(0.0)
    , time_update(0.0)
    , time_custom()  {
    }
  navdata_vision_perf_(const ContainerAllocator& _alloc)
    : header(_alloc)
    , drone_time(0.0)
    , tag(0)
    , size(0)
    , time_corners(0.0)
    , time_compute(0.0)
    , time_tracking(0.0)
    , time_trans(0.0)
    , time_update(0.0)
    , time_custom(_alloc)  {
  (void)_alloc;
    }



   typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
  _header_type header;

   typedef double _drone_time_type;
  _drone_time_type drone_time;

   typedef uint16_t _tag_type;
  _tag_type tag;

   typedef uint16_t _size_type;
  _size_type size;

   typedef float _time_corners_type;
  _time_corners_type time_corners;

   typedef float _time_compute_type;
  _time_compute_type time_compute;

   typedef float _time_tracking_type;
  _time_tracking_type time_tracking;

   typedef float _time_trans_type;
  _time_trans_type time_trans;

   typedef float _time_update_type;
  _time_update_type time_update;

   typedef std::vector<float, typename ContainerAllocator::template rebind<float>::other >  _time_custom_type;
  _time_custom_type time_custom;




  typedef boost::shared_ptr< ::ardrone_autonomy::navdata_vision_perf_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::ardrone_autonomy::navdata_vision_perf_<ContainerAllocator> const> ConstPtr;

}; // struct navdata_vision_perf_

typedef ::ardrone_autonomy::navdata_vision_perf_<std::allocator<void> > navdata_vision_perf;

typedef boost::shared_ptr< ::ardrone_autonomy::navdata_vision_perf > navdata_vision_perfPtr;
typedef boost::shared_ptr< ::ardrone_autonomy::navdata_vision_perf const> navdata_vision_perfConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::ardrone_autonomy::navdata_vision_perf_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::ardrone_autonomy::navdata_vision_perf_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace ardrone_autonomy

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': True}
// {'std_msgs': ['/opt/ros/indigo/share/std_msgs/cmake/../msg'], 'ardrone_autonomy': ['/home/server/ros_workspace/src/ardrone_autonomy/msg'], 'geometry_msgs': ['/opt/ros/indigo/share/geometry_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::ardrone_autonomy::navdata_vision_perf_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::ardrone_autonomy::navdata_vision_perf_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::ardrone_autonomy::navdata_vision_perf_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::ardrone_autonomy::navdata_vision_perf_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::ardrone_autonomy::navdata_vision_perf_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::ardrone_autonomy::navdata_vision_perf_<ContainerAllocator> const>
  : TrueType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::ardrone_autonomy::navdata_vision_perf_<ContainerAllocator> >
{
  static const char* value()
  {
    return "5ed8267a2e2980a430a3439af8e5c9f7";
  }

  static const char* value(const ::ardrone_autonomy::navdata_vision_perf_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x5ed8267a2e2980a4ULL;
  static const uint64_t static_value2 = 0x30a3439af8e5c9f7ULL;
};

template<class ContainerAllocator>
struct DataType< ::ardrone_autonomy::navdata_vision_perf_<ContainerAllocator> >
{
  static const char* value()
  {
    return "ardrone_autonomy/navdata_vision_perf";
  }

  static const char* value(const ::ardrone_autonomy::navdata_vision_perf_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::ardrone_autonomy::navdata_vision_perf_<ContainerAllocator> >
{
  static const char* value()
  {
    return "Header header\n\
float64 drone_time\n\
uint16 tag\n\
uint16 size\n\
float32 time_corners\n\
float32 time_compute\n\
float32 time_tracking\n\
float32 time_trans\n\
float32 time_update\n\
float32[] time_custom\n\
\n\
================================================================================\n\
MSG: std_msgs/Header\n\
# Standard metadata for higher-level stamped data types.\n\
# This is generally used to communicate timestamped data \n\
# in a particular coordinate frame.\n\
# \n\
# sequence ID: consecutively increasing ID \n\
uint32 seq\n\
#Two-integer timestamp that is expressed as:\n\
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')\n\
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')\n\
# time-handling sugar is provided by the client library\n\
time stamp\n\
#Frame this data is associated with\n\
# 0: no frame\n\
# 1: global frame\n\
string frame_id\n\
";
  }

  static const char* value(const ::ardrone_autonomy::navdata_vision_perf_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::ardrone_autonomy::navdata_vision_perf_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.header);
      stream.next(m.drone_time);
      stream.next(m.tag);
      stream.next(m.size);
      stream.next(m.time_corners);
      stream.next(m.time_compute);
      stream.next(m.time_tracking);
      stream.next(m.time_trans);
      stream.next(m.time_update);
      stream.next(m.time_custom);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct navdata_vision_perf_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::ardrone_autonomy::navdata_vision_perf_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::ardrone_autonomy::navdata_vision_perf_<ContainerAllocator>& v)
  {
    s << indent << "header: ";
    s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "drone_time: ";
    Printer<double>::stream(s, indent + "  ", v.drone_time);
    s << indent << "tag: ";
    Printer<uint16_t>::stream(s, indent + "  ", v.tag);
    s << indent << "size: ";
    Printer<uint16_t>::stream(s, indent + "  ", v.size);
    s << indent << "time_corners: ";
    Printer<float>::stream(s, indent + "  ", v.time_corners);
    s << indent << "time_compute: ";
    Printer<float>::stream(s, indent + "  ", v.time_compute);
    s << indent << "time_tracking: ";
    Printer<float>::stream(s, indent + "  ", v.time_tracking);
    s << indent << "time_trans: ";
    Printer<float>::stream(s, indent + "  ", v.time_trans);
    s << indent << "time_update: ";
    Printer<float>::stream(s, indent + "  ", v.time_update);
    s << indent << "time_custom[]" << std::endl;
    for (size_t i = 0; i < v.time_custom.size(); ++i)
    {
      s << indent << "  time_custom[" << i << "]: ";
      Printer<float>::stream(s, indent + "  ", v.time_custom[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // ARDRONE_AUTONOMY_MESSAGE_NAVDATA_VISION_PERF_H

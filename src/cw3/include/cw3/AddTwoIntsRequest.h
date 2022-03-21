#ifndef BEGINNER_TUTORIALS_MESSAGE_ADDTWOINTSREQUEST_H
#define BEGINNER_TUTORIALS_MESSAGE_ADDTWOINTSREQUEST_H

#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace cw3
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
      }
      
     typedef int64_t _a_type;
    _a_type a;
    
     typedef int64_t _b_type;
    _b_type b;
    
    typedef boost::shared_ptr< ::cw3::AddTwoIntsRequest_<ContainerAllocator> > Ptr;
    typedef boost::shared_ptr< ::cw3::AddTwoIntsRequest_<ContainerAllocator> const> ConstPtr;
  }; // struct AddTwoIntsRequest_

  typedef ::cw3::AddTwoIntsRequest_<std::allocator<void> > AddTwoIntsRequest;
  typedef boost::shared_ptr< ::cw3::AddTwoIntsRequest > AddTwoIntsRequestPtr;
  typedef boost::shared_ptr< ::cw3::AddTwoIntsRequest const> AddTwoIntsRequestConstPtr;
  
  // constants requiring out of line definition
  template<typename ContainerAllocator>
  std::ostream& operator<<(std::ostream& s, const ::cw3::AddTwoIntsRequest_<ContainerAllocator> & v)
  {
    ros::message_operations::Printer< ::cw3::AddTwoIntsRequest_<ContainerAllocator> >::stream(s, "", v);
    return s;
  }
} // namespace beginner_tutorials

namespace ros
{
  namespace message_traits
  {
    template <class ContainerAllocator>
    struct IsFixedSize< ::cw3::AddTwoIntsRequest_<ContainerAllocator> >
      : TrueType
      { };

    template <class ContainerAllocator>
    struct IsFixedSize< ::cw3::AddTwoIntsRequest_<ContainerAllocator> const>
      : TrueType
      { };

    template <class ContainerAllocator>
    struct IsMessage< ::cw3::AddTwoIntsRequest_<ContainerAllocator> >
      : TrueType
      { };

    template <class ContainerAllocator>
    struct IsMessage< ::cw3::AddTwoIntsRequest_<ContainerAllocator> const>
      : TrueType
      { };

    template <class ContainerAllocator>
    struct HasHeader< ::cw3::AddTwoIntsRequest_<ContainerAllocator> >
      : FalseType
      { };

    template <class ContainerAllocator>
    struct HasHeader< ::cw3::AddTwoIntsRequest_<ContainerAllocator> const>
      : FalseType
      { };


    template<class ContainerAllocator>
    struct MD5Sum< ::cw3::AddTwoIntsRequest_<ContainerAllocator> >
    {
      static const char* value()
      {
        return "36d09b846be0b371c5f190354dd3153e";
      }

      static const char* value(const ::cw3::AddTwoIntsRequest_<ContainerAllocator>&) { return value(); }
      static const uint64_t static_value1 = 0x36d09b846be0b371ULL;
      static const uint64_t static_value2 = 0xc5f190354dd3153eULL;
    };

    template<class ContainerAllocator>
    struct DataType< ::cw3::AddTwoIntsRequest_<ContainerAllocator> >
    {
      static const char* value()
      {
        return "cw3/AddTwoIntsRequest";
      }

      static const char* value(const ::cw3::AddTwoIntsRequest_<ContainerAllocator>&) { return value(); }
    };

    template<class ContainerAllocator>
    struct Definition< ::cw3::AddTwoIntsRequest_<ContainerAllocator> >
    {
      static const char* value()
      {
        return "int64 a\n\
    int64 b\n\
    ";
      }

      static const char* value(const ::cw3::AddTwoIntsRequest_<ContainerAllocator>&) { return value(); }
    };

  } // namespace message_traits
} // namespace ros

namespace ros
{
  namespace serialization
  {
    template<class ContainerAllocator> struct Serializer< ::cw3::AddTwoIntsRequest_<ContainerAllocator> >
    {
      template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
      {
        stream.next(m.a);
        stream.next(m.b);
      }
      
      ROS_DECLARE_ALLINONE_SERIALIZER;
    }; // struct AddTwoIntsRequest_
  } // namespace serialization
} // namespace ros

namespace ros
{
  namespace message_operations
  {
    template<class ContainerAllocator>
    struct Printer< ::cw3::AddTwoIntsRequest_<ContainerAllocator> >
    {
      template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::cw3::AddTwoIntsRequest_<ContainerAllocator>& v)
      {
        s << indent << "a: ";
        Printer<int64_t>::stream(s, indent + "  ", v.a);
        s << indent << "b: ";
        Printer<int64_t>::stream(s, indent + "  ", v.b);
      }
    };
  } // namespace message_operations
} // namespace ros

#endif // BEGINNER_TUTORIALS_MESSAGE_ADDTWOINTSREQUEST_H

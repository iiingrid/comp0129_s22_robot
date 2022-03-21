#ifndef BEGINNER_TUTORIALS_MESSAGE_ADDTWOINTSRESPONSE_H
#define BEGINNER_TUTORIALS_MESSAGE_ADDTWOINTSRESPONSE_H

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
  struct AddTwoIntsResponse_
  {
    typedef AddTwoIntsResponse_<ContainerAllocator> Type;
    
    AddTwoIntsResponse_()
      : sum(0)  {
      }
    AddTwoIntsResponse_(const ContainerAllocator& _alloc)
      : sum(0)  {
      }
      
     typedef int64_t _sum_type;
    _sum_type sum;
    
      typedef boost::shared_ptr< ::cw3::AddTwoIntsResponse_<ContainerAllocator> > Ptr;
      typedef boost::shared_ptr< ::cw3::AddTwoIntsResponse_<ContainerAllocator> const> ConstPtr;
  }; // struct AddTwoIntsResponse_

  typedef ::cw3::AddTwoIntsResponse_<std::allocator<void> > AddTwoIntsResponse;
  typedef boost::shared_ptr< ::cw3::AddTwoIntsResponse > AddTwoIntsResponsePtr;
  typedef boost::shared_ptr< ::cw3::AddTwoIntsResponse const> AddTwoIntsResponseConstPtr;

  // constants requiring out of line definition
  template<typename ContainerAllocator>
  std::ostream& operator<<(std::ostream& s, const ::cw3::AddTwoIntsResponse_<ContainerAllocator> & v)
  {
    ros::message_operations::Printer< ::cw3::AddTwoIntsResponse_<ContainerAllocator> >::stream(s, "", v);
    return s;
  }
} // namespace beginner_tutorials

namespace ros
{
  namespace message_traits
   {
    template <class ContainerAllocator>
    struct IsFixedSize< ::cw3::AddTwoIntsResponse_<ContainerAllocator> >
      : TrueType
      { };
      
    template <class ContainerAllocator>
    struct IsFixedSize< ::cw3::AddTwoIntsResponse_<ContainerAllocator> const>
      : TrueType
      { };
      
    template <class ContainerAllocator>
    struct IsMessage< ::cw3::AddTwoIntsResponse_<ContainerAllocator> >
      : TrueType
      { };
      
    template <class ContainerAllocator>
    struct IsMessage< ::cw3::AddTwoIntsResponse_<ContainerAllocator> const>
      : TrueType
      { };
      
    template <class ContainerAllocator>
    struct HasHeader< ::cw3::AddTwoIntsResponse_<ContainerAllocator> >
      : FalseType
      { };
      
    template <class ContainerAllocator>
    struct HasHeader< ::cw3::AddTwoIntsResponse_<ContainerAllocator> const>
      : FalseType
      { };
      
    template<class ContainerAllocator>
    struct MD5Sum< ::cw3::AddTwoIntsResponse_<ContainerAllocator> >
    {
      static const char* value()
      {
        return "b88405221c77b1878a3cbbfff53428d7";
      }
      
      static const char* value(const ::cw3::AddTwoIntsResponse_<ContainerAllocator>&) { return value(); }
      static const uint64_t static_value1 = 0xb88405221c77b187ULL;
      static const uint64_t static_value2 = 0x8a3cbbfff53428d7ULL;
    };
    
    template<class ContainerAllocator>
    struct DataType< ::cw3::AddTwoIntsResponse_<ContainerAllocator> >
    {
      static const char* value()
      {
        return "cw3/AddTwoIntsResponse";
      }
      
      static const char* value(const ::cw3::AddTwoIntsResponse_<ContainerAllocator>&) { return value(); }
    };
    
    template<class ContainerAllocator>
    struct Definition< ::cw3::AddTwoIntsResponse_<ContainerAllocator> >
    {
      static const char* value()
      {
        return "int64 sum\n\
    \n\
    ";
      }
      
      static const char* value(const ::cw3::AddTwoIntsResponse_<ContainerAllocator>&) { return value(); }
    };
  } // namespace message_traits
} // namespace ros

namespace ros
{
  namespace serialization
  {
    template<class ContainerAllocator> struct Serializer< ::cw3::AddTwoIntsResponse_<ContainerAllocator> >
    {
      template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
      {
        stream.next(m.sum);
      }
      
      ROS_DECLARE_ALLINONE_SERIALIZER;
    }; // struct AddTwoIntsResponse_
  } // namespace serialization
} // namespace ros

namespace ros
{
  namespace message_operations
  {
    template<class ContainerAllocator>
    struct Printer< ::cw3::AddTwoIntsResponse_<ContainerAllocator> >
    {
      template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::cw3::AddTwoIntsResponse_<ContainerAllocator>& v)
      {
        s << indent << "sum: ";
        Printer<int64_t>::stream(s, indent + "  ", v.sum);
      }
    };
  } // namespace message_operations
} // namespace ros

#endif // BEGINNER_TUTORIALS_MESSAGE_ADDTWOINTSRESPONSE_H

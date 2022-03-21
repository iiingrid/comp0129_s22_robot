#ifndef BEGINNER_TUTORIALS_MESSAGE_ADDTWOINTS_H
#define BEGINNER_TUTORIALS_MESSAGE_ADDTWOINTS_H

#include <ros/service_traits.h>
#include <AddTwoIntsRequest.h>
#include <AddTwoIntsResponse.h>

namespace cw3
{
  struct AddTwoInts
  {
    typedef AddTwoIntsRequest Request;
    typedef AddTwoIntsResponse Response;
    Request request;
    Response response;
    
    typedef Request RequestType;
    typedef Response ResponseType;
  }; // struct AddTwoInts
} // namespace beginner_tutorials

namespace ros
{
  namespace service_traits
  {
    template<>
    struct MD5Sum< ::cw3::AddTwoInts > {
      static const char* value()
      {
        return "6a2e34150c00229791cc89ff309fff21";
      }
      
      static const char* value(const ::cw3::AddTwoInts&) { return value(); }
    };
    
    template<>
    struct DataType< ::cw3::AddTwoInts > {
      static const char* value()
      {
        return "cw3/AddTwoInts";
      }

      static const char* value(const ::cw3::AddTwoInts&) { return value(); }
    };
    
    template<>
    struct MD5Sum< ::cw3::AddTwoIntsRequest>
    {
      static const char* value()
      {
        return MD5Sum< ::cw3::AddTwoInts >::value();
      }
      static const char* value(const ::cw3::AddTwoIntsRequest&)
      {
        return value();
      }
    };
    
    template<>
    struct DataType< ::cw3::AddTwoIntsRequest>
    {
      static const char* value()
      {
        return DataType< ::cw3::AddTwoInts >::value();
      }
      static const char* value(const ::cw3::AddTwoIntsRequest&)
      {
        return value();
      }
    };
    
    template<>
    struct MD5Sum< ::cw3::AddTwoIntsResponse>
    {
      static const char* value()
      {
        return MD5Sum< ::cw3::AddTwoInts >::value();
      }
      static const char* value(const ::cw3::AddTwoIntsResponse&)
      {
        return value();
      }
    };
    
    template<>
    struct DataType< ::cw3::AddTwoIntsResponse>
    {
      static const char* value()
      {
        return DataType< ::cw3::AddTwoInts >::value();
      }
      static const char* value(const ::cw3::AddTwoIntsResponse&)
      {
        return value();
      }
    };
  } // namespace service_traits
} // namespace ros

#endif // BEGINNER_TUTORIALS_MESSAGE_ADDTWOINTS_H

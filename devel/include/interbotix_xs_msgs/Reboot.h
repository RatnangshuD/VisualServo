// Generated by gencpp from file interbotix_xs_msgs/Reboot.msg
// DO NOT EDIT!


#ifndef INTERBOTIX_XS_MSGS_MESSAGE_REBOOT_H
#define INTERBOTIX_XS_MSGS_MESSAGE_REBOOT_H

#include <ros/service_traits.h>


#include <interbotix_xs_msgs/RebootRequest.h>
#include <interbotix_xs_msgs/RebootResponse.h>


namespace interbotix_xs_msgs
{

struct Reboot
{

typedef RebootRequest Request;
typedef RebootResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct Reboot
} // namespace interbotix_xs_msgs


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::interbotix_xs_msgs::Reboot > {
  static const char* value()
  {
    return "229067e7bfb48bf403b702d5f7f1ee93";
  }

  static const char* value(const ::interbotix_xs_msgs::Reboot&) { return value(); }
};

template<>
struct DataType< ::interbotix_xs_msgs::Reboot > {
  static const char* value()
  {
    return "interbotix_xs_msgs/Reboot";
  }

  static const char* value(const ::interbotix_xs_msgs::Reboot&) { return value(); }
};


// service_traits::MD5Sum< ::interbotix_xs_msgs::RebootRequest> should match
// service_traits::MD5Sum< ::interbotix_xs_msgs::Reboot >
template<>
struct MD5Sum< ::interbotix_xs_msgs::RebootRequest>
{
  static const char* value()
  {
    return MD5Sum< ::interbotix_xs_msgs::Reboot >::value();
  }
  static const char* value(const ::interbotix_xs_msgs::RebootRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::interbotix_xs_msgs::RebootRequest> should match
// service_traits::DataType< ::interbotix_xs_msgs::Reboot >
template<>
struct DataType< ::interbotix_xs_msgs::RebootRequest>
{
  static const char* value()
  {
    return DataType< ::interbotix_xs_msgs::Reboot >::value();
  }
  static const char* value(const ::interbotix_xs_msgs::RebootRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::interbotix_xs_msgs::RebootResponse> should match
// service_traits::MD5Sum< ::interbotix_xs_msgs::Reboot >
template<>
struct MD5Sum< ::interbotix_xs_msgs::RebootResponse>
{
  static const char* value()
  {
    return MD5Sum< ::interbotix_xs_msgs::Reboot >::value();
  }
  static const char* value(const ::interbotix_xs_msgs::RebootResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::interbotix_xs_msgs::RebootResponse> should match
// service_traits::DataType< ::interbotix_xs_msgs::Reboot >
template<>
struct DataType< ::interbotix_xs_msgs::RebootResponse>
{
  static const char* value()
  {
    return DataType< ::interbotix_xs_msgs::Reboot >::value();
  }
  static const char* value(const ::interbotix_xs_msgs::RebootResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // INTERBOTIX_XS_MSGS_MESSAGE_REBOOT_H
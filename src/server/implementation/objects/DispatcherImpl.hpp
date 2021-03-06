#ifndef __DISPATCHER_IMPL_HPP__
#define __DISPATCHER_IMPL_HPP__

#include "HubImpl.hpp"
#include "Dispatcher.hpp"
#include <EventHandler.hpp>

namespace kurento
{

class MediaPipeline;
class HubPort;
class DispatcherImpl;

void Serialize (std::shared_ptr<DispatcherImpl> &object, JsonSerializer &serializer);

class DispatcherImpl : public HubImpl, public virtual Dispatcher
{

public:

  DispatcherImpl (std::shared_ptr<MediaPipeline> mediaPipeline);

  virtual ~DispatcherImpl () {};

  void connect (std::shared_ptr<HubPort> source, std::shared_ptr<HubPort> sink);

  /* Next methods are automatically implemented by code generator */
  virtual bool connect (const std::string &eventType, std::shared_ptr<EventHandler> handler);

  virtual void invoke (std::shared_ptr<MediaObjectImpl> obj,
                       const std::string &methodName, const Json::Value &params,
                       Json::Value &response);

  virtual void Serialize (JsonSerializer &serializer);

private:

  class StaticConstructor
  {
  public:
    StaticConstructor();
  };

  static StaticConstructor staticConstructor;

};

} /* kurento */

#endif /*  __DISPATCHER_IMPL_HPP__ */

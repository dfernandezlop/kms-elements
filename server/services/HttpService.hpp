/*
 * (C) Copyright 2014 Kurento (http://kurento.org/)
 *
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the GNU Lesser General Public License
 * (LGPL) version 2.1 which accompanies this distribution, and is available at
 * http://www.gnu.org/licenses/lgpl-2.1.html
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 *
 */

#ifndef __HTTP_SERVICE_HPP__
#define __HTTP_SERVICE_HPP__

#include <HttpEndPointServer.hpp>
#include "Service.hpp"

namespace kurento
{

class HttpServiceException : public std::exception
{

public:
  HttpServiceException (std::string desc) : desc (desc) {
  }
  virtual ~HttpServiceException() {}
  virtual const char *what() const throw() {
    return desc.c_str();
  }

private:
  std::string desc;
};

class HttpService: public Service
{
public:
  HttpService (Glib::KeyFile &confFile, bool fixedPort = true);
  virtual ~HttpService() throw ();
  virtual void start ();
  virtual void stop ();

private:

  class StaticConstructor
  {
  public:
    StaticConstructor();
  };

  static StaticConstructor staticConstructor;
};

} /* kurento */

#endif /* __HTTP_SERVICE_HPP__ */

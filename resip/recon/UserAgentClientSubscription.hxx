#if !defined(UserAgentClientSubscription_hxx)
#define UserAgentClientSubscription_hxx

#include <resip/dum/AppDialogSet.hxx>
#include <resip/dum/InviteSessionHandler.hxx>
#include <resip/dum/DialogSetHandler.hxx>
#include <resip/dum/SubscriptionHandler.hxx>

#include "UserAgent.hxx"

namespace resip
{
class DialogUsageManager;
class SipMessage;
}

namespace useragent
{
class UserAgent;

/**
  This class is used to manage active client subscriptions.

  Author: Scott Godin (sgodin AT SipSpectrum DOT com)
*/

class UserAgentClientSubscription : public resip::AppDialogSet
{
   public:  
      UserAgentClientSubscription(UserAgent& userAgent, resip::DialogUsageManager& dum, unsigned int handle);  
      virtual ~UserAgentClientSubscription();

      UserAgent::SubscriptionHandle getSubscriptionHandle();
      virtual void end();

      // ClientSubscriptionHandler ///////////////////////////////////////////////////
      virtual void onUpdatePending(resip::ClientSubscriptionHandle h, const resip::SipMessage& notify, bool outOfOrder);
      virtual void onUpdateActive(resip::ClientSubscriptionHandle h, const resip::SipMessage& notify, bool outOfOrder);
      virtual void onUpdateExtension(resip::ClientSubscriptionHandle, const resip::SipMessage& notify, bool outOfOrder);
      virtual void onTerminated(resip::ClientSubscriptionHandle h, const resip::SipMessage& notify);
      virtual void onNewSubscription(resip::ClientSubscriptionHandle h, const resip::SipMessage& notify);
      virtual int  onRequestRetry(resip::ClientSubscriptionHandle h, int retryMinimum, const resip::SipMessage& notify);

   private:       
      void notifyReceived(const resip::Data& notifyData);

      UserAgent &mUserAgent;
      resip::DialogUsageManager &mDum;
      UserAgent::SubscriptionHandle mSubscriptionHandle;
      size_t mLastNotifyHash;
      bool mEnded;
};

}

#endif


/* ====================================================================

 Original contribution Copyright (C) 2008 Plantronics, Inc.
 Provided under the terms of the Vovida Software License, Version 2.0.

 The Vovida Software License, Version 2.0 
 
 Redistribution and use in source and binary forms, with or without
 modification, are permitted provided that the following conditions
 are met:
 
 1. Redistributions of source code must retain the above copyright
    notice, this list of conditions and the following disclaimer.
 
 2. Redistributions in binary form must reproduce the above copyright
    notice, this list of conditions and the following disclaimer in
    the documentation and/or other materials provided with the
    distribution. 
 
 THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESSED OR IMPLIED
 WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, TITLE AND
 NON-INFRINGEMENT ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT
 OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT DAMAGES
 IN EXCESS OF $1,000, NOR FOR ANY INDIRECT, INCIDENTAL, SPECIAL,
 EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
 OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE
 USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH
 DAMAGE.

 ==================================================================== */
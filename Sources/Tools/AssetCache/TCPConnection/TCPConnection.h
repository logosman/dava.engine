/*==================================================================================
    Copyright (c) 2008, binaryzebra
    All rights reserved.

    Redistribution and use in source and binary forms, with or without
    modification, are permitted provided that the following conditions are met:

    * Redistributions of source code must retain the above copyright
    notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
    notice, this list of conditions and the following disclaimer in the
    documentation and/or other materials provided with the distribution.
    * Neither the name of the binaryzebra nor the
    names of its contributors may be used to endorse or promote products
    derived from this software without specific prior written permission.

    THIS SOFTWARE IS PROVIDED BY THE binaryzebra AND CONTRIBUTORS "AS IS" AND
    ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
    WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
    DISCLAIMED. IN NO EVENT SHALL binaryzebra BE LIABLE FOR ANY
    DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
    (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
    LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
    ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
    (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
    SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
=====================================================================================*/


#ifndef __DAVAENGINE_TCP_CONNECTION_H__
#define __DAVAENGINE_TCP_CONNECTION_H__

#include "Network/Base/Endpoint.h"
#include "Network/NetworkCommon.h"
#include "Network/NetCore.h"

namespace DAVA
{
    
class TCPChannel;
class TCPConnection
{
public:

    static TCPConnection * CreateClient(uint32 service, const Net::Endpoint & endpoint);
    static TCPConnection * CreateServer(uint32 service, const Net::Endpoint & endpoint);
    
    virtual ~TCPConnection();

    bool Connect();
    void Disconnect();
    
protected:
    TCPConnection(Net::eNetworkRole role, uint32 service, const Net::Endpoint & endpoint);
    
    static Net::IChannelListener * Create(uint32 serviceId, void* context);
    static void Delete(Net::IChannelListener* obj, void* context);

    static bool RegisterService(uint32 service);
    
    TCPChannel * CreateChannel();
    void DestroyChannel(TCPChannel *channel);
    
    
protected:
    
    uint32 service;
    Net::eNetworkRole role;
    Net::Endpoint endpoint;
    Net::NetCore::TrackId controllerId;

    static Set<uint32> registeredServices;
    static Mutex serviceMutex;
    
    static List<TCPChannel *> channels;
    static Mutex channelMutex;
};


};

#endif // __DAVAENGINE_TCP_CONNECTION_H__


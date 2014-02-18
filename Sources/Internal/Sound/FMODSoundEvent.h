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



#ifndef __DAVAENGINE_FMOD_SOUND_EVENT_H__
#define __DAVAENGINE_FMOD_SOUND_EVENT_H__

#include "Base/BaseTypes.h"
#include "Base/BaseMath.h"
#include "Base/EventDispatcher.h"
#include "Base/FastNameMap.h"
#include "Sound/SoundEvent.h"

namespace FMOD
{
    class Event;
};

namespace DAVA
{

class FMODSoundEvent : public SoundEvent
{
public:
	virtual ~FMODSoundEvent();

    virtual bool IsActive() const;
    virtual bool Trigger();
	virtual void Stop();
    virtual void Pause();
    
    virtual void SetVolume(float32 volume);
    
    virtual void SetPosition(const Vector3 & position);
    virtual void SetOrientation(const Vector3 & orientation);
    virtual void UpdateInstancesPosition();
    
    virtual void SetParameterValue(const FastName & paramName, float32 value);
    virtual float32 GetParameterValue(const FastName & paramName);
    virtual bool IsParameterExists(const FastName & paramName);

    virtual void GetEventParametersInfo(Vector<SoundEventParameterInfo> & paramsInfo) const;

    virtual String GetEventName() const;

    //FMOD only
    void PerformCallback(FMOD::Event  * event, eSoundEventCallbackType callbackType);
    
protected:
    FMODSoundEvent(const FastName & eventName);
    void ApplyParamsToEvent(FMOD::Event * event);

    List<FMOD::Event *> fmodEventInstances;
    FastName eventName;
    
    Vector3 position;
    Vector3 orientation;
    
    bool is3D;

    FastNameMap<float32> paramsValues;
    
friend class FMODSoundSystem;
};

};

#endif
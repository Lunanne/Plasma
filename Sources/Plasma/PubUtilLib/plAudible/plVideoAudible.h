/*==LICENSE==*

CyanWorlds.com Engine - MMOG client, server and tools
Copyright (C) 2011  Cyan Worlds, Inc.

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.

Additional permissions under GNU GPL version 3 section 7

If you modify this Program, or any covered work, by linking or
combining it with any of RAD Game Tools Bink SDK, Autodesk 3ds Max SDK,
NVIDIA PhysX SDK, Microsoft DirectX SDK, OpenSSL library, Independent
JPEG Group JPEG library, Microsoft Windows Media SDK, or Apple QuickTime SDK
(or a modified version of those libraries),
containing parts covered by the terms of the Bink SDK EULA, 3ds Max EULA,
PhysX SDK EULA, DirectX SDK EULA, OpenSSL and SSLeay licenses, IJG
JPEG Library README, Windows Media SDK EULA, or QuickTime SDK EULA, the
licensors of this Program grant you additional
permission to convey the resulting work. Corresponding Source for a
non-source form of such a combination shall include the source code for
the parts of OpenSSL and IJG JPEG Library used as well as that of the covered
work.

You can contact Cyan Worlds, Inc. by email legal@cyan.com
or by snail mail at:
Cyan Worlds, Inc.
14617 N Newport Hwy
Mead, WA   99021

*==LICENSE==*/

#ifndef plVideoAudible_inc
#define plVideoAudible_inc

#include <memory>

#include "plAudio/plWin32VideoSound.h"
#include "plAudible.h"

class plVideoAudible : public plAudible
{
public:
    plVideoAudible();
    void        SetSound(std::shared_ptr<plWin32VideoSound> sound);
    void        Play(int index = -1);
    bool        IsPlaying(int index = -1);
    void        Stop(int index = -1);
    void        Activate();
    void        DeActivate();
    plSound*    GetSound(int i) const;


    void        SynchedPlay(int index = -1){};
    void        FastForwardPlay(int index = -1){};
    void        FastForwardToggle(int index = -1){};
    void        SetMin(const float m, int index = -1){}; // sets minimum falloff distance
    void        SetMax(const float m, int index = -1){}; // sets maximum falloff distance
    float       GetMin(int index = -1) const{return -1;};
    float       GetMax(int index = -1) const{ return -1; };
    void        SetVelocity(const hsVector3 vel, int index = -1){};
    hsVector3   GetVelocity(int index = -1) const{ return hsVector3(); };
    hsPoint3    GetPosition(int index = -1){ return hsPoint3(); };
    void        SetLooping(bool loop, int index = -1){}; // sets continuous loop or stops looping
    void        SetTime(double t, int index = -1){};
    void        RemoveCallbacks(plSoundMsg* pMsg){};
    void        AddCallbacks(plSoundMsg* pMsg){};
    void        GetStatus(plSoundMsg* pMsg){};
    int         GetNumSounds() const{ return 1; };    
    int         GetSoundIndex(const char *keyname) const{return 0;};
    void        Init(bool isLocal){};
    void        SetVolume(const float volume, int index = -1){};
    void        SetMuted(bool muted, int index = -1){};
    void        ToggleMuted(int index = -1){};
    void        SetTalkIcon(int index, uint32_t str){};
    void        ClearTalkIcon(){};
    void        SetFilename(int index, const char *filename, bool isCompressed){};  // set filename for a streaming sound
    void        SetFadeIn(const int type, const float length, int index = -1){};
    void        SetFadeOut(const int type, const float length, int index = -1){};
    void        SetSceneObject(plKey obj){};
    plKey       GetSceneObject() const {return nullptr;};
    void        SetSceneNode(plKey node){};
    plKey       GetSceneNode() const{return nullptr;};
    plAudible&  SetProperty(int prop, bool on){ return *this;};
    bool        GetProperty(int prop){return false;};
private:
    std::shared_ptr<plWin32VideoSound> fSound;
};

#endif

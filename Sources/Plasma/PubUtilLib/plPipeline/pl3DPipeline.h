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
#ifndef _pl3DPipeline_inc_
#define _pl3DPipeline_inc_

#include <stack>

#include "plPipeline.h"
#include "plPipelineViewSettings.h"


class pl3DPipeline : public plPipeline
{
protected:
    plPipelineViewSettings              fView;
    std::stack<plPipelineViewSettings>  fViewStack;

    hsBitVector                         fDebugFlags;

public:
    CLASSNAME_REGISTER(pl3DPipeline);
    GETINTERFACE_ANY(pl3DPipeline, plPipeline);

    size_t GetViewStackSize() const { return fViewStack.size(); }


    /*** VIRTUAL METHODS ***/
    virtual void SetClear(const hsColorRGBA* col=nullptr, const float* depth=nullptr) {
        fView.SetClear(col, depth);
    }

    virtual hsColorRGBA GetClearColor() const {
        return fView.GetClearColor();
    }

    virtual float GetClearDepth() const {
        return fView.GetClearDepth();
    }

    virtual bool TestVisibleWorld(const hsBounds3Ext& wBnd) {
        return fView.TestVisibleWorld(wBnd);
    }

    virtual bool HarvestVisible(plSpaceTree* space, hsTArray<int16_t>& visList) {
        return fView.HarvestVisible(space, visList);
    }

    virtual bool SubmitOccluders(const hsTArray<const plCullPoly*>& polyList) {
        return fView.SubmitOccluders(polyList);
    }

    virtual void SetDebugFlag(uint32_t flag, bool on) {
        fDebugFlags.SetBit(flag, on);
    }

    virtual bool IsDebugFlagSet(uint32_t flag) const {
        return fDebugFlags.IsBitSet(flag);
    }

    virtual void SetDrawableTypeMask(uint32_t mask) {
        fView.SetDrawableTypeMask(mask);
    }

    virtual uint32_t GetDrawableTypeMask() const {
        return fView.GetDrawableTypeMask();
    }

    virtual void SetSubDrawableTypeMask(uint32_t mask) {
        fView.SetSubDrawableTypeMask(mask);
    }

    virtual uint32_t GetSubDrawableTypeMask() const {
        return fView.GetSubDrawableTypeMask();
    }
};

#endif //_pl3DPipeline_inc_

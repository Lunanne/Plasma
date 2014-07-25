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

#ifndef _plMoviePlayer_inc
#define _plMoviePlayer_inc

#include "HeadSpin.h"
#include "hsColorRGBA.h"
#include "plFileSystem.h"
#include "hsPoint2.h"
#include "plAudio/plWin32VideoSound.h"
#include "plAudible/plVideoAudible.h"
#include "pnSceneObject/plAudioInterface.h"

#include <memory>
#include <vector>
#include <tuple>

#include <opus.h>

namespace mkvparser
{
    class BlockEntry;
    class MkvReader;
    class Segment;
    class Track;
}

typedef std::tuple<std::unique_ptr<uint8_t>, int32_t> blkbuf_t;

class plMoviePlayer
{
protected:
    friend class TrackMgr;

    class plPlate* fPlate;
    class plMipmap* fTexture;

    mkvparser::MkvReader* fReader;
    std::unique_ptr<mkvparser::Segment> fSegment;
    std::unique_ptr<class TrackMgr> fAudioTrack, fVideoTrack; // TODO: vector of tracks?
    std::unique_ptr<class VPX> fVpx;
    int64_t fTimeScale, fStartTime;

    hsPoint2 fPosition, fScale;
    plFileName fMoviePath;

    OpusDecoder* fOpusDecoder;
    std::shared_ptr<plWin32VideoSound> fAudioSound;
    plVideoAudible fAudioPlayer;
    plAudioInterface fAudioInterface;

    int64_t GetMovieTime() const;
    bool IOpenMovie();
    bool IProcessVideoFrame(const std::vector<blkbuf_t>& frames);
    bool IProcessAudioFrame(const std::vector<blkbuf_t>& frames);

public:
    plMoviePlayer();
    ~plMoviePlayer();

    bool Start();
    bool NextFrame();

    plFileName GetFilename() const { return fMoviePath; }
    void SetFilename(const plFileName& filename) { fMoviePath = filename; }

    hsPoint2 GetPosition() const { return fPosition; }
    void SetPosition(const hsPoint2& pos) { fPosition = pos; }
    void SetPosition(float x, float y) { fPosition.Set(x, y); }
   
    hsPoint2 GetScale() const { return fScale; }
    void SetScale(const hsPoint2& scale) { fScale = scale; }
    void SetScale(float x, float y) { fScale.Set(x, y); }
};

#endif // _plMoviePlayer_inc

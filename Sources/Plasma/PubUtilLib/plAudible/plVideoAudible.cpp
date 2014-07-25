#include "hsResMgr.h"
#include "pnKeyedObject/plUoid.h"
#include "plVideoAudible.h"

static int uniqueID = 0;
plVideoAudible::plVideoAudible() : plAudible()
{
    uniqueID++;
    hsgResMgr::ResMgr()->NewKey(plString::Format("videosound#%d", uniqueID), this, plLocation::kGlobalFixedLoc);
}

void plVideoAudible::SetSound(std::shared_ptr<plWin32VideoSound> sound)
{
    fSound = sound;
}

void plVideoAudible::Play(int index)
{
    fSound->Activate();
    fSound->Play();
}

bool plVideoAudible::IsPlaying(int index)
{
    return fSound->IsPlaying();
}

void plVideoAudible::Stop(int index)
{
    fSound->Stop();
}

void plVideoAudible::Activate()
{
    fSound->Activate();
}

void plVideoAudible::DeActivate()
{
    fSound->DeActivate();
}

plSound* plVideoAudible::GetSound(int i) const
{
    return fSound.get();
}
//Script DLL example. Put the 'pluginsdk' directory from the snapshot in the same directory as this file and compile as a DLL.

#include "main.h"

using namespace Script;

extern "C" __declspec(dllexport) void AsyncStart() //async because we are using debug features
{
    Debug::Wait(); //wait until the user paused
    auto cip = Register::GetCIP(); //get CIP
    if (Memory::ReadByte(cip) == 0x60) //check for UPX signature (could be better but it's just an example)
    {
        Cmd("bc"); //clear breakpoints
        Cmd("bphwc"); //clear hardware breakpoints
        auto found = Pattern::FindMem(cip, 0x1000, "83 EC ?? E9"); //find OEP jump pattern
        if (found) //check if the OEP jump was found
        {
            Debug::SetBreakpoint(found + 3); //set a breakpoint on the OEP jump
            Debug::Run(); //let UPX unpack
            Debug::StepIn(); //step to OEP
            Comment::Set(Register::GetCIP(), "OEP"); //comment on OEP
            Gui::Message("Reached OEP. Use Scylla to dump and restore imports!"); //give the user a message
            Cmd("scylla"); //run Scylla
        }
        else
            Gui::Message("Couldn't find OEP jump (83 EC ?? E9)..."); //fail with a message
    }
    else
        Gui::Message("Put EIP on a UPX entry point (0x60) to continue..."); //fail with a message
}

//uncomment this to get called synchronously
//extern "C" __declspec(dllexport) void Start() {}
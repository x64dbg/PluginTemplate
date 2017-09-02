#include "plugin.h"

static duint cbExpr(int argc, duint* argv, void* userdata)
{
    if(argc < 2)
        return 0;
    return argv[0] + argv[1];
}

//Initialize your plugin data here.
bool pluginInit(PLUG_INITSTRUCT* initStruct)
{
    _plugin_registerexprfunction(pluginHandle, PLUGIN_NAME, 2, cbExpr, nullptr);
    return true; //Return false to cancel loading the plugin.
}

//Deinitialize your plugin data here.
void pluginStop()
{
}

//Do GUI/Menu related things here.
void pluginSetup()
{
}

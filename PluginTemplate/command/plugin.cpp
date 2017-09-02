#include "plugin.h"

static bool cbCommand(int argc, char* argv[])
{
    _plugin_logputs(PLUGIN_NAME);
    return true; //Return false to indicate the command failed.
}

//Initialize your plugin data here.
bool pluginInit(PLUG_INITSTRUCT* initStruct)
{
    _plugin_registercommand(pluginHandle, PLUGIN_NAME, cbCommand, false);
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

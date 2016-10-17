# PluginTemplate

Plugin template for x64dbg.

## Installation

Grab the latest [release](https://github.com/x64dbg/PluginTemplate/releases/latest) and copy `PluginTemplate.zip` to `Documents\Visual Studio 2013\Templates\ProjectTemplates\Visual C++ Project\`

## Building

1. Use `File -> Export Template...`.
2. Append the content of `templatefiles.txt` to `<TemplateContent>` in `MyTemplate.vstemplate`.
3. Set `ReplaceParameters="true"` for `plugin.h` in `MyTemplate.vstemplate`.
3. Copy the `pluginsdk\*.lib` inside the ZIP.

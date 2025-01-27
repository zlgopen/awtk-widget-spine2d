﻿import os
import platform
import scripts.app_helper as app

helper = app.Helper(ARGUMENTS)

APP_ROOT = helper.APP_ROOT
APP_CPPPATH=[
  os.path.join(APP_ROOT, "3rd/spine-cpp/spine-cpp/include"),
  os.path.join(APP_ROOT, "3rd/spine-cpp/spine-cpp-lite"),
]

APP_CXXFLAGS=' -DLITEHTML_UTF8=1 '
if platform.system() == 'Windows' and not helper.awtk.TOOLS_NAME == 'mingw':
  APP_CXXFLAGS += ' /std:c++latest '
else:
  APP_CXXFLAGS += ' -std=gnu++17 '
helper.add_cxxflags(APP_CXXFLAGS)
helper.add_cpppath(APP_CPPPATH)
helper.set_dll_def('src/spine2d.def').call(DefaultEnvironment)

SConscriptFiles = ['3rd/SConscript', 'src/SConscript', 'demos/SConscript', 'tests/SConscript']
helper.SConscript(SConscriptFiles)

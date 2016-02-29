:: Copyright 2013 <chaishushan{AT}gmail.com>. All rights reserved.
:: Use of this source code is governed by a BSD-style
:: license that can be found in the LICENSE file.

setlocal

cd %~dp0

:: ----------------------------------------------------------------------------
:: Setup MSVC

:: VS2010
if not "x%VS100COMNTOOLS%" == "x" (
	echo Setup VS2010 Win64 ...
	call "%VS100COMNTOOLS%\..\..\VC\vcvarsall.bat" x86_amd64
	goto build
)

:: VS2012
if not "x%VS110COMNTOOLS%" == "x" (
	echo Setup VS2012 Win64 ...
	call "%VS110COMNTOOLS%\..\..\VC\vcvarsall.bat" x86_amd64
	goto build
)

:: VS2013
if not "x%VS120COMNTOOLS%" == "x" (
	echo Setup VS2013 Win64 ...
	call "%VS120COMNTOOLS%\..\..\VC\vcvarsall.bat" x86_amd64
	goto build
)

:build

:: -----------------------------------------------------------------------------
:: BUG: http://public.kitware.com/Bug/bug_relationship_graph.php?bug_id=14693&graph=relation

mkdir zz_build_win64_release
cd    zz_build_win64_release

cmake ..^
  -G "NMake Makefiles"^
  -DCMAKE_INSTALL_PREFIX=..^
  -DCMAKE_BUILD_TYPE=release^
  ^
  -DCMAKE_C_FLAGS_DEBUG="/MTd /Zi /Od /Ob0 /RTC1"^
  -DCMAKE_CXX_FLAGS_DEBUG="/MTd /Zi /Od /Ob0 /RTC1"^
  -DCMAKE_C_FLAGS_RELEASE="/MT /O2 /Ob2 /DNDEBUG"^
  -DCMAKE_CXX_FLAGS_RELEASE="/MT /O2 /Ob2 /DNDEBUG"^
  ^
  -DCMAKE_MODULE_LINKER_FLAGS="/MANIFEST:NO /machine:x64"^
  -DCMAKE_SHARED_LINKER_FLAGS="/MANIFEST:NO /machine:x64"^
  -DCMAKE_STATIC_LINKER_FLAGS="/MANIFEST:NO /machine:x64"^
  -DCMAKE_EXE_LINKER_FLAGS="/MANIFEST:NO /MACHINE:x64"

nmake install

cd ..

:: -----------------------------------------------------------------------------
:end

